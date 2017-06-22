// Copyright (c) 2017 Emilian Cioca
#pragma once
#include "Jewel3D/Reflection/Reflection.h"

namespace Jwl
{
	class vec3;

	void SeedRandomNumberGenerator();
	void SeedRandomNumberGenerator(unsigned seed);

	float RandomRange(float min, float max);
	int RandomRange(int min, int max);

	// Returns a random unit-length vector.
	vec3 RandomDirection();
	// Returns a random color with [0, 1] RGB values.
	vec3 RandomColor();

	class Range
	{
	public:
		Range() = default;
		Range(float min, float max);

		// Potential range is 'value' +- half the 'deviation'.
		static Range Deviation(float value, float deviation);

		float Random() const;
		void Set(float min, float max);

		bool Contains(float value) const;

		float min = 0.0f;
		float max = 1.0f;
	};
}

REFLECT(Jwl::RandomRange)<>,
	MEMBERS <
		REF_MEMBER(value)<>,
		REF_MEMBER(deviation)<>
	>
REF_END;
