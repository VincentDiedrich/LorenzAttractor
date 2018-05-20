#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<GLFW/glfw3.h>


namespace Kasco {
	namespace Graphics {
	
	class Window{
	public:
		Window(GLint width, GLint height, const char *name);
		~Window();
		//void init();
		void update() const;
		bool closed() const;
		void clear() const;

	private:
		bool init();
			
	private:
		GLint m_width, m_height;
		const char *m_name; 
		GLFWwindow *m_window;
		bool m_closed;
	};
	}
}

#endif // !WINDOW_H
