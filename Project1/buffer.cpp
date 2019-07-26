#include "buffer.h"

namespace graphics {
	Buffer::Buffer(float* data, GLsizei count, GLuint componentCount)
		:m_ComponentCount(componentCount)
	{
		glGenBuffers(1, &m_Id);
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Buffer::bind() const 
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
	}

	void Buffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
