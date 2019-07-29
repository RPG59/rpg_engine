#include "window.h"
#include "shader.h"

#include "renderable2d.h"
#include "simpleRenderer2d.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")

int main()
{
	using namespace graphics;
	Window window("TITLE", 1024, 576);
	glClearColor(.2f, .3f, .8f, 1.f);

	float4x4 matrix;
	matrix.orthographic(-10.0f, 10.0f, -10.0f * 9.0f / 16.0f, 10.0f * 9.0f / 16.0f, -1.0f, 1.0f);

	Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
	shader.Enable();
	shader.SetUniform("u_ProjectionMatrix", matrix);

	Renderable2D* sprite = new Renderable2D(float3(-5, -5, 0), float2(4, 5), float4(.2f, .8f, .8f, 1.f), shader);
	Renderable2D* sprite2 = new Renderable2D(float3(-2, -2, 0), float2(3, 3), float4(.2f, .1f, .8f, 1.f), shader);
	SimpleRenderer2D renderer;

	while (!window.isClosed())
	{
		double x, y;
		Window::getMousePosition(x, y);
		shader.SetUniform("light_pos", float2((float)(x * 16.f / 1024.f), (float)(9.f - y * 9.f / 576.f)));
		std::cout << x << ", " << y << std::endl;
		window.clear();

		renderer.submit(sprite);
		renderer.submit(sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}
