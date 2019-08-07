#pragma once

#include <string>
#include <GLEW/glew.h>
#include <freeImage/FreeImage.h>

#include "imageLoader.h"

namespace graphics {
	class Texture
	{
	private:
		std::string m_Path;
		GLuint m_TID;
		GLsizei m_Width, m_Height;
	public:
		Texture(std::string& path);
		~Texture();
		void bind() const;
		void unbind() const;

		inline const uint32_t getWidth() const { return m_Width; }
		inline const uint32_t getHeight() const { return m_Height; }
	private:
		GLuint load();
	};
}
