#pragma once

#include <glm/ext/matrix_clip_space.hpp>

#include "layer.h"
#include "batchRenderer2D.h"

namespace graphics {
	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
		 
	};
}
