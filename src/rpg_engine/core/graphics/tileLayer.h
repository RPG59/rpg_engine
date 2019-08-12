#pragma once

#include <ext/matrix_clip_space.hpp>

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
