#pragma once
#include <glew.h>

namespace graphics {
	class Buffer {
	private:
		GLuint m_Id;
		GLuint m_ComponentCount;
	public:
		Buffer(float* data, GLsizei count, GLuint componentCount);

		void bind() const;
		void unbind() const;
		inline GLuint getComponentCount() { return m_ComponentCount; }
	};

}
