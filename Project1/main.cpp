#include "window.h"
#include "shader.h"

#include "renderable2d.h"
#include "simpleRenderer2d.h"

int main()
{
	using namespace graphics;
	Window window("TITLE", 1024, 768);
	glClearColor(.2f, .3f, .8f, 1.f);


	const float vertices[] = {
		-0.5f, -0.5f, .0f,
		0.5f, -0.5f, .0f,
		0.5f, 0.5f, .0f,
		-0.5f, 0.5f, .0f,
	};


	//uint32_t vbo;
	//glGenBuffers(1, &vbo);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glEnableVertexAttribArray(0);

	float4x4 matrix;
	matrix.orthographic(.0f, 16.f, .0f, 9.f, -1.f, 1.f);
	float4x4 matrix2;
	matrix2.translate(float3(4, 3, 0));

	Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
	shader.Enable();
	shader.SetUniform("pr_matrix", matrix);
	shader.SetUniform("ml_matrix", matrix2);
	Renderable2D* sprite = new Renderable2D(float3(5, 5, 0), float2(4, 4), float4(1, 0, 1, 1), shader);
	SimpleRenderer2D renderer;

	while (!window.isClosed())
	{
		double x, y;
		Window::getMousePosition(x, y);
		//std::cout << x << ", " << y << std::endl;
		window.clear();
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		renderer.submit(sprite);
		renderer.flush();
		

		window.update();
	}

	return 0;
}
