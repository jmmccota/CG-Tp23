#include "Fase_Canhao.hpp"



Fase_Canhao::Fase_Canhao()
{
}

Fase_Canhao::~Fase_Canhao()
{
}

void Fase_Canhao::definePersonagens()
{
}

void Fase_Canhao::desenhaBackground()
{
}

void Fase_Canhao::desenhaHUD()
{
}

void Fase_Canhao::desenha()
{
    EfeitoVisual::getInstance().setCamera();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    EfeitoVisual::getInstance().setCamera();


	//principal->desenha();

	for (auto i = inimigos.begin(); i != inimigos.end(); i++)
		(*i)->desenha();

	for (auto i = projeteis.begin(); i != projeteis.end(); i++)
		(*i)->desenha();

	glutSwapBuffers();
}

void Fase_Canhao::terminou()
{
}

void Fase_Canhao::atualiza(int value)
{
}

void Fase_Canhao::mouse(int button, int state, int x, int y)
{
}

void Fase_Canhao::keyDown(unsigned char key, int x, int y)
{
}

void Fase_Canhao::keyUp(unsigned char key, int x, int y)
{
}

void Fase_Canhao::specialKeyDown(int key, int x, int y)
{
}

void Fase_Canhao::specialKeyUp(int key, int x, int y)
{
}

void Fase_Canhao::inicializa()
{
    projeteis.push_back(new Bala());
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0);
}
