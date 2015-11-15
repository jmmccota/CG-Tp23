#include "Fase_Canhao.hpp"

#define TEXTURA_CENTRO 0
#define TEXTURA_DIREITA 1
#define TEXTURA_CIMA 2
#define TEXTURA_ESQUERDA 3
#define TEXTURA_BAIXO 4

namespace gambi
{
    GLfloat x[2] = { 100, -100 };
    GLfloat z[4] = { -50, -100, -150, -200 };
}


Fase_Canhao::Fase_Canhao()
{
}

Fase_Canhao::~Fase_Canhao()
{
}

void Fase_Canhao::definePersonagens()
{
}

void Fase_Canhao::desenhaBackground()
{

    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_CENTRO]);
    glBegin(GL_QUADS);
    glVertex3f(1000, 1000, -2000);
    glVertex3f(1000, -1000, -2000);
    glVertex3f(-1000, -1000, -2000);
    glVertex3f(-1000, 1000, -2000);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_DIREITA]);
    glBegin(GL_QUADS);
    glVertex3f(1000, 1000, 0);
    glVertex3f(1000, 1000, -2000);
    glVertex3f(1000, -1000, -2000);
    glVertex3f(1000, -1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_ESQUERDA]);
    glBegin(GL_QUADS);
    glVertex3f(-1000, 1000, 0);
    glVertex3f(-1000, 1000, -2000);
    glVertex3f(-1000, -1000, -2000);
    glVertex3f(-1000, -1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_CIMA]);
    glBegin(GL_QUADS);
    glVertex3f(1000, 1000, 0);
    glVertex3f(1000, 1000, -2000);
    glVertex3f(-1000, 1000, -2000);
    glVertex3f(-1000, 1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_BAIXO]);
    glBegin(GL_QUADS);
    glVertex3f(1000, -1000, 0);
    glVertex3f(1000, -1000, -2000);
    glVertex3f(-1000, -1000, -2000);
    glVertex3f(-1000, -1000, 0);
    glEnd();
}

void Fase_Canhao::desenhaHUD()
{
}

void Fase_Canhao::insereLuzes()
{

}

void Fase_Canhao::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    EfeitoVisual::getInstance().setCamera();

    desenhaBackground();

	for (auto i = inimigos.begin(); i != inimigos.end(); i++)
		(*i)->desenha();

	for (auto i = projeteis.begin(); i != projeteis.end(); i++)
        (*i)->desenha();

    principal->desenha();

	glutSwapBuffers();
}

void Fase_Canhao::terminou()
{
}

void Fase_Canhao::atualiza(int value)
{
    for (auto i = inimigos.begin(); i != inimigos.end(); i++)
        (*i)->acao(0);

    for (auto i = projeteis.begin(); i != projeteis.end(); i++)
        (*i)->acao(0);



    //Remove coisas inativas
}

void Fase_Canhao::mouse(int button, int state, int x, int y)
{
}

void Fase_Canhao::keyDown(unsigned char key, int x, int y)
{
    switch (key){
        case '1':
            EfeitoVisual::getInstance().posX++;
            break;
        case '2':
            EfeitoVisual::getInstance().posX--;
            break;
        case '3':
            EfeitoVisual::getInstance().posY++;
            break;
        case '4':
            EfeitoVisual::getInstance().posY--;
            break;
        case '5':
            EfeitoVisual::getInstance().posZ++;
            break;
        case '6':
            EfeitoVisual::getInstance().posZ--;
            break;
        case 'P':
        case 'p':
            rand();
            GLfloat x = gambi::x[rand() % 2];
            GLfloat z = gambi::z[rand() % 4];
            inimigos.push_back(new Relogio(x, -50 + z, z, 1));
            inimigos.back()->setVel(std::make_tuple(-x / (rand() % 100 + 20), 4, z / (rand() % 100 + 20)));
            inimigos.back()->setAcel(std::make_tuple(0, -0.02, 0));
            break;
    }
}

void Fase_Canhao::keyUp(unsigned char key, int x, int y)
{
}

void Fase_Canhao::specialKeyDown(int key, int x, int y)
{
    principal->acao(key);
}

void Fase_Canhao::specialKeyUp(int key, int x, int y)
{
}

void Fase_Canhao::inicializa()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, texturas);
    texturas[TEXTURA_CENTRO] = SOIL_load_OGL_texture("textures/center.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturas[TEXTURA_DIREITA] = SOIL_load_OGL_texture("textures/right.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturas[TEXTURA_CIMA] = SOIL_load_OGL_texture("textures/top.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturas[TEXTURA_ESQUERDA] = SOIL_load_OGL_texture("textures/left.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texturas[TEXTURA_BAIXO] = SOIL_load_OGL_texture("textures/bottom.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    principal = new Canhao(0, -2, 0, 1);
    srand(time(NULL));
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClearDepth(1.0);
}
 