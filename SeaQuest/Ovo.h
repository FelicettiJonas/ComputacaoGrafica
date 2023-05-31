#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898 

class Ovo
{
public:
	GLfloat initialX = 0;
	GLfloat initialY = 0;
	Ovo(GLfloat initialX, GLfloat initialY)
	{
		this -> initialX = initialX;
		this -> initialY = initialY;
		printf("%lf\n", initialX);
	}


	void desenharOvo()
	{

		glPushMatrix();

		glTranslatef(initialX, initialY, 0);

		// Draw the body of the submarine
		glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color
		glBegin(GL_POLYGON);
		glVertex2i(0, 15);
		glVertex2i(40, 15);
		glVertex2i(40, 0);
		glVertex2i(0, 0);
		glEnd();

		const float radius = 10.0f;
		const int numSegments = 100;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(100.0f, 200.0f);  // Center of the circle
		for (int i = 0; i <= numSegments; i++) {
			float theta = 2.0f * PI * static_cast<float>(i) / static_cast<float>(numSegments);
			float x = radius * cos(theta);
			float y = radius * sin(theta);
			glVertex2f(x, y);
		}
		glEnd();

		// Draw the propeller
		glTranslatef(40, 0, 0);

		glColor3f(1.0f, 0.8f, 0.2f);
		glBegin(GL_TRIANGLES);
		glVertex2i(10, 15);
		glVertex2i(0, 7);
		glVertex2i(10, 0);
		glEnd();

		glPopMatrix();
	}
};
