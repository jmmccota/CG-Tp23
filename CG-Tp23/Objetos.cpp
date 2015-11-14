#include "Objetos.hpp"


Bala::Bala(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
    SolidoComposto(posX, posY, posZ, escala)
{
    this->carrega("models/bala.dat");
}
Bala::Bala()
{
    this->carrega("models/bala.dat");
}


Bala::~Bala()
{
}
 

Relogio::Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala)
{
    this->carrega("models/relogio.dat");
}

Relogio::Relogio()
{
    this->carrega("models/relogio.dat");
}

Relogio::~Relogio()
{
}

void Relogio::acao(int value)
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}


Canhao::Canhao(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala)
{
    this->carrega("models/Canhao.dat");
}

Canhao::Canhao()
{
    this->carrega("models/Canhao.dat");
    this->gira(0, 0, 0);
}

Canhao::~Canhao()
{
}

void Canhao::acao(int value)
{
    switch (value)
    {
        case GLUT_KEY_UP:
            gira(1, 0, 0);
            break;
        case GLUT_KEY_DOWN:
            gira(-1, 0, 0);
            break;
        case GLUT_KEY_RIGHT:
            gira(0, 1, 0);
            break;
        case GLUT_KEY_LEFT:
            gira(0, -1, 0);
            break;
    }
}