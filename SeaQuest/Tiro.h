#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

class Tiro
{
public:
	GLfloat posicaoX;
	GLfloat posicaoY;
	GLfloat comprimento = 7;
	GLfloat altura = 3;
	bool vivo = false;

	void desenhar()
	{
		glPushMatrix();

		glTranslated(posicaoX, posicaoY, 0);
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(0, 3);
		glVertex2i(7, 3);
		glVertex2i(7, 0);
		glVertex2i(0, 0);
		glEnd();

		glPopMatrix();
	}

	void nadar(float velocidade)
	{
		this->posicaoX -= velocidade;
	}

	void nascer(GLfloat posicaoX, GLfloat posicaoY)
	{
		this->posicaoX = posicaoX;
		this->posicaoY = posicaoY;
		this->vivo = true;
	}
};

