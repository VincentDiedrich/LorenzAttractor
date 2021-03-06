#include<iostream>
#include "src/graphics/Window.h"

using namespace Kasco::Graphics;

float delta = 0;
float oldTime;
float currentTime;
float STEP = 0.01f;

float red = 0.3f;

int main()
{
	Window window(1200, 900, "Kasco Engine");
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	glScalef(0.02f, 0.02f, 0.02f);
	glTranslatef(-1, -1, 0);

	currentTime = 0;
	oldTime = glfwGetTime();
	int initialIterations = 1;

	while (!window.closed())
	{
		glRotatef(delta * 10, 1, 1, 0);
		delta = glfwGetTime() - oldTime;
		
		oldTime = glfwGetTime();
		
		currentTime += delta;

		if (currentTime >= STEP)
		{
			currentTime = (currentTime - STEP);
			initialIterations += 1;
			if (initialIterations >= 50000)
			{
				initialIterations = 50000;
			}
			
		}

		window.clear();

		/*glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();*/

		

		float x = 0.01;
		float y = 0;
		float z = 0;

		float a = 10;
		float b = 28;
		float c = 8 / 3;

		
		


		glColor3f(0.2f, red, 0.8f);
		red + 0.5f;
			if (red >= 255.0f)
			{
				red = 0.1f;
			}

		glLineWidth(3.5f);

		glBegin(GL_LINE_STRIP);
		int i;
		for (i = 0; i < initialIterations; i++)
		{
			
			float dt = 0.01;
			float dx = a * (y - x) * dt;
			float dy = (x * (b - z) - y) * dt;
			float dz = (x * y - c * z) * dt;
			x = x + dx;
			y = y + dy;
			z = z + dz;
			
			//std::cout << x << y << z << std::endl;

			glVertex3f(x, y, z);
		}

		glEnd();

		window.update();
	}
    return 0;
}

