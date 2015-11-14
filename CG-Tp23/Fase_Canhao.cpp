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

	for (auto i = inimigos.begin(); i != inimigos.end(); i++)
		(*i)->desenha();

	for (auto i = projeteis.begin(); i != projeteis.end(); i++)
        (*i)->desenha();

    principal->desenha();

	glutSwapBuffers();
}

void Fase_Canhao::terminou()
{
}

void Fase_Canhao::atualiza(int value)
{
    for (auto i = inimigos.begin(); i != inimigos.end(); i++)
        (*i)->acao(0);

    for (auto i = projeteis.begin(); i != projeteis.end(); i++)
        (*i)->acao(0);



    //Remove coisas inativas
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
        case 'P':
        case 'p':
            rand();
            inimigos.push_back(new Relogio(rand() % 200 - 100, -50, rand() % 200 - 200, 1));
            inimigos.back()->setVel(std::make_tuple(rand() % 5 - 2.5, rand() % 5, rand() % 5 - 2.5));
            inimigos.back()->setAcel(std::make_tuple(0, -0.02, 0));
            break;
    }
}

void Fase_Canhao::keyUp(unsigned char key, int x, int y)
{
}

void Fase_Canhao::specialKeyDown(int key, int x, int y)
{
    principal->acao(key);
}

void Fase_Canhao::specialKeyUp(int key, int x, int y)
{
}

void Fase_Canhao::inicializa()
{
    principal = new Canhao(0, 0, 0, 1);
    srand(time(NULL));
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClearDepth(1.0);
}
 