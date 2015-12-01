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
        inline int getPontos() { return 0; }
};

///////////////////////////////////////////////////////////////////////

class Relogio : public SolidoComposto
{
    public:
        Relogio();
        Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
        ~Relogio();

        void acao();
        inline int getPontos() { return 10; }
};

///////////////////////////////////////////////////////////////////////

class SuperRelogio : public SolidoComposto
{
public:
    SuperRelogio();
    SuperRelogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
    ~SuperRelogio();

    void acao();
    inline int getPontos() { return 100; }
};

///////////////////////////////////////////////////////////////////////

class Silvio : public SolidoComposto
{
public:
    Silvio();
    Silvio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
    ~Silvio();

    void acao();
    inline int getPontos() { return 1000000; }
};

///////////////////////////////////////////////////////////////////////

class Moises : public SolidoComposto
{
public:
    Moises();
    Moises(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
    ~Moises();

    void acao();
    tuple<GLfloat, GLfloat, GLfloat> calculaTamanho();
    inline int getPontos() { return 1; }
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
        inline int getPontos() { return 0; }
};

#endif