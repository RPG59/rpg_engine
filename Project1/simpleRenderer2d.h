#pragma once

#include <deque>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "renderer2d.h"
#include "static_sprite.h"
#include "renderable2d.h"

namespace graphics {
	class SimpleRenderer2D : public Renderer2D {
	private:
		std::deque<const StaticSprite*> m_RanderQueue;
	public:
		void submit(const Renderable2D* renderable) override;
		void flush() override;
	};
}
