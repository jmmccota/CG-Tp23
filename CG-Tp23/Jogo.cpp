#include "Jogo.hpp"

Jogo::Jogo()
{
	score = new Score();
}

Jogo::~Jogo()
{

}

void Jogo::run()
{
	pair<int, int> sizeScreen = EfeitoVisual::getInstance().sizeScreen();
	pair<int, int> posScrenn = EfeitoVisual::getInstance().positionScreen("center");
	char *myargv[1];
	int myargc = 1;
	myargv[0] = _strdup("CG-Tp23");

	glutInit(&myargc, myargv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(sizeScreen.first, sizeScreen.second);
	glutInitWindowPosition(posScrenn.first, posScrenn.second);
	glutCreateWindow("CG-Tp23");
	glutReshapeFunc(EfeitoVisual::resize);

	//fases.push_back(new Menu());
	fases.push_back(new Fase_Canhao(this));
    proxFase = 0;
	proximaFase();


	glutMainLoop();
}

Jogo& Jogo::getInstance()
{
	static Jogo singleton;
	return singleton;
}

void Jogo::mouse(int button, int state, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->mouse(button, state, x, y);
}
void Jogo::keyDown(unsigned char key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyDown(key, x, y);
}
void Jogo::keyUp(unsigned char key, int x, int y)
{
	switch (key)
    {
        case 'P':
        case 'p': //pause
            Jogo::getInstance().pausado = !Jogo::getInstance().pausado;
            break;
		default:
			Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyUp(key, x, y);
			break;
	}

}

void Jogo::specialKeyDown(int key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->specialKeyDown(key, x, y);
}
void Jogo::specialKeyUp(int key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->specialKeyUp(key, x, y);
}

void Jogo::draw()
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->desenha();
}
void Jogo::timer(int value)
{
	if (!Jogo::getInstance().pausado) {
		Jogo::getInstance().estado++;
		Jogo::getInstance().fases[Jogo::getInstance().proxFase]->atualiza(value);
		glutPostRedisplay();
	}
	glutTimerFunc(TEMPOQUADRO, Jogo::timer, Jogo::getInstance().estado);
}

void Jogo::inicializa(int fase)
{
	estado = 0;
	// Inicializa o sistema de coordenadas
	glutMouseFunc(Jogo::mouse);
	glutKeyboardFunc(Jogo::keyDown);
	glutKeyboardUpFunc(Jogo::keyUp);
	glutSpecialFunc(Jogo::specialKeyDown);
	glutSpecialUpFunc(Jogo::specialKeyUp);
	glutDisplayFunc(Jogo::draw);
	glutTimerFunc(TEMPOQUADRO, Jogo::timer, 1);
	EfeitoSonoro::getInstance().finishAllAudios();
	Jogo::getInstance().fases[fase]->inicializa();

}

void Jogo::proximaFase()
{
	if (proxFase != -1)
		inicializa(proxFase);
	else
		fimJogo();
}

void Jogo::setProxFase(int p)
{
	proxFase = p;
}

void Jogo::fimJogo()
{
	exit(0);
}
 