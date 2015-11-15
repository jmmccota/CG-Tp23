#ifndef FASE_CANHAO
#define FASE_CANHAO

#include "Fase.hpp"
#include "Objetos.hpp"
#include <SOIL.h>

class Fase_Canhao : public Fase
{
    protected:
        Canhao* principal;
		GLuint texturas[5];

	public:
		Fase_Canhao();
		~Fase_Canhao();

		void definePersonagens();

		void desenhaBackground();

		void desenhaHUD();

        void insereLuzes();

		void desenha();

		void terminou();

		void atualiza(int value);


		void mouse(int button, int state, int x, int y);
		void keyDown(unsigned char key, int x, int y);
		void keyUp(unsigned char key, int x, int y);
		void specialKeyDown(int key, int x, int y);
		void specialKeyUp(int key, int x, int y);


		virtual void inicializa();
};

#endif