#pragma once

#include <vector>

#include <GLEW/glew.h>
#include "buffer.h"

namespace graphics {
	class VertexArray {
	private:
		GLuint m_Id;
		std::vector<Buffer*> m_Buffers;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;
	};
}
