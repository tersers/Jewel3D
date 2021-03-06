// Copyright (c) 2017 Emilian Cioca
#include "MeshEncoder.h"

#include "Jewel3D/Math/Vector.h"
#include "Jewel3D/Resource/Encoder.h"

#include <fstream>
#include <string>
#include <vector>

#define CURRENT_VERSION 1
#define CHAR_BUFFER_SIZE 128

std::unique_ptr<Jwl::Encoder> GetEncoder()
{
	return std::make_unique<MeshEncoder>();
}

//- Indices for three points; one triangle. v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
struct MeshFace
{
	MeshFace() = default;
	MeshFace(unsigned v1, unsigned v2, unsigned v3, unsigned t1, unsigned t2, unsigned t3, unsigned n1, unsigned n2, unsigned n3)
	{
		vertices[0] = v1; vertices[1] = v2; vertices[2] = v3;
		textures[0] = t1; textures[1] = t2; textures[2] = t3;
		normals[0] = n1; normals[1] = n2; normals[2] = n3;
	}

	unsigned vertices[3];
	unsigned textures[3];
	unsigned normals[3];
};

MeshEncoder::MeshEncoder()
	: Encoder(CURRENT_VERSION)
{
}

Jwl::ConfigTable MeshEncoder::GetDefault() const
{
	Jwl::ConfigTable defaultConfig;

	defaultConfig.SetValue("version", CURRENT_VERSION);
	defaultConfig.SetValue("scale", 1);
	defaultConfig.SetValue("uvs", true);
	defaultConfig.SetValue("normals", true);

	return defaultConfig;
}

bool MeshEncoder::Validate(const Jwl::ConfigTable& metadata, unsigned loadedVersion) const
{
	switch (loadedVersion)
	{
	case 1:
		if (!metadata.HasSetting("uvs"))
		{
			Jwl::Error("Missing \"uvs\" value.");
			return false;
		}

		if (!metadata.HasSetting("normals"))
		{
			Jwl::Error("Missing \"normals\" value.");
			return false;
		}

		if (!metadata.HasSetting("scale"))
		{
			Jwl::Error("Missing \"scale\" value.");
			return false;
		}

		if (metadata.GetSize() != 4)
		{
			Jwl::Error("Incorrect number of value entries.");
			return false;
		}
	}

	return true;
}

