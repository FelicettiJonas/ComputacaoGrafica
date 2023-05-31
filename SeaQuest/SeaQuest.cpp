#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Ovo.h"

#define PI 3.1415926535898 
#define janela_altura 800
#define janela_largura 900

Ovo ovo = Ovo(200, 30);

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(300, 100); // posicao que surge a janela
	glutCreateWindow("circulo"); // cria janela

	//glutFullScreen();
	glutKeyboardFunc(&keyboard);  // chama teclado
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}

void frame()
{
	Ovo ovo2 = Ovo(-200, -30);
	ovo.desenharOvo();

	glPushMatrix();
	glTranslatef(ovo.initialX, ovo.initialY, 0);
	glBegin(GL_LINE_LOOP);
	glColor3ub(200, 40, 239);  // cor
	glVertex2f(0, 15);
	glVertex2f(50, 15);
	glVertex2f(50, 0);
	glVertex2f(0, 0);
	glEnd();

	if (!(ovo.initialX < ovo2.initialX - 50 || ovo.initialX-50 > ovo2.initialX)) {
		printf("Bateu");
	}

	glPopMatrix();
	
	ovo2.desenharOvo();
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

	frame();

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

void keyboard(unsigned char tecla, int x, int y)
{
	printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 para esquerda: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);
	if (tecla == '1')
	{
		ovo.initialX = ovo.initialX - 5;
		printf("\n o valor de translacao e %.2f\n", ovo.initialX);
	}

	glutPostRedisplay();

}
