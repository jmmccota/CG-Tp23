#ifndef OBJETOS_H
#define OBJETOS_H

class Bala;
class Relogio;
class Canhao;

#include "Solido.hpp"


class Bala : public SolidoComposto
{
	public:
		Bala();
        Bala(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
		~Bala();

        void acao();
};

///////////////////////////////////////////////////////////////////////

class Relogio : public SolidoComposto
{
    public:
        Relogio();
        Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
        ~Relogio();

        void acao();
};

///////////////////////////////////////////////////////////////////////

class Canhao : public SolidoComposto
{
    protected:
        bool moveCima = false, moveBaixo = false, 
             moveEsq = false, moveDir = false;

    public:
        Canhao(Fase* fase);
        Canhao(GLfloat posX, GLfloat posY, GLfloat posZ, float escala, Fase* fase);
        ~Canhao();

        void acao();
        void keyDown(int value);
        void keyUp(int value);
};

#endif