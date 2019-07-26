#include "window.h"

namespace graphics {
	Window::Window(const char* title, int width, int height)
		:m_Width(width), m_Height(height), m_Title(title)
	{
		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::getMousePosition(double& x, double& y)
	{
		x = mx;
		y = my;
	}

	bool Window::init()
	{
		if (!glfwInit()) {
			std::cout << "ERROR: GLFW not inititialize!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
		if (m_Window == nullptr)
		{
			std::cout << "ERROR: GLFW Window is not created!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "ERROR: GLEW not inititialize!" << std::endl;
			return false;
		}
		std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	//void Window::key_callback

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::isClosed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		// input handler
	}	

	void Window::window_resize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

	double Window::mx = 0;
	double Window::my = 0;


}
