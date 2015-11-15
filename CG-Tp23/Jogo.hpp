#ifndef JOGO_H
#define JOGO_H

//60fps
#define TEMPOQUADRO 16
class Jogo;

#include "Solido.hpp"
#include "EfeitoVisual.hpp"
#include "EfeitoSonoro.hpp"
#include "Fase.hpp"
#include "Score.hpp"
#include <vector>


#define JOGO

/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar :
		Jogo::getInstance().FUNCAOQUEEUQUEROCHAMAR(PARAMETROS);
		...
	Porque:
		1 - Somente uma instancia pode existir para que as informacoes
			de estado do jogo sejam consistentes durante o jogo todo.
		2 - Callbacks OpenGL precisam ser estaticas.
			Para chamar uma funcao de um objeto dentro de uma funcao
			estatica e necessario ter uma referencia a essa instancia.
			A propria classe jogo contendo a referencia resolve esse problema.
*/


class Jogo
{
private:

	int proxFase;
	std::vector<Fase*> fases;

	Jogo();
	Jogo(Jogo const&);
	void operator=(Jogo const&);

public:

	~Jogo();
	static Jogo& getInstance();

	//Armazena o valor do frame
	bool pausado = false;
	int estado = 0;
	int controlaScore = 10000;
	void setControlaScore();
	void zeraControlaScore();
	int getControlaScore();
	//Armazena a pontuacao do jogador
	Score *score;;
	
	//Callbacks OpenGL
	static void mouse(int button, int state, int x, int y);
	static void keyDown(unsigned char key, int x, int y);
	static void keyUp(unsigned char key, int x, int y);
	static void specialKeyDown(int key, int x, int y);
	static void specialKeyUp(int key, int x, int y);
	static void draw();

	static void timer(int value);

	void run();
	void inicializa(int fase);
	void setProxFase(int p);
	void proximaFase();
	void fimJogo();
};

#endif
