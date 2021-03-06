#pragma once
#include "Jewel3D/Resource/Encoder.h"

#include <string>

class TextureEncoder : public Jwl::Encoder
{
public:
	TextureEncoder();

	virtual Jwl::ConfigTable GetDefault() const override;

	virtual bool Validate(const Jwl::ConfigTable& metadata, unsigned loadedVersion) const override;

	virtual bool Convert(const std::string& source, const std::string& destination, const Jwl::ConfigTable& metadata) const override;
};
