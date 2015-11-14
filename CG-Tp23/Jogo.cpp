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
	myargv[0] = _strdup("CG-Tp1");

	glutInit(&myargc, myargv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(sizeScreen.first, sizeScreen.second);
	glutInitWindowPosition(posScrenn.first, posScrenn.second);
	glutCreateWindow("Jiraya's Fly");
	glutReshapeFunc(EfeitoVisual::resize);

	//fases.push_back(new Menu());
	fases.push_back(new Fase_Canhao());
    proxFase = 0;
	proximaFase();


	glutMainLoop();
}

Jogo& Jogo::getInstance()
{
	static Jogo singleton;
	return singleton;
}
void Jogo::setControlaScore() {
	controlaScore += 10000;
}
void Jogo::zeraControlaScore() {
	controlaScore = 0;
}
int Jogo::getControlaScore() {
	return controlaScore;
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
		case 27: //Tecla ESC -> Sair do Jogo
			exit(0);
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
	if (!Jogo::getInstance().pausado || Jogo::getInstance().proxFase < 2) {
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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
