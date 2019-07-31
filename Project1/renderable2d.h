#pragma once
#include "Math.h"
#include "VertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

namespace graphics {

	struct VertexData
	{
		float3 vertices;
		uint32_t color;
	};

	class Renderable2D {
	protected:
		float3 m_Position;
		float2 m_Size;
		float4 m_Color;
	public:
		Renderable2D(float3 position, float2 size, float4 color)
			:m_Position(position), m_Color(color), m_Size(size)
		{

		}

		virtual ~Renderable2D()
		{

		}

		inline const float3& getPosition() const { return m_Position; }
		inline const float2& getSize() const { return m_Size; }
		inline const float4& getColor() const { return m_Color; }
	};
}
