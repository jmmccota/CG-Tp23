#include "EfeitoVisual.hpp"
#include <cmath>
#define FULLHD_ORTHO_X 1000
#define FULLHD_ORTHO_Y 1000


EfeitoVisual::EfeitoVisual()
{
    fullscreen = false;
    sizeX = 1000;
    sizeY = 1000;
}

EfeitoVisual::~EfeitoVisual()
{
}

void EfeitoVisual::ortho2D()
{
    gluOrtho2D(0.0f, FULLHD_ORTHO_X, 0.0f, FULLHD_ORTHO_Y);
}

pair<GLfloat, GLfloat> EfeitoVisual::getOrtho2D()
{
    return pair<GLfloat, GLfloat>(FULLHD_ORTHO_X, FULLHD_ORTHO_Y);
}

bool EfeitoVisual::colisao(Solido *a, Solido *b)
{
	std::tuple<GLfloat, GLfloat, GLfloat> pos1, pos2, tam1, tam2;
	pos1 = a->getPos();
	pos2 = b->getPos();
	tam1 = a->getTam();
	tam2 = b->getTam();
    if ((abs(std::get<0>(pos1) - std::get<0>(pos2)) <= (std::get<0>(tam1) + std::get<0>(tam2))) &&
        (abs(std::get<1>(pos1) - std::get<1>(pos2)) <= (std::get<1>(tam1) + std::get<1>(tam2))) &&
		(abs(std::get<2>(pos1) - std::get<2>(pos2)) <= (std::get<2>(tam1) + std::get<2>(tam2))))
        return true;
    return false;
}

void EfeitoVisual::resize(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    if (w  < h)
        glViewport(0, 0, w, w);
    else
        glViewport(0, 0, h, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    EfeitoVisual::getInstance().sizeX = w;
    EfeitoVisual::getInstance().sizeY = h;
}

void EfeitoVisual::setCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluPerspective(100, 1, 0.1, 500);
	gluLookAt(0, 0, 0, 0, 0, 0, 0, 1, 0);
}

bool EfeitoVisual::isFullScreen()
{
    return fullscreen;
}

pair<GLint, GLint> EfeitoVisual::sizeScreen()
{
    return pair<GLint, GLint>(sizeX, sizeY);
}

pair<double, double> EfeitoVisual::positionScreen(char * type)
{
    pair<double, double> val;
    if (type == "center") {
        val.first = ((GetSystemMetrics(SM_CXSCREEN) - sizeScreen().first) / 2);
        val.second = ((GetSystemMetrics(SM_CYSCREEN) - sizeScreen().second) / 2);
    }
    return val;
}

void EfeitoVisual::setFullScreen()
{
    if (!fullscreen) {
        glutFullScreen();
    }
    else {
        //Default values
        sizeX = 1000;
        sizeY = 1000;
        glutReshapeWindow(sizeX, sizeY);
        pair<int, int> position = positionScreen("center");
        glutInitWindowPosition(position.first, position.second);
    }
    fullscreen = !fullscreen;
}

EfeitoVisual& EfeitoVisual::getInstance()
{
    static EfeitoVisual singleton;
    return singleton;
}
