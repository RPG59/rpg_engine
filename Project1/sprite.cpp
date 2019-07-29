#include "sprite.h"

namespace graphics {
	Sprite::Sprite(float x, float y, float width, float height, float4 color)
		: Renderable2D(float3(x, y, 0), float2(width, height), color)
	{

	}
}