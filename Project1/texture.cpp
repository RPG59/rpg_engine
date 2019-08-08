#include "texture.h"

namespace graphics {
	Texture::Texture(std::string& path)
		: m_Path(path)
	{
		m_TID = load();
	}

	Texture::~Texture()
	{
		//FreeImage_Unload()
	}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_TID);
	}

	void Texture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	GLuint Texture::load()
	{
		BYTE* pixels = loadImage(m_Path.c_str(), &m_Width, &m_Height);
		GLuint result;

		glGenTextures(1, &result);
		glBindTexture(GL_TEXTURE_2D, result);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
		glBindTexture(GL_TEXTURE_2D, NULL);
		//delete

		return result;

	}
}
