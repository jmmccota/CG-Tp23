#include "Objetos.hpp"


Bala::Bala(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
    SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/bala.dat");
}
Bala::Bala() : SolidoComposto(nullptr)
{
    this->carrega("models/bala.dat");
}


Bala::~Bala()
{
}

void Bala::acao()
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}
 

Relogio::Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/relogio.dat");
}

Relogio::Relogio() : SolidoComposto(nullptr)
{
    this->carrega("models/relogio.dat");
}

Relogio::~Relogio()
{
}

void Relogio::acao()
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}


Canhao::Canhao(GLfloat posX, GLfloat posY, GLfloat posZ, float escala, Fase* fase) :
SolidoComposto(posX, posY, posZ, escala, fase)
{
    this->carrega("models/Canhao.dat");
}

Canhao::Canhao(Fase* fase) : SolidoComposto(fase)
{
    this->carrega("models/Canhao.dat");
    this->gira(0, 0, 0);
}

Canhao::~Canhao()
{
}

void Canhao::acao()
{
    GLfloat qtd = 0.5;
    if (moveCima)
        gira(qtd, 0, 0);
    else if (moveBaixo)
        gira(-qtd, 0, 0);
    if (moveEsq)
        gira(0, qtd, 0);
    else if (moveDir)
        gira(0, -qtd, 0);
}

void Canhao::keyDown(int value)
{
    switch (value)
    {
        case GLUT_KEY_DOWN:
            moveBaixo = true;
            break;
        case GLUT_KEY_UP:
            moveCima = true;
            break;
        case GLUT_KEY_LEFT:
            moveEsq = true;
            break;
        case GLUT_KEY_RIGHT:
            moveDir = true;
            break;
    }
}

void Canhao::keyUp(int value)
{
    switch (value)
    {
        case GLUT_KEY_DOWN:
            moveBaixo = false;
            break;
        case GLUT_KEY_UP:
            moveCima = false;
            break;
        case GLUT_KEY_LEFT:
            moveEsq = false;
            break;
        case GLUT_KEY_RIGHT:
            moveDir = false;
            break;
        case 'z':{
            GLfloat x = tamZ * sin(-rotY / 180 * 3.141592),
                y = tamZ * sin(rotX / 180 * 3.141592),
                z = -tamZ * cos(-rotY / 180 * 3.141592);

            float multVel = 3;
            Bala *b = new Bala(x, y, z, 0.6);
            b->gira(rotX, rotY, 0);
            b->setVel(std::make_tuple(multVel * (x - posX), multVel * (y - posY), multVel * (z - posZ)));
            b->setAcel(std::make_tuple(0, -0.01, 0));
            fase->novoProjetil(b);
            break;
        }
    }
}