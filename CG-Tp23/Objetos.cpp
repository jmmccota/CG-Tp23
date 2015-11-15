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
    int qtd = 3;
    switch (value)
    {
        case GLUT_KEY_UP:
            gira(qtd, 0, 0);
            break;
        case GLUT_KEY_DOWN:
            gira(-qtd, 0, 0);
            break;
        case GLUT_KEY_RIGHT:
            gira(0, -qtd, 0);
            break;
        case GLUT_KEY_LEFT:
            gira(0, qtd, 0);
            break;
        //case ' ':{
        //    GLfloat x = tamX, y = tamY, z = tamZ,
        //            rX = rotX / 180 * 3.141592, rY = rotY / 180 * 3.141592, rZ = rotZ / 180 * 3.141592,
        //            xi, yi, zi;

        //    //Calcula posicao ponta
        //    xi = z * cos(1.57079 + rY)

        //    Bala b = new Bala();
        //        break;
        //}
    }
}