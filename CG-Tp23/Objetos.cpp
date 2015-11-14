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