#ifndef OBJETOS_H
#define OBJETOS_H
#include "Solido.hpp"


class Bala : public SolidoComposto
{
	public:
		Bala();
        Bala(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
		~Bala();

		void acao() {}
};

class Relogio : public SolidoComposto
{
public:
    Relogio();
    Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala);
    ~Relogio();

    void acao() {}
};

#endif