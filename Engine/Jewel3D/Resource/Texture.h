// Copyright (c) 2017 Emilian Cioca
#pragma once
#include "Resource.h"
#include "Jewel3D/Reflection/Reflection.h"
#include "Jewel3D/Rendering/Rendering.h"

#include <string>
#include <vector>

namespace Jwl
{
	class Texture : public Resource<Texture>
	{
		REFLECT_PRIVATE;
	public:
		Texture() = default;
		~Texture();

		// Creates an empty texture.
		void CreateTexture(
			unsigned width, unsigned height,
			TextureFormat format,
			TextureFilterMode filter = TextureFilterMode::Point,
			TextureWrapModes wrapModes = TextureWrapMode::Clamp,
			float anisotropicLevel = 1.0f,
			unsigned numSamples = 1);

		// Loads packed *.texture resources, as well as *.png, *.jpg, *.tga, *.bmp.
		bool Load(std::string filePath);
		void Unload();

		void Bind(unsigned slot);
		void UnBind(unsigned slot);

		void SetFilterMode(TextureFilterMode filter);
		void SetWrapModes(TextureWrapModes wrapModes);
		// Must be in the range of [1, 16].
		void SetAnisotropicLevel(float level);

		unsigned GetHandle() const;
		unsigned GetNumSamples() const;
		unsigned GetBindingTarget() const;
		unsigned GetWidth() const;
		unsigned GetHeight() const;
		TextureFormat GetTextureFormat() const;
		TextureFilterMode GetFilterMode() const;
		TextureWrapModes GetWrapModes() const;
		float GetAnisotropicLevel() const;

		bool IsCubeMap() const;

		void RegenerateMipmaps();

	private:
		unsigned hTex		= 0;
		unsigned numSamples = 1;
		unsigned target		= 0;
		int width			= 0;
		int height			= 0;
		TextureFormat format = TextureFormat::RGB_8;
		TextureFilterMode filter = TextureFilterMode::Point;
		TextureWrapModes wrapModes = TextureWrapMode::Clamp;
		float anisotropicLevel = 1.0f;
	};

	//- Used to associate a Texture with a particular binding point.
	struct TextureSlot
	{
		TextureSlot() = default;
		TextureSlot(Texture::Ptr tex, unsigned unit = 0);

		void Bind() const;
		void UnBind() const;

		Texture::Ptr tex;
		//- Unit the texture should be bound to when rendering.
		unsigned unit = 0;
	};
	
	//- A group of textures that are bound and unbound together.
	class TextureList
	{
		REFLECT_PRIVATE;
	public:
		void Bind() const;
		void UnBind() const;

		void Add(Texture::Ptr tex, unsigned unit = 0);
		void Remove(unsigned unit);
		//- Removes all TextureSlots.
		void Clear();

		//- Returns the buffer bound at the specified unit.
		Texture::Ptr& operator[](unsigned unit);

		const auto& GetAll() const { return textureSlots; }

	private:
		std::vector<TextureSlot> textureSlots;
	};

	//- Loads raw image data from the disk.
	//- Can be used when an image is needed for non-rendering use.
	class Image
	{
	public:
		Image() = default;
		Image(int width, int height, TextureFormat format, unsigned char* data);
		~Image();

		// Loads *.png, *.jpg, *.tga, and *.bmp.
		static Image Load(const std::string& file, bool flipY = true);

		const int width = 0;
		const int height = 0;
		const TextureFormat format = TextureFormat::RGB_8;
		const unsigned char* data = nullptr;
	};
}

REFLECT_SHAREABLE(Jwl::Texture)
REFLECT(Jwl::Texture) < Resource >,
	MEMBERS<
		REF_MEMBER(numSamples)< ReadOnly >,
		REF_MEMBER(numChannels)< ReadOnly >,
		REF_MEMBER(width)< ReadOnly >,
		REF_MEMBER(height)< ReadOnly >,
		REF_MEMBER(format)< ReadOnly >
	>
REF_END;

REFLECT(Jwl::TextureSlot)<>,
	MEMBERS<
		REF_MEMBER(tex)<>,
		REF_MEMBER(unit)<>
	>
REF_END;

REFLECT_BASIC(std::vector<Jwl::TextureSlot>)
REFLECT(Jwl::TextureList)<>,
	MEMBERS<
		REF_MEMBER(textureSlots)<>
	>
REF_END;
