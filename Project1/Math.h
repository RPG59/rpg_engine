#pragma once
#include <cmath>
#include <Windows.h>

#define M_PI           3.14159265358979323846  /* pi */
struct float2 {
	float x, y;
	float2() {
		x = 0.0f;
		y = 0.0f;
	}
	float2(float x, float y) {
		this->x = x;
		this->y = y;
	}
};
struct float3 {
	float x, y, z;
	float3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	float3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct float4 {
	float x;
	float y;
	float z;
	float w;
	float4() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}
	float4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

struct float4x4 {
	float elements[4 * 4];
	void identity() {
		for (int i = 0; i < 4 * 4; ++i) {
			elements[i] = 0.0f;
		}
		elements[0 + 0 * 4] = 1.0f;
		elements[1 + 1 * 4] = 1.0f;
		elements[2 + 2 * 4] = 1.0f;
		elements[3 + 3 * 4] = 1.0f;
	}

	float4x4 orthographic(float left, float right, float top, float bottom, float nearPlan, float farPlan) {
		identity();

		elements[0 + 0 * 4] = 2.0f / (right - left);
		elements[1 + 1 * 4] = 2.0f / (top - bottom);
		elements[2 + 2 * 4] = 2.0f / (nearPlan - farPlan);

		elements[0 + 3 * 4] = (left + right) / (left - right);
		elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		elements[2 + 3 * 4] = (farPlan + nearPlan) / (farPlan - nearPlan);
	}

	static float4x4 createOrthographic(float left, float right, float top, float bottom, float nearPlan, float farPlan) {
		float4x4 matrix;
		matrix.identity();

		matrix.elements[0 + 0 * 4] = 2.0f / (right - left);
		matrix.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		matrix.elements[2 + 2 * 4] = 2.0f / (nearPlan - farPlan);

		matrix.elements[0 + 3 * 4] = (left + right) / (left - right);
		matrix.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		matrix.elements[2 + 3 * 4] = (farPlan + nearPlan) / (farPlan - nearPlan);

		return matrix;
	}

	void translate(float3 vector) {
		identity();

		elements[0 + 3 * 4] = vector.x;
		elements[1 + 3 * 4] = vector.y;
		elements[2 + 3 * 4] = vector.z;
	}

	void rotate(float angle) {
		identity();

		float r = float(M_PI * angle / 180);
		float cos = std::cos(r);
		float sin = std::sin(r);

		elements[0 + 0 * 4] = cos;
		elements[1 + 0 * 4] = sin;

		elements[0 + 1 * 4] = cos;
		elements[1 + 1 * 4] = sin;
	}

	void multiply(float4x4 & matrix) {
		float result[4 * 4];
		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				float sum = 0.0f;
				for (int e = 0; e < 4; ++e) {
					sum += elements[x + e * 4] * matrix.elements[e + y * 4];
				}
				result[x + y * 4] = sum;
			}
		}
		CopyMemory(elements, result, sizeof(float) * 4 * 4);
	}

	static float3 createMultiply(const float4x4& mat, const float3& vec)
	{
		float3 res;
		res.x = mat.elements[0 + 0] * vec.x + mat.elements[0 + 1] * vec.y + mat.elements[0 + 2] * vec.z + mat.elements[0 + 3];
		res.y = mat.elements[4 + 0] * vec.x + mat.elements[4 + 1] * vec.y + mat.elements[4 + 2] * vec.z + mat.elements[4 + 3];
		res.z = mat.elements[8 + 0] * vec.x + mat.elements[8 + 1] * vec.y + mat.elements[8 + 2] * vec.z + mat.elements[8 + 3];

		return res;
	}
};
