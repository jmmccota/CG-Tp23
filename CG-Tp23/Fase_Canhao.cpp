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



    GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 };	   // "cor" 
    GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 
    GLfloat posicaoLuz[4] = { 8.0, 0.0, 0.0, 0.0 };
    GLfloat posicaoLuz2[4] = { -8.0, 0.0, 0.0, 0.0 };
    GLfloat posicaoLuz3[4] = { 0.0, 8.0, 0.0, 0.0 };

    // Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Ativa o uso da luz ambiente 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
    // Define os parâmetros da luz de número 1
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz2);
    // Define os parâmetros da luz de número 2
    glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz3);

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita a luz de número 1
    glEnable(GL_LIGHT1);
    // Habilita a luz de número 2
    glEnable(GL_LIGHT2);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);










    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

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
	EfeitoVisual::getInstance().setCamera();
}
