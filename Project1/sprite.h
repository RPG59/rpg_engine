#pragma once

#include<glm/vec4.hpp>
#include<glm/vec3.hpp>
#include<glm/vec2.hpp>

#include "renderable2d.h"

namespace graphics {
	class Sprite : public Renderable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, glm::vec4 color);

	};
}
