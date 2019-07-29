#include "batchRenderer2D.h"

namespace graphics {
	BatchRenderer2D::BatchRenderer2D()
	{
		this->init();
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
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FLOAT, RENDERER_VERTEX_SIZE, 0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FLOAT, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * GL_FLOAT));
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

	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{
	}

	void BatchRenderer2D::flush()
	{

	}

}

