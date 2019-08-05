#include "batchRenderer2D.h"

namespace graphics {
	BatchRenderer2D::BatchRenderer2D()
	{
		init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		delete m_IBO;
		glDeleteBuffers(1, &m_VBO);
	}

	void BatchRenderer2D::init()
	{
		glGenBuffers(1, &m_VBO);
		glGenVertexArrays(1, &m_VAO);

		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);



		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, 0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const void*)offsetof(VertexData, VertexData::color));
		glBindBuffer(GL_ARRAY_BUFFER, NULL);

		GLushort indices[RENDERER_INDICES_SIZE];
		int offset = 0;

		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
		glBindVertexArray(NULL);     
	}

	void BatchRenderer2D::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		m_Buffer = reinterpret_cast<VertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	}

	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{
		const float3& position = renderable->getPosition();
		const float4& color = renderable->getColor();
		const float2& size = renderable->getSize();

		uint8_t r = color.x * 255.f;
		uint8_t g = color.y * 255.f;
		uint8_t b = color.z * 255.f;
		uint8_t a = color.w * 255.f;

		const uint32_t packedColor = a << 24 | b << 16 | g << 8 | r;

		m_Buffer->vertices = float4x4::createMultiply(*m_TransformationBack, position);
		m_Buffer->color = packedColor;
		m_Buffer++;

		m_Buffer->vertices = float4x4::createMultiply(*m_TransformationBack, float3(position.x, position.y + size.y, position.z));
		m_Buffer->color = packedColor;
		m_Buffer++;

		m_Buffer->vertices = float4x4::createMultiply(*m_TransformationBack, float3(position.x + size.x, position.y + size.y, position.z));
		m_Buffer->color = packedColor;
		m_Buffer++;

		m_Buffer->vertices = float4x4::createMultiply(*m_TransformationBack, float3(position.x + size.x, position.y, position.z));
		m_Buffer->color = packedColor;
		m_Buffer++;

		m_IndexCount += 6;
	}

	void BatchRenderer2D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
	}

	void BatchRenderer2D::flush()
	{
		glBindVertexArray(m_VAO);
		m_IBO->bind();

		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

		m_IBO->unbind();
		glBindVertexArray(NULL);

		m_IndexCount = 0;
	}

}






