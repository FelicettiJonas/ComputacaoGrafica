#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define janela_altura 400
#define janela_largura 600

float trans = 0;
float transH = 0;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("colisao_quadrado"); // cria janela

	//glutFullScreen();
	glutKeyboardFunc(&keyboard);  // chama teclado
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}


void keyboard(unsigned char tecla, int x, int y)
{
	printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 para esquerda: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);
	if (tecla == '1')
	{
		trans = trans - 1;
		printf("\n o valor de translacao e %.2f\n", trans);
	}
	if (tecla == '2')
	{
		trans = trans + 1;
		printf("\n o valor de translacao e %.2f\n", trans);
	}
	if (tecla == '3') {
		transH = transH - 1;
		printf("\n o valor de translacao H e %.2f\n", transH);
	}
	if (tecla == '4') {
		transH = transH + 1;
		printf("\n o valor de translacao H e %.2f\n", transH);
	}



	glutPostRedisplay();


}



void desenhar()
{

	glTranslatef(0, 0, 0);

	glBegin(GL_QUADS);

	glColor3f(1.0, 0.0, 0.0);  // cor
	glVertex2f(-100, 100);
	glVertex2f(-5, 100);
	glVertex2f(-5, 0);
	glVertex2f(-100, 0);

	glEnd();

	glTranslatef(trans, transH, 0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.2469);  // cor
	glVertex2f(100, 100);
	glVertex2f(5, 100);
	glVertex2f(5, 0);
	glVertex2f(100, 0);

	glEnd();

}

void display()
{
	glMatrixMode(GL_MODELVIEW);  //coordenadas de desenho
	glLoadIdentity();

	if ((trans <-10 && trans >-200) && (transH > -100 && transH < 100))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // cor do fundo

	}
	else
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // cor do fundo
	}

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPEZA

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