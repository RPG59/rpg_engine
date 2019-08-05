#include "window.h"
#include "shader.h"

#include "renderable2d.h"
#include "simpleRenderer2d.h"

#include "static_sprite.h"
#include "sprite.h"
#include "batchRenderer2D.h"
#include "tileLayer.h"

#include "group.h"

#include <time.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")

#define TEST_50K 0

int main()
{
	using namespace graphics;
	std::srand(time(nullptr));

	Window window("TITLE", 1024, 576);
	glClearColor(.0f, .0f, .0f, 1.f);
	Shader* shader = new Shader("../shaders/basic.vert", "../shaders/basic.frag");
	TileLayer layer(shader);

#if TEST_50K
	for (float y = -9.f; y < 9.f; y += .2f)
	{
		for (float x = -16.f; x < 16.f; x += .2f)
		{
			layer.add(new Sprite(x, y, .9f, .9f, float4(rand() % 1000 / 1000.f, 0, 1.f, 1.f)));
		}
	}
#else
	float4x4 rotate;
	rotate.identity();
	rotate.rotate(90.f);
	float4x4 transform;
	transform.translate(float3(15.f, -5.f, .0f));
	Group* group = new Group(rotate);

	group->add(new Sprite(0, 0, 6, 3, float4(1, 1, 1, 1)));
	group->add(new Sprite(.5f, .5f, 5.f, 2.f, float4(1, 0, 1, 1)));

	layer.add(group);

#endif


	while (!window.isClosed())
	{
		window.clear();
		double x, y;
		Window::getMousePosition(x, y);
		shader->SetUniform("light_pos", float2((float)(x * 32.f / 1024.f - 16.f), (float)(y * 18.f / 576.f - 9.f)));

		layer.render();
		
		window.update();
	}


	return 0;
}
