#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

class Peixe
{
public:
	GLfloat posicaoX = 00;
	GLfloat posicaoY = 0;
	GLfloat comprimento = 34;
	GLfloat altura = 12;
	bool vivo = false;

	void desenharPeixe()
	{
		if (this->vivo) {
			glPushMatrix();

			glTranslatef(posicaoX, posicaoY, 0);

			glBegin(GL_POLYGON);				// draw body
			glColor3f(0.93, 0.43, 0.02);
			glVertex2i(30, 4);
			glVertex2i(22, 12);
			glVertex2i(0, 4);
			glVertex2i(24, 0);
			glEnd();

			glPushMatrix();

			glTranslatef(-4, 0, 0);
			glBegin(GL_POLYGON);			//draw tail
			glVertex2i(4, 4);
			glVertex2i(0, 12);
			glVertex2i(1, 4);
			glVertex2i(0, 0);
			glVertex2i(4, 4);
			glEnd();
			glPopMatrix();

			glPopMatrix();
		}

	}

	void nadar(float velocidade)
	{
		this->posicaoX += velocidade;
	}

	void nascer()
	{
		this->vivo = true;
		this->posicaoX = (rand() % 300) - 750;
		this->posicaoY = (rand() % 600) - 400;
	}
};

