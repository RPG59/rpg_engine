#pragma once
#include <iostream>

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

namespace graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window {
	private:
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window = nullptr;
		//bool m_Closed;

		static double mx, my;


	public:
		Window(const char* title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool isClosed() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		static void getMousePosition(double& x, double& y);
	private:
		bool init();

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void window_resize(GLFWwindow* window, int width, int height);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};
}

