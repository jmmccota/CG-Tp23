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
void EfeitoVisual::desenhaTitulo(int posX, int posY)
{

	glColor3f(0, 1.0, 1.0);
	int x1 = 43 + posX, y1 = 20 + posY;

	//J
	FuncoesAuxiliares::bresenham(x1, 750 + y1 + 80, x1, 660 + y1); //  |
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1 - 100, 698 + y1); //i 
	FuncoesAuxiliares::bresenham(x1 - 100, 698 + y1, x1 - 70, 698 + y1);//-
	FuncoesAuxiliares::bresenham(x1 - 70, 698 + y1, x1 - 70, 680 + y1);//'
	FuncoesAuxiliares::bresenham(x1 - 70, 680 + y1, x1 - 28, 680 + y1);//---
	FuncoesAuxiliares::bresenham(x1 - 28, 680 + y1, x1 - 28, 750 + y1 + 80);// I
	FuncoesAuxiliares::bresenham(x1 - 28, 750 + y1 + 80, x1, 750 + y1 + 80); //-

	x1 -= 5;																		 //I
	FuncoesAuxiliares::bresenham(x1 + 15, 750 + y1 + 80, x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 45, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 15, 750 + y1 + 80);

	//R
	x1 += 10;
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 45, 660 + y1); //|
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 145, 750 + y1 + 80);//- em cima
	FuncoesAuxiliares::bresenham(x1 + 145, 750 + y1 + 80, x1 + 145, 700 + y1 + 30);// ' ate o meio
	FuncoesAuxiliares::bresenham(x1 + 145, 700 + y1 + 30, x1 + 70, 700 + y1 + 30);// - ate o meio do R
	FuncoesAuxiliares::bresenham(x1 + 70, 700 + y1 + 30, x1 + 145, 660 + y1);// \ate o fim do r
	FuncoesAuxiliares::bresenham(x1 + 145, 660 + y1, x1 + 115, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 115, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 70, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 660 + y1, x1 + 45, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 75 + 5, 715 + y1 + 40, x1 + 112, 715 + y1 + 40);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 112, 715 + y1 + 40, x1 + 112, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(x1 + 112, 740 + y1 + 50, x1 + 75 + 5, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(x1 + 75 + 5, 740 + y1 + 50, x1 + 75 + 5, 715 + y1 + 40);//
																						 //A
																						 //A
	x1 += 45;
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

	//Y
	x1 += 60;
	FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 190 + 20, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 190 + 20, 660 + y1, x1 + 280, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 280, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 193, 705 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 705 + y1, x1 + 170, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 170, 750 + y1 + 80, x1 + 195, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 195, 750 + y1 + 80, x1 + 213, 718 + y1 + 35);
	FuncoesAuxiliares::bresenham(x1 + 213, 718 + y1 + 35, x1 + 245, 750 + y1 + 80);

	//A
	x1 += 180;
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

	//'
	x1 += 10;
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 720 + y1 + 70);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 720 + y1 + 70, x1 + 245, 750 + y1 + 80);

	//s
	x1 -= 70;
	FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 355, 718 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 355, 718 + y1 + 30, x1 + 355, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 355, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 300, 683 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 315, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 315, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 355, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 355, 660 + y1, x1 + 300, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 300, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 340, 671 + y1);
	FuncoesAuxiliares::bresenham(x1 + 340, 683 + y1 + 15, x1 + 340, 671 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 683 + y1 + 15, x1 + 340, 683 + y1 + 15);

	//fly	
	//f
	int y2 = -70 + posY;
	x1 = 50 + posX;
	FuncoesAuxiliares::bresenham(x1 + 160, 685 + y2, x1 + 160, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 160, 730 + y2, x1 + 190, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 190, 730 + y2, x1 + 190, 720 + y2);
	FuncoesAuxiliares::bresenham(x1 + 190, 720 + y2, x1 + 170, 720 + y2);
	FuncoesAuxiliares::bresenham(x1 + 170, 720 + y2, x1 + 170, 710 + y2);
	FuncoesAuxiliares::bresenham(x1 + 170, 710 + y2, x1 + 180, 710 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 710 + y2, x1 + 180, 703 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 703 + y2, x1 + 170, 703 + y2);
	FuncoesAuxiliares::bresenham(x1 + 170, 703 + y2, x1 + 170, 685 + y2);
	FuncoesAuxiliares::bresenham(x1 + 160, 685 + y2, x1 + 170, 685 + y2);	

	////l
	FuncoesAuxiliares::bresenham(x1 + 200, 685 + y2, x1 + 200, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 200, 685 + y2, x1 + 225, 685 + y2);
	FuncoesAuxiliares::bresenham(x1 + 225, 685 + y2, x1 + 225, 695 + y2);
	FuncoesAuxiliares::bresenham(x1 + 225, 695 + y2, x1 + 210, 695 + y2);
	FuncoesAuxiliares::bresenham(x1 + 210, 695 + y2, x1 + 210, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 200, 730 + y2, x1 + 210, 730 + y2);
	//Y
	x1 += 60;
	FuncoesAuxiliares::bresenham(x1 + 175, 685 + y2, x1 + 185, 685 + y2);
	FuncoesAuxiliares::bresenham(x1 + 185, 685 + y2, x1 + 205, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 205, 730 + y2, x1 + 195, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 175, 685 + y2, x1 + 185, 707 + y2);
	FuncoesAuxiliares::bresenham(x1 + 185, 707 + y2, x1 + 172, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 172, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 190, 715 + y2);
	FuncoesAuxiliares::bresenham(x1 + 195, 730 + y2, x1 + 190, 715 + y2);
	/*FuncoesAuxiliares::bresenham(x1 + 195, 635 + y2, x1 + 230, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 210, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 193, 680 + y2);
	FuncoesAuxiliares::bresenham(x1 + 193, 680 + y2, x1 + 165, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 165, 730 + y2, x1 + 180, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 198, 698 + y2);
	FuncoesAuxiliares::bresenham(x1 + 198, 698 + y2, x1 + 210, 730 + y2);*/
	//mudar cor
	x1 += 10;
	glBegin(GL_QUADS);
	glVertex2d(x1+220,y2+730);
	glVertex2d(x1 + 250, y2 + 730);
	glVertex2d(x1 + 250, y2 + 723);
	glVertex2d(x1 + 220, y2 + 723);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2d(x1 + 242, y2 + 730);
	glVertex2d(x1 + 250, y2 + 730);
	glVertex2d(x1 + 250, y2 + 707);
	glVertex2d(x1 + 242, y2 + 707);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2d(x1 + 220, y2 + 712);
	glVertex2d(x1 + 250, y2 + 712);
	glVertex2d(x1 + 250, y2 + 705);
	glVertex2d(x1 + 220, y2 + 705);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2d(x1 + 220, y2 + 710);
	glVertex2d(x1 + 227, y2 + 710);
	glVertex2d(x1 + 227, y2 + 685);
	glVertex2d(x1 + 220, y2 + 685);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2d(x1 + 220, y2 + 692);
	glVertex2d(x1 + 250, y2 + 692);
	glVertex2d(x1 + 250, y2 + 685);
	glVertex2d(x1 + 220, y2 + 685);
	glEnd();
	
	////y
	//x1 += 115;
	//FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 195, 635 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 195, 635 + y2, x1 + 230, 730 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 210, 730 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 193, 680 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 193, 680 + y2, x1 + 165, 730 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 165, 730 + y2, x1 + 180, 730 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 198, 698 + y2);
	//FuncoesAuxiliares::bresenham(x1 + 198, 698 + y2, x1 + 210, 730 + y2);

	//Circulos com Bresenham
	//glColor3f(1.0, 1.0, 0.0); //amarelo
	//FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 50, 50);
	//glColor3f(0, 0.0, 0.8);
	//FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 45, 40);
	//glColor3f(1.0, 1.0, 1.0);
	//FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 40, 40);
	//glColor3f(1.0, 0.0, 0.0);
	//FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 30, 30);

	//katana
	/*int xk = 540 + posX;
	int yk = 50 + posY;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(-20 + xk, yk + 518);
	glVertex2i(-10 + xk, yk + 498);
	glVertex2i(20 + xk, yk + 528);
	glVertex2i(10 + xk, yk + 548);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(-19 + xk, yk + 518);
	glVertex2i(-11 + xk, yk + 498);
	glVertex2i(19 + xk, yk + 528);
	glVertex2i(11 + xk, yk + 548);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(-8 + xk, yk + 515, 2, 2);
	FuncoesAuxiliares::bresenhamCircle(7 + xk, yk + 530, 2, 2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(27 + xk, yk + 521);
	glVertex2i(7 + xk, yk + 558);
	glVertex2i(14 + xk, yk + 565);
	glVertex2i(35 + xk, yk + 525);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(16 + xk, yk + 521);
	glVertex2i(8 + xk, yk + 558);
	glVertex2i(15 + xk, yk + 565);
	glVertex2i(34 + xk, yk + 525);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(28 + xk, yk + 537);
	glVertex2i(170 + xk, yk + 669);
	glVertex2i(170 + xk, yk + 695);
	glVertex2i(18 + xk, yk + 552);
	glEnd();*/


	//Circulos com Bresenham
	//glColor3f(1.0, 1.0, 0.0); //amarelo
	//FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 90, 90);
	//glColor3f(0, 0.0, 0.8);
	//FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 80, 80);
	//glColor3f(1.0, 1.0, 1.0);
	//FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 40, 40);
	//glColor3f(1.0, 0.0, 0.0);
	//FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 30, 30);

	////katana
	//xk = 170 + posX;
	//yk = 50 + posY;
	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_LINE_LOOP);
	//glVertex2i(20 + xk, yk + 518);
	//glVertex2i(10 + xk, yk + 498);
	//glVertex2i(-20 + xk, yk + 528);
	//glVertex2i(-10 + xk, yk + 548);
	//glEnd();
	//glColor3f(0.0, 0.0, 0.0);
	//glBegin(GL_QUADS);
	//glVertex2i(19 + xk, yk + 518);
	//glVertex2i(11 + xk, yk + 498);
	//glVertex2i(-19 + xk, yk + 528);
	//glVertex2i(-11 + xk, yk + 548);
	//glEnd();
	//glColor3f(1.0, 1.0, 1.0);
	//FuncoesAuxiliares::bresenhamCircle(8 + xk, yk + 515, 2, 2);
	//FuncoesAuxiliares::bresenhamCircle(-7 + xk, yk + 530, 2, 2);
	//glBegin(GL_LINE_LOOP);
	//glVertex2i(-27 + xk, yk + 521);
	//glVertex2i(-7 + xk, yk + 558);
	//glVertex2i(-14 + xk, yk + 565);
	//glVertex2i(-35 + xk, yk + 525);
	//glEnd();
	//glColor3f(0.0, 0.0, 0.0);
	//glBegin(GL_QUADS);
	//glVertex2i(-16 + xk, yk + 521);
	//glVertex2i(-8 + xk, yk + 558);
	//glVertex2i(-15 + xk, yk + 565);
	//glVertex2i(-34 + xk, yk + 525);
	//glEnd();
	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_QUADS);
	//glVertex2i(-28 + xk, yk + 537);
	//glVertex2i(-170 + xk, yk + 669);
	//glVertex2i(-170 + xk, yk + 695);
	//glVertex2i(-18 + xk, yk + 552);
	//glEnd();
}
EfeitoVisual& EfeitoVisual::getInstance()
{
    static EfeitoVisual singleton;
    return singleton;
}
