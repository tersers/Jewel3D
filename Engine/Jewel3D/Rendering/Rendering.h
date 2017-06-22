// Copyright (c) 2017 Emilian Cioca
#pragma once
#include "Jewel3D/Reflection/Reflection.h"
#include "Jewel3D/Utilities/Singleton.h"

#include <string>

namespace Jwl
{
	class vec4;

	enum class UniformBufferSlot : unsigned
	{
		Camera = 10,
		Model = 11,
		Engine = 12,
		Time = 13,
		Particle = 14
	};

	enum class TextureFormat
	{
		RGB_8,
		RGB_16,
		RGB_16F,
		RGB_32,
		RGB_32F,
		RGBA_8,
		RGBA_16,
		RGBA_16F,
		RGBA_32,
		RGBA_32F,
		DEPTH_24
	};

	enum class TextureWrapMode
	{
		Clamp,
		ClampWithBorder,
		Repeat,
		RepeatMirrored,
		RepeatMirroredOnce
	};

	struct TextureWrapModes
	{
		TextureWrapModes() = default;
		TextureWrapModes(TextureWrapMode xy);
		TextureWrapModes(TextureWrapMode x, TextureWrapMode y);

		TextureWrapMode x = TextureWrapMode::Clamp;
		TextureWrapMode y = TextureWrapMode::Clamp;
	};

	enum class TextureFilterMode
	{
		Point,
		Linear,
		Bilinear,
		Trilinear
	};

	enum class CullFunc
	{
		// Both back and front faces are rendered.
		None,
		// Clockwise face is culled from rendering. This is the default behaviour.
		Clockwise,
		// Counter-clockwise face is culled from rendering.
		CounterClockwise
	};

	enum class BlendFunc
	{
		// Blending is disabled.
		None,
		// Color is interpolated with the pixels in the renderTarget based on alpha.
		Linear,
		// Color is added onto the pixels in the renderTarget.
		Additive,
		// Color is multiplied with the pixels in the renderTarget.
		Multiplicative,
		// Blending is disabled, but pixels with less than 1.0 alpha are discarded.
		CutOut
	};

	enum class DepthFunc
	{
		None,
		WriteOnly,
		TestOnly,
		Normal
	};

	enum class VSyncMode
	{
		// Frames are sent to display device as soon as they are ready.
		// Screen tearing can occur but input is most responsive.
		Off = 0,
		// Framerate is locked to multiples of the display's refresh rate to eliminate tearing.
		// Can introduce input lag or stuttering.
		On = 1,
		// Vsync is on when the framerate exceeds the display's refresh rate to eliminate tearing.
		// When the framerate drops, Vsync turns off to eliminate stuttering and input lag.
		Adaptive = -1
	};

	int ResolveFilterMagMode(TextureFilterMode filter);
	int ResolveFilterMinMode(TextureFilterMode filter);
	bool ResolveMipMapping(TextureFilterMode filter);
	int ResolveWrapMode(TextureWrapMode wrapMode);
	unsigned ResolveFormat(TextureFormat format);

	TextureFilterMode StringToFilterMode(const std::string&);
	TextureWrapMode StringToWrapMode(const std::string&);

	unsigned CountMipLevels(unsigned width, unsigned height, TextureFilterMode filter);
	unsigned CountChannels(TextureFormat format);

	void ClearBackBuffer();
	void ClearBackBufferDepth();
	void ClearBackBufferColor();

	void SetActiveTextureUnit(unsigned unit);
	void SetClearColor(const vec4& color);
	void SetClearColor(float r, float g, float b, float a);
	void SetWireframe(bool enabled);
	void SetCullFunc(CullFunc func);
	void SetBlendFunc(BlendFunc func);
	void SetDepthFunc(DepthFunc func);
	void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height);
	bool SetVSync(VSyncMode mode);

	static class GPUInfo : public Singleton<class GPUInfo>
	{
	public:
		//- Queries the limits from the device and provides them to the application.
		//- Called by Application on window creation.
		void ScanDevice();

		unsigned GetMaxTextureSlots() const;
		unsigned GetMaxUniformBufferSlots() const;
		unsigned GetMaxRenderTargetAttachments() const;
		unsigned GetMaxDrawBuffers() const;

	private:
		unsigned MaxTextureSlots = 0;
		unsigned MaxUniformBufferSlots = 0;
		unsigned MaxRenderTargetAttachments = 0;
		unsigned MaxDrawBuffers = 0;
	} &GPUInfo = Singleton<class GPUInfo>::instanceRef;
}

REFLECT(Jwl::TextureFormat)<>,
	VALUES <
		REF_VALUE(RGB_8),
		REF_VALUE(RGB_16),
		REF_VALUE(RGB_16F),
		REF_VALUE(RGB_32),
		REF_VALUE(RGB_32F),
		REF_VALUE(RGBA_8),
		REF_VALUE(RGBA_16),
		REF_VALUE(RGBA_16F),
		REF_VALUE(RGBA_32),
		REF_VALUE(RGBA_32F),
		REF_VALUE(DEPTH_24)
	>
REF_END;

REFLECT(Jwl::TextureWrapMode)<>,
	VALUES <
		REF_VALUE(Clamp),
		REF_VALUE(ClampWithBorder),
		REF_VALUE(Repeat),
		REF_VALUE(RepeatMirrored),
		REF_VALUE(RepeatMirroredOnce)
	>
REF_END;

REFLECT(Jwl::TextureFilterMode)<>,
	VALUES <
		REF_VALUE(Point),
		REF_VALUE(Linear),
		REF_VALUE(Bilinear),
		REF_VALUE(Trilinear)
	>
REF_END;

REFLECT(Jwl::CullFunc)<>,
	VALUES <
		REF_VALUE(None),
		REF_VALUE(Clockwise),
		REF_VALUE(CounterClockwise)
	>
REF_END;

REFLECT(Jwl::BlendFunc)<>,
	VALUES <
		REF_VALUE(None),
		REF_VALUE(Linear),
		REF_VALUE(Additive),
		REF_VALUE(Multiplicative),
		REF_VALUE(CutOut)
	>
REF_END;

REFLECT(Jwl::DepthFunc)<>,
	VALUES <
		REF_VALUE(None),
		REF_VALUE(WriteOnly),
		REF_VALUE(TestOnly),
		REF_VALUE(Normal)
	>
REF_END;
