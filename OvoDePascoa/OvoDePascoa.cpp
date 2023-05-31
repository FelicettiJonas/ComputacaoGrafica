#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898 
#define janela_altura 400
#define janela_largura 600

void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("circulo"); // cria janela

	//glutFullScreen();
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}

void desenhar()
{
	GLfloat circ_pnt = 300;
	GLfloat ang, raioX = 40.0f, raioY = 80.0f;


	GLfloat raioX2 = 10.0f, raioY2 = 10.0f;


	glBegin(GL_POLYGON);
	glColor3ub(80, 40, 239);  // cor
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
		//printf("%f   %f\n", cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	//papel do ovo de pascoa
	glBegin(GL_TRIANGLES);
	glColor3ub(80, 40, 239);  // cor
	glVertex2f(40, 130);
	glVertex2f(-40, 130);
	glVertex2f(0, 60);
	glEnd();




	//circulo do laço

	glBegin(GL_POLYGON);
	glColor3ub(246, 224, 1);  // cor
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX2, (sin(ang) * raioY2)+80);
		//printf("%f   %f\n", cos(ang) * raioX2, sin(ang) * raioY2);
	}
	glEnd();

	//triangulos do laço
	glBegin(GL_TRIANGLES);
	glColor3ub(246, 224, 1);  // cor
	glVertex2f(60.0f, 110.0f);
	glVertex2f(60.0f, 60.0f);
	glVertex2f(0.0f, 80.0f);
	glEnd();

	//triangulos do laço
	glBegin(GL_TRIANGLES);
	glColor3ub(246, 224, 1);  // cor
	glVertex2f(-60.0f, 110.0f);
	glVertex2f(-60.0f, 60.0f);
	glVertex2f(0.0f, 80.0f);
	glEnd();

}

void display()
{
	glMatrixMode(GL_MODELVIEW);  //coordenadas de desenho
	glLoadIdentity();

	glClearColor(0.13, 0.13, 0.27, 1); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA

	// Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();


	glFlush();  // execute o desenho

}

void tela(GLsizei w, GLsizei h)
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);


	glMatrixMode(GL_MODELVIEW);

}