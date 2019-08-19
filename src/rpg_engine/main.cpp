//#include "core/window.h"
//#include "core/graphics/shader.h"
//
//#include "core/graphics/renderable2d.h"
//
//#include "core/graphics/static_sprite.h"
//#include "core/graphics/sprite.h"
//#include "core/graphics/batchRenderer2D.h"
//#include "core/graphics/tileLayer.h"
//
//#include "core/graphics/texture.h"
//
//#include "core/graphics/group.h"
//
//#include <time.h>
//
//
//
//
////#pragma comment(lib, "opengl32.lib")
////#pragma comment(lib, "glew32s.lib")
////#pragma comment(lib, "glfw3.lib")
////#pragma comment(lib, "FreeImage.lib")
//
//#define TEST_50K 0
//
//int main()
//{
//	using namespace graphics;
//	//std::srand(time(nullptr));
//
//	Window window("TITLE", 1024, 576);
//	glClearColor(.0f, .0f, .0f, 1.f);
//	Shader* shader = new Shader("../shaders/basic.vert", "../shaders/basic.frag");
//	TileLayer layer(shader);
//
//	std::string path1 = "../test.png";
//	std::string path2 = "../test1.png";
//	Texture texture1(path1);
//	Texture texture2(path2);
//
//#if TEST_50K
//	for (float y = -9.f; y < 9.f; y += 1.f)
//	{
//		for (float x = -16.f; x < 16.f; x += 1.f)
//		{
//			//layer.add(new Sprite(x, y, .9f, .9f, glm::vec4(rand() % 1000 / 1000.f, 0, 1.f, 1.f)));
//			layer.add(new Sprite(x, y, 1, 1, rand() % 2 ? &texture1 : &texture2));
//		}
//	}
//
//	layer.add(new Sprite(-16, -9, 16, 9, glm::vec4(.5f, .3f, .1f, 1.f)));
//#else
//
//	//glm::mat4x4 transform(1.f);
//	//transform = glm::translate(transform, glm::vec3(-5.f, 0.f, 0));
//	//transform = glm::rotate(transform, 45.f, glm::vec3(0.f, 0.f, 1.f));
//	//Group* group = new Group(transform);
//	//group->add(new Sprite(0, 0, 6, 3, glm::vec4(1, 1, 1, 1)));
//	//group->add(new Sprite(.5f, .5f, 5.f, 2.f, glm::vec4(1, 0, 1, 1)));
//
//	//layer.add(group);
//	float x_pos = -5;
//	float y_pos = -5;
//
//
//
//#endif
//
//	int32_t texIDs[] =
//	{
//		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//	};
//
//	shader->Enable();
//	shader->SetUniform("textures", 10, texIDs);
//
//
//	while (!window.isClosed())
//	{
//		Sprite* sprite = new Sprite(x_pos, y_pos, 5, 5, glm::vec4(.2f, .8f, .1, 1));
//		layer.add(sprite);
//		window.clear();
//		double x, y;
//		Window::getMousePosition(x, y);
//		if (x < window.getWidth() / 2.)
//			x_pos -= .001;
//		else
//			x_pos += .001;
//
//		if (y > window.getHeight() / 2.)
//			y_pos -= .001;
//		else
//			y_pos += .001;
//
//		shader->SetUniform("light_pos", glm::vec2((float)(x * 32.f / window.getWidth() - 16.f), (float)(18.f - y * 18.f / window.getHeight() - 9.f)));
//		layer.render();
//
//		window.update();
//	}
//
//
//	return 0;
//}
//
