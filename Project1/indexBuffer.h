#pragma once
#include <GLEW/glew.h>

namespace graphics {
	class IndexBuffer
	{
	private:
		GLuint m_Id;
		GLuint m_Count;
	public:
		IndexBuffer(GLushort* data, GLsizei count);
		~IndexBuffer();

		void bind() const;
		void unbind() const;
		inline GLsizei getCount() const { return m_Count; }
	};

}
