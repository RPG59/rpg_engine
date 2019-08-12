#pragma once

#include <cstddef>	
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>

#include "renderable2d.h"
#include "renderer2d.h"
#include "indexBuffer.h"

namespace graphics {

#define RENDERER_MAX_SPRITES 60000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE  * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_TEXTURE_COORD_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3

	class BatchRenderer2D : public Renderer2D {
	private:
		GLuint m_VAO = NULL;
		GLuint m_VBO = NULL;
		VertexData* m_Buffer = nullptr;
		IndexBuffer* m_IBO = nullptr;
		GLsizei m_IndexCount = NULL;

		std::vector<GLuint> m_TextureSlots;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		void begin()override;
		void submit(const Renderable2D* renderable) override;
		void end() override;
		void flush() override;
	private:
		void init();
	};

}
