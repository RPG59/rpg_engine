#pragma once

#include<vec4.hpp>
#include<vec3.hpp>
#include<vec2.hpp>

#include "renderable2d.h"

namespace graphics {
	class Sprite : public Renderable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, glm::vec4 color);
		Sprite(float x, float y, float width, float height, Texture* texture);

	};
}
