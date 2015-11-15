#include "Solido.hpp"

class Fase;

#ifdef SOLIDO

#ifndef FASE_H
#define FASE_H

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Jogo.hpp"
#include "EfeitoVisual.hpp"
#include "EfeitoSonoro.hpp"
#include "Solido.hpp"
#include <list>
#include <vector>


/*
	Classe abstrata para servir como "interface" para
		as telas do jogo.
*/


#define FASE


class Fase
{
	protected:

		//Personagem jogavel
        SolidoComposto *principal;

        //Lista de inimigos que apareceram na tela
        std::list<SolidoComposto*> inimigos;

        //Lista de projeteis que apareceram na tela
        std::list<SolidoComposto*> projeteis;

	public:
        Fase();

		//Limpa memoria alocada dinamicamente
		virtual ~Fase();

		//Inicializa o personagem principal e a fila de inimigos
		virtual void definePersonagens() = 0;

		//Desenha o fundo da fase na tela
        virtual void desenhaBackground() = 0;
		
		//Desenha a interface (hp, municao, tempo, score, ...)
        virtual void desenhaHUD() = 0;

        //Coloca a iluminacao do cenario
        virtual void insereLuzes() = 0;

		//Desenha todos os elementos da fase na tela
		virtual void desenha() = 0;

		//Define se a fase foi encerrada
		//	Caso tenha sido desvia o fluxo para a funcao que define as fases
		virtual void terminou() = 0;

		//Define quais alteracoes devem ser feitas do frame anterior
		//para o frame atual e chama a funcao de desenho
        virtual void atualiza(int value) = 0;

        //Faz os tratamentos necessarios caso haja um clique do mouse
        virtual void mouse(int button, int state, int x, int y) = 0;

        //Faz os tratamentos necessarios caso seja pressionada uma tecla
        //  do teclado
        virtual void keyDown(unsigned char key, int x, int y) = 0;

        //Faz os tratamentos necessarios caso seja solta uma tecla
        //  do teclado
        virtual void keyUp(unsigned char key, int x, int y) = 0;

        //Faz os tratamentos necessarios caso seja pressionada uma tecla
        //  especial do teclado
        virtual void specialKeyDown(int key, int x, int y) = 0;

        //Faz os tratamentos necessarios caso seja solta uma tecla
        //  especial do teclado
        virtual void specialKeyUp(int key, int x, int y) = 0;

        //Realiza chamada para definePersonagens e glSetup
        virtual void inicializa() = 0;

        //Insere um novo projetil na fase
        void novoProjetil(SolidoComposto *p);
		
        void reseta();
};

//Incluir todas as fases do jogo
#include "Solido.hpp"
#include "Fase_Canhao.hpp"


#endif
 
#endif