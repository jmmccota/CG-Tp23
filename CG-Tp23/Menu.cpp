#include "Menu.hpp"
#define FONT_DEFAULT GLUT_BITMAP_HELVETICA_18

Menu::~Menu() {

}

void Menu::definePersonagens() {
}

void Menu::desenhaBackground() {
}
void Menu::insereLuzes() {

}
#pragma region "Pack de Desenho do Menu"

//-------------- Usado para pegar Dinamicamente a Posição dos Elementos do Menu ---------------
struct PositionMenuElement
{
	float posInit_X;
	float posEnd_X;
	float posInit_Y;
	float posEnd_Y;

};
vector<PositionMenuElement> vetPosMenuElements;
//----------------------------------------------------------------------------------------------
int setaSelectOption = 0;
bool limitX = false;

float xFixo = 0;

//Desenha uma Linha - Parametro: posição em relação ao eixo Y
void drawLine(float pos, char eixo) {

	pair<int, int> size = EfeitoVisual::getInstance().getOrtho2D();

	glColor3f(1, 0.27, 0);
	glLineWidth(3.0f);
	if (eixo == 'x') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(pos, 0.0);
		glVertex2f(pos, size.second);
		glEnd();
	}
	else if (eixo == 'y') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, pos);
		glVertex2f(size.first, pos);
		glEnd();
	}
}

