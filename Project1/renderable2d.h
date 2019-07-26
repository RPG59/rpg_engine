#pragma once
#include "Math.h"
#include "VertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

namespace graphics {
	class Renderable2D {
	protected:
		float3 m_Position;
		float2 m_Size;
		float4 m_Color;
		

		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;
	public:
		Renderable2D(float3 position, float2 size, float4 color, Shader& shader)
			:m_Position(position), m_Color(color), m_Size(size), m_Shader(shader)
		{
			m_VertexArray = new VertexArray();
			float vertices[] = {
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
			};
			//float vertices[] = {
			//	-.5f, -.5f, .0f,
			//	.5f, -.5f, .0f,
			//	.5f, .5f, .0f,
			//	-.5f, .5f, .0f,
			//};
			float colors[] = {
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			//m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		inline const float3& getPosition() const { return m_Position; }
		inline const float4& getColor() const { return m_Color; }
		inline Shader& getShader() const { return m_Shader; }
	};
}
