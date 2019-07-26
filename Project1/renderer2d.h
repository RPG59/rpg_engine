#pragma once
#include <glew.h>

#include "renderable2d.h"
#include "Math.h"

namespace graphics {
	class Renderer2D {
	public:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;
	};
}