// Copyright (c) 2017 Emilian Cioca
#pragma once
#include "Jewel3D/Reflection/Reflection.h"

namespace Jwl
{
	class vec3;
	class mat3;

	class quat
	{
	public:
		quat() = default;
		quat(float X, float Y, float Z, float W);
		quat(const vec3& right, const vec3& up, const vec3& forward);
		quat(const mat3& rotation);
		
		quat operator*(const quat&) const;
		vec3 operator*(const vec3&) const;
		quat& operator*=(const quat&);

		float operator[](unsigned index) const;
		float& operator[](unsigned index);

		void SetIdentity();
		void Conjugate();
		quat GetConjugate() const;
		void Normalize();
		quat GetNormalized() const;

		vec3 GetRight() const;
		vec3 GetUp() const;
		vec3 GetForward() const;

		void Rotate(const vec3& axis, float degrees);
		void Rotate(float X, float Y, float Z, float degrees);
		void RotateX(float degrees);
		void RotateY(float degrees);
		void RotateZ(float degrees);
		
		static const quat Identity;

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 1.0f;
	};

	float Dot(const quat& p0, const quat& p1);
	quat Slerp(const quat& p0, const quat& p1, float percent);
}

REFLECT(Jwl::quat)<>,
	MEMBERS <
		REF_MEMBER(x)<>,
		REF_MEMBER(y)<>,
		REF_MEMBER(z)<>,
		REF_MEMBER(w)<>
	>
REF_END;
