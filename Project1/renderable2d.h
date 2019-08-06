#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include "VertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "renderer2d.h"

namespace graphics {

	struct VertexData
	{
		glm::vec3 vertices;
		uint32_t color;
	};

	class Renderable2D {
	protected:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;
	protected:
		Renderable2D() {}
	public:
		Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
			:m_Position(position), m_Color(color), m_Size(size)
		{

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
	};
}
