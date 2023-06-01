#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

class Background
{
public:
	void desenhar()
	{
		glBegin(GL_QUADS);
		glColor3f(0.16, 0.48, 0.6);
		glVertex2i(-450, -400);
		glVertex2i(450, -400);
		glColor3f(0.33, 0.29, 0.5);
		glVertex2i(450, 200);
		glVertex2i(-450, 200);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.59, 0.11, 0.47);
		glVertex2i(-450, 200);
		glVertex2i(450, 200);
		glColor3f(0.88, 0.46, 0.14);
		glVertex2i(450, 400);
		glVertex2i(-450, 400);
		glEnd();
	}
};

