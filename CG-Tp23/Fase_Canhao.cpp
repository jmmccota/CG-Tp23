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
    //principal->acao();

    for (auto i = inimigos.begin(); i != inimigos.end(); i++)
        (*i)->acao();

    for (auto i = projeteis.begin(); i != projeteis.end(); i++)
        (*i)->acao();
}

void Fase_Canhao::mouse(int button, int state, int x, int y)
{
}

void Fase_Canhao::keyDown(unsigned char key, int x, int y)
{
    switch (key){
    case '1':
        EfeitoVisual::getInstance().posX++;
        break;
    case '2':
        EfeitoVisual::getInstance().posX--;
        break;
    case '3':
        EfeitoVisual::getInstance().posY++;
        break;
    case '4':
        EfeitoVisual::getInstance().posY--;
        break;
    case '5':
        EfeitoVisual::getInstance().posZ++;
        break;
    case '6':
        EfeitoVisual::getInstance().posZ--;
        break;
    }
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
    projeteis.push_back(new Relogio(100, -50, -100, 1));
    projeteis.back()->gira(0, 0, 0);
    projeteis.back()->setVel(std::make_tuple(-2, 2, -1));
    projeteis.back()->setAcel(std::make_tuple(0, -0.02, 0));
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClearDepth(1.0);
}
 