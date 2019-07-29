#include "window.h"
#include "shader.h"

#include "renderable2d.h"
#include "simpleRenderer2d.h"

#include "static_sprite.h"
#include "sprite.h"
#include "batchRenderer2D.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")

#define BATCH_RENDNRER 1

int main()
{
	using namespace graphics;
	Window window("TITLE", 1024, 576);
	glClearColor(.2f, .3f, .8f, 1.f);

	float4x4 matrix;
	float4x4 matrix2;
	matrix.orthographic(-10.0f, 10.0f, -10.0f * 9.0f / 16.0f, 10.0f * 9.0f / 16.0f, -1.0f, 1.0f);
	matrix2.translate(float3(4, 3, 0));

	Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
	shader.Enable();
	shader.SetUniform("u_ProjectionMatrix", matrix);
	//shader.SetUniform("u_ModelMatrix", matrix2);

#if BATCH_RENDNRER
	Sprite sprite(99, 99, 99, 99, float4(.2f, .8f, .8f, 1.f));
	//Sprite sprite2(-2, -2, 3, 3, float4(.2f, .1f, .8f, 1.f));
	BatchRenderer2D renderer;
#else
	StaticSprite sprite(-8, -8, 99, 99, float4(.2f, .8f, .8f, 1.f), shader);
	StaticSprite sprite2(-2, -2, 3, 3, float4(.2f, .1f, .8f, 1.f), shader);
	SimpleRenderer2D renderer;
#endif

	while (!window.isClosed())
	{
		double x, y;
		Window::getMousePosition(x, y);
		shader.SetUniform("light_pos", float2((float)(x * 16.f / 1024.f), (float)(9.f - y * 9.f / 576.f)));
		//std::cout << x << ", " << y << std::endl;
		window.clear();

#if BATCH_RENDNRER
		renderer.begin();
#endif
		renderer.submit(&sprite);
		//renderer.submit(&sprite2);
		renderer.flush();
#if BATCH_RENDNRER
		renderer.end();
#endif

		window.update();
	}

	return 0;
}
