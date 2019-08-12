#pragma once

#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>

#include "VertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "renderer2d.h"
#include "texture.h"

namespace graphics {

	struct VertexData
	{
		glm::vec3 vertices;
		glm::vec2 texCoord;
		uint32_t color;
		float tid;
	};

	class Renderable2D {
	protected:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;
		std::vector<glm::vec2> m_TextureCoord;
		Texture* m_Texture;
	protected:
		Renderable2D()
		{
			setDefaultTextureCoord();
		}
	public:
		Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
			:m_Position(position), m_Color(color), m_Size(size)
		{
			setDefaultTextureCoord();
		}

		virtual ~Renderable2D()
		{

		}

		virtual void submit(Renderer2D* renderer)
		{
			renderer->submit(this);
		}

		inline const glm::vec3& getPosition() const { return m_Position; }
		inline const glm::vec2& getSize() const { return m_Size; }
		inline const glm::vec4& getColor() const { return m_Color; }
		inline const std::vector<glm::vec2>& getTextureCoord() const { return m_TextureCoord; }
		inline const GLuint getTID() const { return m_Texture == nullptr ? 0 : m_Texture->getID(); }

	private:
		void setDefaultTextureCoord()
		{
			m_TextureCoord.push_back(glm::vec2(0, 0));
			m_TextureCoord.push_back(glm::vec2(0, 1));
			m_TextureCoord.push_back(glm::vec2(1, 1));
			m_TextureCoord.push_back(glm::vec2(1, 0));
		}
	};
}
