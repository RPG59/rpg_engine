#include "tileLayer.h"


namespace graphics {
	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader, glm::ortho(-16.f, 16.f, -9.f, 9.f, -1.f, 1.f))
	{
	}

	TileLayer::~TileLayer()
	{
	}
}