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
#pragma comment(lib, "FreeImage.lib")

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
	glm::mat4x4 transform(1.f);
	transform = glm::translate(transform, glm::vec3(-5.f, 0.f, 0));
	transform = glm::rotate(transform, 45.f, glm::vec3(0.f, 0.f, 1.f));
	Group* group = new Group(transform);
	group->add(new Sprite(0, 0, 6, 3, glm::vec4(1, 1, 1, 1)));
	group->add(new Sprite(.5f, .5f, 5.f, 2.f, glm::vec4(1, 0, 1, 1)));

	layer.add(group);

#endif


	while (!window.isClosed())
	{
		window.clear();
		double x, y;
		Window::getMousePosition(x, y);
		shader->SetUniform("light_pos", glm::vec2((float)(x * 32.f / 1024.f - 16.f), (float)(18.f - y * 18.f / 576.f - 9.f)));

		layer.render();
		
		window.update();
	}


	return 0;
}
