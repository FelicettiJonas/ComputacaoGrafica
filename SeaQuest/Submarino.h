#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898 

class Submarino
{
public:
	GLfloat posicaoX = 0;
	GLfloat posicaoY = 190;
	GLfloat comprimento = 50;
	GLfloat altura = 15;
	bool vivo = false;


	void desenharSubmarino()
	{
		if (this->vivo)
		{
			glPushMatrix();

			glTranslatef(posicaoX, posicaoY, 0);

			// Draw the body of the submarine
			glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color
			glBegin(GL_POLYGON);
			glVertex2i(0, 15);
			glVertex2i(40, 15);
			glVertex2i(40, 0);
			glVertex2i(0, 0);
			glEnd();


			glTranslatef(0, 7.5, 0);
			const float radius = 7.5f;
			const int numSegments = 10;
			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0.0f, 0.0f);  // Center of the circle
			for (int i = 0; i < numSegments; i++)
			{
				GLfloat ang = (2 * PI * i) / numSegments;
				glVertex2f(cos(ang) * radius, sin(ang) * radius);
			}
			glEnd();

			// Draw the propeller
			glTranslatef(40, -7.50, 0);

			glColor3f(1.0f, 0.8f, 0.2f);
			glBegin(GL_TRIANGLES);
			glVertex2i(10, 15);
			glVertex2i(0, 7);
			glVertex2i(10, 0);
			glEnd();

			glPopMatrix();

		}
	}

	void nascer()
	{
		this->posicaoX = 0;
		this->posicaoY = 190;
		this->vivo = true;
	}
};