bool MeshEncoder::Convert(const std::string& source, const std::string& destination, const Jwl::ConfigTable& metadata) const
{
	const std::string outputFile = destination + Jwl::ExtractFilename(source) + ".model";
	const bool packUvs = metadata.GetBool("uvs");
	const bool packNormals = metadata.GetBool("normals");
	const float scale = metadata.GetFloat("scale");

	// Load ASCII file.
	std::ifstream input;
	input.open(source);
	if (!input)
	{
		Jwl::Error("Input file could not be opened or processed.");
		return false;
	}

	char inputString[CHAR_BUFFER_SIZE] = { '\0' };
	bool hasUvs = false;
	bool hasNormals = false;

	// Unique data.
	std::vector<Jwl::vec3> vertexData;
	std::vector<Jwl::vec2> textureData;
	std::vector<Jwl::vec3> normalData;
	// Indexing data.
	std::vector<MeshFace> faceData;

	while (!input.eof())
	{
		input.getline(inputString, CHAR_BUFFER_SIZE);

		if (std::strchr(inputString, '#') != nullptr)
			continue;

		if (std::strstr(inputString, "vt") == inputString)
		{
			hasUvs = true;

			// Load texture coordinates.
			Jwl::vec2 temp;
			std::sscanf(inputString, "vt %f %f", &temp.x, &temp.y);
			textureData.push_back(temp);
		}
		else if (std::strstr(inputString, "vn") == inputString)
		{
			hasNormals = true;

			// Load normals.
			Jwl::vec3 temp;
			std::sscanf(inputString, "vn %f %f %f", &temp.x, &temp.y, &temp.z);
			normalData.push_back(temp);
		}
		else if (std::strchr(inputString, 'v') == inputString)
		{
			// Load vertices.
			Jwl::vec3 temp;
			std::sscanf(inputString, "v %f %f %f", &temp.x, &temp.y, &temp.z);
			vertexData.push_back(temp * scale);
		}
		else if (std::strchr(inputString, 'f') == inputString)
		{
			// load face indices.
			MeshFace temp;

			// Each permutation of data formats.
			if (hasUvs && hasNormals)
			{
				std::sscanf(inputString, "f %u/%u/%u %u/%u/%u %u/%u/%u",
					&temp.vertices[0], &temp.textures[0], &temp.normals[0],
					&temp.vertices[1], &temp.textures[1], &temp.normals[1],
					&temp.vertices[2], &temp.textures[2], &temp.normals[2]);
			}
			else if (hasUvs && !hasNormals)
			{
				std::sscanf(inputString, "f %u/%u %u/%u %u/%u",
					&temp.vertices[0], &temp.textures[0],
					&temp.vertices[1], &temp.textures[1],
					&temp.vertices[2], &temp.textures[2]);
			}
			else if (!hasUvs && hasNormals)
			{
				std::sscanf(inputString, "f %u//%u %u//%u %u//%u",
					&temp.vertices[0], &temp.normals[0],
					&temp.vertices[1], &temp.normals[1],
					&temp.vertices[2], &temp.normals[2]);
			}
			else
			{
				// Only vertices.
				std::sscanf(inputString, "f %u %u %u",
					&temp.vertices[0], &temp.vertices[1], &temp.vertices[2]);
			}

			faceData.push_back(temp);
		}
	}

	input.close();

	bool useUvs = packUvs && hasUvs;
	bool useNormals = packNormals && hasNormals;

	const unsigned numVertices = faceData.size() * 3;
	unsigned bufferSize = numVertices * 3;
	if (useUvs) bufferSize += numVertices * 2;
	if (useNormals) bufferSize += numVertices * 3;

	float* data = static_cast<float*>(malloc(sizeof(float) * bufferSize));
	defer{ free(data); };

	// Unpack the data.
	unsigned pen = 0;
	for (unsigned i = 0; i < faceData.size(); i++)
	{
		for (unsigned j = 0; j < 3; j++)
		{
			data[pen++] = vertexData[faceData[i].vertices[j] - 1].x;
			data[pen++] = vertexData[faceData[i].vertices[j] - 1].y;
			data[pen++] = vertexData[faceData[i].vertices[j] - 1].z;

			if (useUvs)
			{
				data[pen++] = textureData[faceData[i].textures[j] - 1].x;
				data[pen++] = textureData[faceData[i].textures[j] - 1].y;
			}

			if (useNormals)
			{
				data[pen++] = normalData[faceData[i].normals[j] - 1].x;
				data[pen++] = normalData[faceData[i].normals[j] - 1].y;
				data[pen++] = normalData[faceData[i].normals[j] - 1].z;
			}
		}
	}

	// Save file.
	FILE* modelFile = fopen(outputFile.c_str(), "wb");
	if (modelFile == nullptr)
	{
		Jwl::Error("Output file could not be created.");
		return false;
	}

	// Write header.
	unsigned numFaces = faceData.size();
	fwrite(&numFaces, sizeof(int), 1, modelFile);
	fwrite(&useUvs, sizeof(bool), 1, modelFile);
	fwrite(&useNormals, sizeof(bool), 1, modelFile);

	// Write Data.
	fwrite(data, sizeof(float), bufferSize, modelFile);
	auto result = fclose(modelFile);

	// Report results.
	if (result != 0)
	{
		Jwl::Error("Failed to generate mesh Binary\nOutput file could not be saved.");
		return false;
	}
	else
	{
		if (packUvs && !hasUvs)
		{
			Jwl::Warning("Output of uvs was enabled but no uvs were found in the mesh.");
		}
		
		if (packNormals && !hasNormals)
		{
			Jwl::Warning("Output of normals was enabled but no normals were found in the mesh.");
		}

		return true;
	}
}
