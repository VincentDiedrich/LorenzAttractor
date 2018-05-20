#include<iostream>
#include "Window.h"

namespace Kasco {
	namespace Graphics {
		Window::Window(GLint width, GLint height, const char *name)
		{
			m_width = width; 
			m_height = height;
			m_name = name;
			
			glfwInit();

			if (!init())
			{
				glfwTerminate();
			}
		}
		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{

			if (!glfwInit)
			{
				std::cout << "Failed to Initialise GLFW" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_window);
			
			return true;
		}


		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_window) == 1;
		}

	}
}