//Desenha Quadrado para Opções - Paremetros: Posição x, Posição Y, Titulo 
void drawSquad(float posX, float posY, string titulo) {

	pair<float, float> fullHD = EfeitoVisual::getInstance().getOrtho2D();	
	float rasterX = fullHD.first - posX;
	float rasterY = 25;

	if (EfeitoVisual::getInstance().isFullScreen()) {
		glRasterPos2f(posX - (titulo.length() * 5) + ((rasterX - posX) / 2), posY - 10);
	}
	else {
		glRasterPos2f(posX - (titulo.length() * 10) + ((rasterX - posX) / 2), posY - 10);

	}
	glColor3f(0.0, 0.0, 1);
	FuncoesAuxiliares::writeWord_BITMAP(titulo, FONT_DEFAULT);

	//-------------------- BEGIN BOXES DE BESTSCORES ---------------------
	glColor3f(0.0, 0.0, 1);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(rasterX - 11.1111112, posY + 35.5555556);
	glVertex2f(rasterX - 6.6666666, posY + 31.1111111);
	glVertex2f(rasterX - 3.3333333, posY + 24.4444444);
	glVertex2f(rasterX - 2.2222222, posY + 13.3333333);
	glVertex2f(rasterX, posY);
	glVertex2f(rasterX, rasterY);
	glVertex2f(rasterX - 1.1111111, posY - 13.3333333);
	glVertex2f(rasterX - 3.3333333, posY - 24.4444444);
	glVertex2f(rasterX - 6.6666666, posY - 31.1111111);
	glVertex2f(rasterX - 11.1111112, posY - 35.5555556);
	glVertex2f(posX + 11.1111112, posY - 35.5555556);
	glVertex2f(posX + 6.6666666, posY - 31.1111111);
	glVertex2f(posX + 3.3333333, posY - 24.4444444);
	glVertex2f(posX + 1.1111111, posY - 13.3333333);
	glVertex2f(posX, posY);
	glVertex2f(posX, rasterY);
	glVertex2f(posX + 1.1111111, posY + 13.3333333);
	glVertex2f(posX + 3.3333333, posY + 24.4444444);
	glVertex2f(posX + 6.6666666, posY + 31.1111111);
	glVertex2f(posX + 11.1111112, posY + 35.5555556);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(posX, rasterY);
	glVertex2f(rasterX, rasterY);
	glEnd();
	//Desenha Seta para Volta
	int xSetaVolta = 20, ySetaVolta = 30;
	glColor3f(1, 0.27, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(40+ xSetaVolta, 380 + ySetaVolta);
	glVertex2i(15 + xSetaVolta, 350 + ySetaVolta);
	glVertex2i(40 + xSetaVolta, 320 + ySetaVolta);
	glVertex2i(40 + xSetaVolta, 340 + ySetaVolta);
	glVertex2i(85 + xSetaVolta, 340 + ySetaVolta);
	glVertex2i(85 + xSetaVolta, 360 + ySetaVolta);
	glVertex2i(40 + xSetaVolta, 360 + ySetaVolta);
	glEnd();
	//-------------------- END BOXES DE BESTSCORES ---------------------
}

//Desenha as Opções Dinamicamente - Parametros: options, quantidade de Opções, e a posição inial Y
void drawOptionsMenu(char *options[], int quantOptions, int posY) {

	//Limpa vetor de posições de elementos do menu
	if (vetPosMenuElements.size() > 0) {
		vetPosMenuElements.clear();
	}

	pair<int, int> ortho = EfeitoVisual::getInstance().getOrtho2D();
	float rasterX = 100;
	float rasterY = posY;

	//Escreve na tela
	for (int pos = 0; pos < quantOptions; pos++) {
		if (pos == setaSelectOption) {
			glColor3f(1.0, 1.0, 1.0);
		}
		else {
			//glColor3f(0, 1.0, 0.9);
			glColor3f(1, 0.27, 0);
		}

		string titulo = options[pos];
		if (EfeitoVisual::getInstance().isFullScreen()) {
			glRasterPos2f(rasterX - (titulo.length() * 5) + 251, rasterY - 10);
		}
		else {
			glRasterPos2f(rasterX - (titulo.length() * 10) + 251, rasterY - 10);
		}
		FuncoesAuxiliares::writeWord_BITMAP(titulo, FONT_DEFAULT);

		//-------------------- BEGIN BOXES DE OPÇÕES ---------------------
		glLineWidth(2.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(rasterX + 588.89, rasterY + 35.56);
		glVertex2f(rasterX + 593.34, rasterY + 31.11);
		glVertex2f(rasterX + 596.67, rasterY + 24.44);
		glVertex2f(rasterX + 598.89, rasterY + 13.33);
		glVertex2f(rasterX + 600, rasterY + 0.11);
		glVertex2f(rasterX + 600, rasterY - 0.11);
		glVertex2f(rasterX + 598.89, rasterY - 13.33);
		glVertex2f(rasterX + 596.67, rasterY - 24.44);
		glVertex2f(rasterX + 593.33, rasterY - 31.11);
		glVertex2f(rasterX + 588.89, rasterY - 35.56);
		glVertex2f(rasterX - 88.89, rasterY - 35.56);
		glVertex2f(rasterX - 93.33, rasterY - 31.11);
		glVertex2f(rasterX - 96.67, rasterY - 24.44);
		glVertex2f(rasterX - 98.89, rasterY - 13.33);
		glVertex2f(rasterX - 100, rasterY - 0.11);
		glVertex2f(rasterX - 100, rasterY + 0.11);
		glVertex2f(rasterX - 98.89, rasterY + 13.33);
		glVertex2f(rasterX - 96.67, rasterY + 24.44);
		glVertex2f(rasterX - 93.33, rasterY + 31.11);
		glVertex2f(rasterX - 88.89, rasterY + 35.56);
		glEnd();
		//---------------------- END BOXES DE OPÇÕES ----------------------

		PositionMenuElement pElement;
		pElement.posInit_X = rasterX - 100;
		pElement.posEnd_X = rasterX + 600;
		pElement.posInit_Y = ortho.second - 35.56 - rasterY;
		pElement.posEnd_Y = ortho.second + 35.56 - rasterY;

		vetPosMenuElements.push_back(pElement);

		rasterY -= 90;
	}

}


//Desenha a Opção do Menu 
void drawOpcoesMenu() {

	int rasterY = 320;
	glColor3f(1, 1, 1);

	glRasterPos2f(40, rasterY);
	FuncoesAuxiliares::writeWord_BITMAP("O objetivo do jogo é atingir o maior numero de relogios possiveis!", FONT_DEFAULT);

	glRasterPos2f(40, rasterY - 40);
	FuncoesAuxiliares::writeWord_BITMAP("Cada relogio destruido sao mais 10 pontos!", FONT_DEFAULT);

	glRasterPos2f(40, rasterY - 80);
	FuncoesAuxiliares::writeWord_BITMAP("Comandos:", FONT_DEFAULT);

	glRasterPos2f(60, rasterY - 120);
	FuncoesAuxiliares::writeWord_BITMAP("- Setas direcionais movimentam o Canhao.", FONT_DEFAULT);

	glRasterPos2f(60, rasterY - 160);
	FuncoesAuxiliares::writeWord_BITMAP("- Para nevoa utilize os botoes '+' ou '-'", FONT_DEFAULT);
	glRasterPos2f(60, rasterY - 200);
	FuncoesAuxiliares::writeWord_BITMAP("- Z para atirar e Q para pausar.", FONT_DEFAULT);

	glColor3f(1, 0.27, 0);

	glRasterPos2f(90, 55);
	FuncoesAuxiliares::writeWord_BITMAP("Z", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(165, 55);
	FuncoesAuxiliares::writeWord_BITMAP("Q", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(250, 55);
	FuncoesAuxiliares::writeWord_BITMAP("+", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(330, 55);
	FuncoesAuxiliares::writeWord_BITMAP("-", GLUT_BITMAP_TIMES_ROMAN_24);
	int xSetas = 30;
	glRasterPos2f(490 - xSetas-10, 160);
	FuncoesAuxiliares::writeWord_BITMAP("<-", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(570 - xSetas, 160);
	FuncoesAuxiliares::writeWord_BITMAP("v", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(650 - xSetas-10, 160);
	FuncoesAuxiliares::writeWord_BITMAP("->", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(573 - xSetas, 240);
	FuncoesAuxiliares::writeWord_BITMAP("^", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1, 0.27, 0);
	/*--------------- BOXES COMANDOS -------------------*/
	//glBegin(GL_LINE_LOOP);
	//glVertex2i(220, 260); //Barra espaço
	//glVertex2i(730, 260);
	//glVertex2i(730, 180);
	//glVertex2i(220, 180);
	//glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 100); //Z
	glVertex2i(130, 100);
	glVertex2i(130, 30);
	glVertex2i(60, 30);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(140, 100); //X
	glVertex2i(210, 100);
	glVertex2i(210, 30);
	glVertex2i(140, 30);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(220, 100); //F
	glVertex2i(290, 100);
	glVertex2i(290, 30);
	glVertex2i(220, 30);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(300, 100); //P
	glVertex2i(370, 100);
	glVertex2i(370, 30);
	glVertex2i(300, 30);
	glEnd();
	
	glBegin(GL_LINE_LOOP); //Seta esquerda
	glVertex2i(460-xSetas, 210);
	glVertex2i(530 - xSetas, 210);
	glVertex2i(530 - xSetas, 140);
	glVertex2i(460 - xSetas, 140);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(540 - xSetas, 210); //Seta baixo
	glVertex2i(610 - xSetas, 210);
	glVertex2i(610 - xSetas, 140);
	glVertex2i(540 - xSetas, 140);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(620 - xSetas, 210); //Seta direita
	glVertex2i(690 - xSetas, 210);
	glVertex2i(690 - xSetas, 140);
	glVertex2i(620 - xSetas, 140);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(540 - xSetas, 290); //Seta cima
	glVertex2i(610 - xSetas, 290);
	glVertex2i(610 - xSetas, 220);
	glVertex2i(540 - xSetas, 220);
	glEnd();

	/*-------------- END COMANDOS SETAS ------------------*/

}

#pragma endregion

void Menu::desenha() {

    glDisable(GL_CULL_FACE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

	pair<int, int> sizeScreen = EfeitoVisual::getInstance().getOrtho2D();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenha Linha Superior Y
	drawLine(sizeScreen.second - 20, 'y');
	//Desenha Linha Inferior Y
	drawLine(20, 'y');

	//if (optMelhores) {//Tela Melhores Pontuações
	EfeitoVisual::getInstance().desenhaTitulo(60, -185);
	//	drawSquad(150, 550, "MELHORES PONTUACOES");
	//	// 5 Valores - Passar 80 por parametro
	//	// 7 Valores - Passar 47 por parametro
	//	// 10 Valores - Passar 30 por Parametro
	//	/*drawBestScoresMenu(Score::getBestScore(7), 47);*/
	//}
	//else 
	if (optOpcoes) {//Tela de Opções
		EfeitoVisual::getInstance().desenhaTitulo(60, -185);
		drawSquad(20, 380, "OPCOES");
		drawOpcoesMenu();
	}
	else if (optSair) {
		exit(1);
	}
	else {//Opções do Menu Inicial
		/*EfeitoVisual::getInstance().desenhaTitulo(1100, 0);*/

		char *options[3];
		options[0] = "NOVO JOGO";
		/*options[1] = "MELHORES PONTUACOES";*/
		options[1] = "OPCOES";
		options[2] = "SAIR";
		drawOptionsMenu(options, 3, 291);

	}

	glutSwapBuffers();
}

void Menu::terminou()
{
	if (optSair)
	{
		Jogo::getInstance().setProxFase(-1);
		Jogo::getInstance().proximaFase();
	}
	else if (optIniciar)
	{
		//EfeitoSonoro::getInstance().finishAllAudios();
		optIniciar = false;
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();

	}
}

void Menu::atualiza(int value) {

    //Testa se a fase acabou
    terminou();

    // Muda a direção quando chega na borda esquerda ou direita
    if (posX1 > windowWidth - POSrsize || posX1 < 0)
        xstep = -xstep;

    // Muda a direção quando chega na borda superior ou inferior
    if (PosY1 > windowHeight - POSrsize || PosY1 < 0)
        ystep = -ystep;

    // Verifica as bordas.  Se a window for menor e o 
    // quadrado sair do volume de visualização 
    if (posX1 > windowWidth - POSrsize)
        posX1 = windowWidth - POSrsize - 1;

    if (PosY1 > windowHeight - POSrsize)
        PosY1 = windowHeight - POSrsize - 1;

    // Move o quadrado
    posX1 += xstep;
    PosY1 += ystep;
}

void Menu::keyDown(unsigned char key, int x, int y)
{
}
void Menu::desenhaHUD()
{
}
void Menu::keyUp(unsigned char key, int x, int y)
{
	if (optMelhores) {

	}
	else if (optOpcoes) {
		switch (key) {

		}
	}
	else {
		switch (key) {
		case 'O'://Tela de Opções
		case 'o':
			/*EfeitoSonoro::getInstance().playEnterMenu();*/
			optOpcoes = true;
			setaSelectOption = 2;
			break;

		case 13: //ENTER -> Iniciar Jogo
			switch (setaSelectOption)
			{
			//case 1:
			//	/*EfeitoSonoro::getInstance().playEnterMenu();*/
			//	optMelhores = true;
			//	break;
			case 1:
				/*EfeitoSonoro::getInstance().playEnterMenu();*/
				optOpcoes = true;
				break;
			case 2:
				optSair = true;
			default:
				/*EfeitoSonoro::getInstance().playEnterMenu();*/
				optIniciar = true;
				break;
			}
			break;

		}
	}
	//Teclas Gerais
	switch (key)
	{
	case 8:
		optMelhores = false;
		optOpcoes = false;
		break;
	/*case 'F':
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;*/
	default:
		macete += (char)key;
		break;
	}

}

void Menu::specialKeyDown(int key, int x, int y)
{
	if (optOpcoes) {
		
		
	}
}

void Menu::specialKeyUp(int key, int x, int y)
{
	if (optMelhores) {

	}
	else if (optOpcoes) {

	}
	else {

		switch (key)
		{
		case GLUT_KEY_UP: //SETA CIMA
			if (setaSelectOption > 0) {
				setaSelectOption--;
				/*EfeitoSonoro::getInstance().playTransitioningMenu();*/
			}
			break;
		case GLUT_KEY_DOWN: //SETA BAIXO
			if (setaSelectOption < 2) {
				setaSelectOption++;

				/*EfeitoSonoro::getInstance().playTransitioningMenu();*/
			}
			break;
		default:
			break;
		}
	}
}

void Menu::mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Position: (" << x << "," << y << ")" << endl;

		/*if (optMelhores) {
			if ((x > 175 && x < 245) && (y > 500 && y < 560)) {
				optMelhores = false;
			}
		}*/
		/*else*/ if (optOpcoes) {
			if ((x > 35 && x < 104) && (y > 271 && y < 326)) {
				optOpcoes = false;
			}
		}
		else {
			for (int i = 0; i < vetPosMenuElements.size(); i++) {
				float xInit = vetPosMenuElements[i].posInit_X;
				float xEnd = vetPosMenuElements[i].posEnd_X;
				float yInit = vetPosMenuElements[i].posInit_Y;
				float yEnd = vetPosMenuElements[i].posEnd_Y;
				if ((x >= xInit && x <= xEnd) && (y >= yInit && y <= yEnd)) {
					setaSelectOption = i;
					/*EfeitoSonoro::getInstance().playEnterMenu();*/
					switch (i)
					{
					case 0:
						optIniciar = true;
						break;
					/*case 1:
						optMelhores = true;
						break;*/
					case 1:
						optOpcoes = true;
						break;
					case 2:
						optSair = true;
					}
				}
			}
		}
	}
}

// Inicializa parâmetros de rendering
void Menu::inicializa()
{
	//Transparencia
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	EfeitoVisual::getInstance().ortho2D();
	
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//-------------
	/*EfeitoSonoro::getInstance().initAudios_Menu();
	EfeitoSonoro::getInstance().playMainTheme();*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    EfeitoSonoro::getInstance().initAudios_Menu();
    EfeitoSonoro::getInstance().playMainTheme();
}
