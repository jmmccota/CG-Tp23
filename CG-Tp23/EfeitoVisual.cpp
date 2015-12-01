#include "EfeitoVisual.hpp"
#include <cmath>
#define FULLHD_ORTHO_X 700
#define FULLHD_ORTHO_Y 700


EfeitoVisual::EfeitoVisual()
{
    fullscreen = false;
    sizeX = FULLHD_ORTHO_X;
    sizeY = FULLHD_ORTHO_Y;
}

EfeitoVisual::~EfeitoVisual()
{
}

void EfeitoVisual::carregaTexturas_FaseCanhao()
{
    glEnable(GL_TEXTURE_2D);
    texturaBala = SOIL_load_OGL_texture("textures/bala.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturaRelogio = SOIL_load_OGL_texture("textures/relogio.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturaSuperRelogio = SOIL_load_OGL_texture("textures/superRelogio.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturaSilvio = SOIL_load_OGL_texture("textures/silvio.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturaMoises = SOIL_load_OGL_texture("textures/moises.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturaCanhao = SOIL_load_OGL_texture("textures/canhao.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

void EfeitoVisual::ortho2D()
{
    gluOrtho2D(0.0f, FULLHD_ORTHO_X, 0.0f, FULLHD_ORTHO_Y);
}

pair<GLfloat, GLfloat> EfeitoVisual::getOrtho2D()
{
    return pair<GLfloat, GLfloat>(FULLHD_ORTHO_X, FULLHD_ORTHO_Y);
}

bool EfeitoVisual::colisao(SolidoComposto *a, SolidoComposto *b)
{
	std::tuple<GLfloat, GLfloat, GLfloat> pos1, pos2, tam1, tam2;
	pos1 = a->getPos();
    pos2 = b->getPos();
	tam1 = a->calculaTamanho();
	tam2 = b->calculaTamanho();

    if ((abs(std::get<0>(pos1) - std::get<0>(pos2)) <= (std::get<0>(tam1) +std::get<0>(tam2))) &&
        (abs(std::get<1>(pos1) - std::get<1>(pos2)) <= (std::get<1>(tam1) +std::get<1>(tam2))) &&
        (abs(std::get<2>(pos1) - std::get<2>(pos2)) <= (std::get<2>(tam1) +std::get<2>(tam2))))
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

    EfeitoVisual::getInstance().sizeX = w;
    EfeitoVisual::getInstance().sizeY = h;
}

void EfeitoVisual::setCamera()
{
	//gluPerspective(100, 1, 0.1, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(EfeitoVisual::getInstance().posX - 0.1, EfeitoVisual::getInstance().posX + 0.1,
              EfeitoVisual::getInstance().posX - 0.1, EfeitoVisual::getInstance().posX + 0.1,
              0.1, 2100);

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(EfeitoVisual::getInstance().posX, EfeitoVisual::getInstance().posY,
              EfeitoVisual::getInstance().posZ, EfeitoVisual::getInstance().posX,
              EfeitoVisual::getInstance().posY, EfeitoVisual::getInstance().posZ - 0.1, 0.0, 1.0, 0.0);
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
        sizeX = FULLHD_ORTHO_X;
        sizeY = FULLHD_ORTHO_Y;
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
