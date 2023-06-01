#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Submarino.h"
#include "Peixe.h"
#include "Background.h"
#include "Tiro.h"
#include <chrono>
#include <thread>

#define PI 3.1415926535898 
#define janela_altura 800
#define janela_largura 900

Submarino submarino = Submarino();
Background background;
Tiro tiro;
Peixe peixes[] = { 
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
	Peixe(),
};


const int kTargetFrameRate = 60;  // Target frame rate in FPS

void display(void);
void tela(GLsizei w, GLsizei h);
void verificarColisao();
void keyboard(unsigned char tecla, int x, int y);
void timerFunc(int value);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(300, 100); // posicao que surge a janela
	glutCreateWindow("SeaQuest"); // cria janela


	//glutFullScreen();
	glutKeyboardFunc(&keyboard);  // chama teclado
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);

	glutTimerFunc(0, timerFunc, 0);

	glutMainLoop(); // redesenhar

	return(0);
}

void frame()
{
	background.desenhar();

	if (tiro.vivo)
	{
		tiro.desenhar();
		tiro.nadar(5);
	}

	if (submarino.vivo)
	{
		submarino.desenharSubmarino();
	}
	else
	{
		submarino.nascer();
	}


	for (int i = 0; i < 10; i++)
	{
		if (peixes[i].vivo)
		{
			peixes[i].nadar(0.5);

			peixes[i].desenharPeixe();
		}
		else
		{
			peixes[i].nascer();
		}
	}

	verificarColisao();
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

	glutPostRedisplay();

}

void tela(GLsizei w, GLsizei h)
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);


	glMatrixMode(GL_MODELVIEW);

}

void verificarColisao()
{
	for (int i = 0; i < 10; i++)
	{
		if (peixes[i].vivo)
		{
			if (
				(!(submarino.posicaoX < peixes[i].posicaoX - submarino.comprimento || submarino.posicaoX - peixes[i].comprimento > peixes[i].posicaoX)) &&
				(!(submarino.posicaoY < peixes[i].posicaoY - submarino.altura || submarino.posicaoY - peixes[i].altura > peixes[i].posicaoY))
				)
			{
				printf("\n Bateu");
				peixes[i].vivo = false;
				submarino.vivo = false;
			}

			if (
				(!(tiro.posicaoX < peixes[i].posicaoX - tiro.comprimento || tiro.posicaoX - peixes[i].comprimento > peixes[i].posicaoX)) &&
				(!(tiro.posicaoY < peixes[i].posicaoY - tiro.altura || tiro.posicaoY - peixes[i].altura > peixes[i].posicaoY))
				)
			{
				printf("\n Acertou! - Arma Recarregada");
				peixes[i].vivo = false;
				tiro.vivo = false;
			}

			if (peixes[i].posicaoX > 500)
			{
				printf("\n Saiu da Tela");
				peixes[i].vivo = false;
			}
		}

		if (tiro.vivo && tiro.posicaoX < -500)
		{
			printf("\n Arma Recarregada");
			tiro.vivo = false;
		}

	}
}

void keyboard(unsigned char tecla, int x, int y)
{
	/*printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 para esquerda: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);*/
	if (tecla == 'a')
	{
		if (submarino.posicaoX > -450)
		{
			submarino.posicaoX = submarino.posicaoX - 5;
			//printf("\n o valor de translacao e %.2f\n", submarino.posicaoX);

		}
	}

	if (tecla == 'd')
	{	
		if (submarino.posicaoX < 400)
		{
			submarino.posicaoX = submarino.posicaoX + 5;
			//printf("\n o valor de translacao e %.2f\n", submarino.posicaoX);

		}
	}

	if (tecla == 's')
	{
		if (submarino.posicaoY > -400)
		{
			submarino.posicaoY = submarino.posicaoY - 5;
			//printf("\n o valor de translacao e %.2f\n", submarino.posicaoX);

		}
	}

	if (tecla == 'w')
	{
		if (submarino.posicaoY < 190)
		{
			submarino.posicaoY = submarino.posicaoY + 5;
			//printf("\n o valor de translacao e %.2f\n", submarino.posicaoX);

		}
	}

	if (tecla == ' ')
	{
		if (!tiro.vivo)
		{
			tiro.nascer(submarino.posicaoX, submarino.posicaoY + 7);
		}
	}

	glutPostRedisplay();

	return;
}


void timerFunc(int value) {
	// Calculate the duration of each frame
	constexpr auto targetFrameDuration = std::chrono::milliseconds(1000 / kTargetFrameRate);
	static auto previousTime = std::chrono::high_resolution_clock::now();

	// Call the display function
	display();

	// Calculate the elapsed time
	const auto currentTime = std::chrono::high_resolution_clock::now();
	const auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime);

	// Calculate the remaining time to reach the target frame duration
	const auto remainingTime = targetFrameDuration - elapsedTime;

	// Sleep for the remaining time if it's greater than zero
	if (remainingTime > std::chrono::milliseconds(0)) {
		std::this_thread::sleep_for(remainingTime);
	}

	// Update the previous time for the next frame
	previousTime = currentTime;

	// Call the timer function again
	glutTimerFunc(0, timerFunc, 0);
}