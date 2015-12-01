#include "Objetos.hpp"


#pragma region Bala
Bala::Bala(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
    SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/bala.dat", EfeitoVisual::getInstance().texturaBala);
}
Bala::Bala() : SolidoComposto(nullptr)
{
    this->carrega("models/bala.dat", EfeitoVisual::getInstance().texturaBala);
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
#pragma endregion

///////////////////////////////////////////////////////////////////////
 
#pragma region Relogio
Relogio::Relogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/relogio.dat", EfeitoVisual::getInstance().texturaRelogio);
}

Relogio::Relogio() : SolidoComposto(nullptr)
{
    this->carrega("models/relogio.dat", EfeitoVisual::getInstance().texturaRelogio);
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
#pragma endregion

///////////////////////////////////////////////////////////////////////

#pragma region SuperRelogio
SuperRelogio::SuperRelogio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/superRelogio.dat", EfeitoVisual::getInstance().texturaSuperRelogio);
}

SuperRelogio::SuperRelogio() : SolidoComposto(nullptr)
{
    this->carrega("models/superRelogio.dat", EfeitoVisual::getInstance().texturaSuperRelogio);
}

SuperRelogio::~SuperRelogio()
{
}

void SuperRelogio::acao()
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}
#pragma endregion

///////////////////////////////////////////////////////////////////////

#pragma region Silvio
Silvio::Silvio(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/silvio.dat", EfeitoVisual::getInstance().texturaSilvio);
}

Silvio::Silvio() : SolidoComposto(nullptr)
{
    this->carrega("models/silvio.dat", EfeitoVisual::getInstance().texturaSilvio);
}

Silvio::~Silvio()
{
}

void Silvio::acao()
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}
#pragma endregion

///////////////////////////////////////////////////////////////////////

#pragma region Moises
Moises::Moises(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) :
SolidoComposto(posX, posY, posZ, escala, nullptr)
{
    this->carrega("models/moises.dat", EfeitoVisual::getInstance().texturaMoises);
}

Moises::Moises() : SolidoComposto(nullptr)
{
    this->carrega("models/moises.dat", EfeitoVisual::getInstance().texturaMoises);
    this->tamX = 0;
    this->tamY = 0;
    this->tamZ = 0;
}

Moises::~Moises()
{
}

void Moises::acao()
{
    posX += velX;
    velX += acelX;
    posY += velY;
    velY += acelY;
    posZ += velZ;
    velZ += acelZ;
}

tuple<GLfloat, GLfloat, GLfloat> Moises::calculaTamanho()
{
    return make_tuple(0, 0, 0);
}
#pragma endregion

///////////////////////////////////////////////////////////////////////

#pragma region Canhao
Canhao::Canhao(GLfloat posX, GLfloat posY, GLfloat posZ, float escala, Fase* fase) :
SolidoComposto(posX, posY, posZ, escala, fase)
{
    this->carrega("models/Canhao.dat", EfeitoVisual::getInstance().texturaCanhao);
}

Canhao::Canhao(Fase* fase) : SolidoComposto(fase)
{
    this->carrega("models/Canhao.dat", EfeitoVisual::getInstance().texturaCanhao);
    this->gira(0, 0, 0);
}

Canhao::~Canhao()
{
}

void Canhao::acao()
{
    GLfloat qtd = 0.5, limite = 30;
    if (moveCima && rotX < limite)
        gira(qtd, 0, 0);
    else if (moveBaixo && rotX > -limite)
        gira(-qtd, 0, 0);
    if (moveEsq && rotY < limite)
        gira(0, qtd, 0);
    else if (moveDir && rotY > -limite)
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
        case 'Z':
        case 'z':{
            EfeitoSonoro::getInstance().playCannon();
            GLfloat x = tamZ * sin(-rotY / 180 * 3.141592) / 2,
                y = tamZ * sin(rotX / 180 * 3.141592) / 2,
                z = (-tamZ * cos(-rotY / 180 * 3.141592)) / 2;

            float multVel = 20;
            Bala *b = new Bala(x, y, z, 0.7);
            b->gira(rotX - 90, 0, rotY);
            b->setVel(std::make_tuple(multVel * (x - posX), multVel * (y - posY), multVel * (z - posZ)));
            b->setAcel(std::make_tuple(0, -0.01, 0));
            fase->novoProjetil(b);

            //Animacao
            this->setPos(make_tuple(-sin(-rotY / 180 * 3.141592)/5, 
                                    -sin(rotX / 180 * 3.141592)/5, 
                                    tamZ * cos(-rotY / 180 * 3.141592)/5));
            contadorRecuo = 1;

            break;
        }
    }
}
#pragma endregion
 