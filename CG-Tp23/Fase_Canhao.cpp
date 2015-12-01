#include "Fase_Canhao.hpp"


#define TEXTURA_CENTRO 0
#define TEXTURA_DIREITA 1
#define TEXTURA_CIMA 2
#define TEXTURA_ESQUERDA 3
#define TEXTURA_BAIXO 4

static float fog_color[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat fog = 0.0002;


namespace gambi
{
    GLfloat x[2] = { 100, -100 };
    GLfloat z[6] = { -50, -100, -150, -200, -250, -300 };
}


Fase_Canhao::Fase_Canhao(Jogo *jogo) : Fase(jogo)
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
	glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_CENTRO]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1000, 1000, -2000);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1000, -1000, -2000);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1000, -1000, -2000);
	glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1000, 1000, -2000);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_DIREITA]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1000, 1000, 0);
	glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1000, 1000, -2000);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1000, -1000, -2000);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1000, -1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_ESQUERDA]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1000, 1000, 0);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1000, 1000, -2000);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1000, -1000, -2000);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1000, -1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_CIMA]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1000, 1000, 0);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1000, 1000, -2000);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1000, 1000, -2000);
	glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1000, 1000, 0);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, texturas[TEXTURA_BAIXO]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1000, -1000, 0);
	glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1000, -1000, -2000);
	glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1000, -1000, -2000);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1000, -1000, 0);
    glEnd();
}

void Fase_Canhao::desenhaHUD()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    EfeitoVisual::getInstance().ortho2D();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);

    glRasterPos2f(600, 650);
    FuncoesAuxiliares::writeWord_BITMAP(std::to_string(Jogo::getInstance().controlaScore), GLUT_BITMAP_TIMES_ROMAN_24);
}

void Fase_Canhao::insereLuzes()
{
    GLfloat luzAmbiente[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 };	   // "cor" 
    GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 
    GLfloat posicaoLuz[4] = { 990.0, 0.0, 0.0, 0.0 };
    GLfloat posicaoLuz2[4] = { -990.0, 0.0, 0.0, 0.0 };
    GLfloat posicaoLuz3[4] = { 0.0, 990.0, 0.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    // Ativa o uso da luz ambiente 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
    // Define os parâmetros da luz de número 1
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz2);
    // Define os parâmetros da luz de número 2
    glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz3);

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita a luz de número 1
    glEnable(GL_LIGHT1);
    // Habilita a luz de número 2
    glEnable(GL_LIGHT2);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, fog);
	glFogfv(GL_FOG_COLOR, fog_color);
}

void Fase_Canhao::desenha()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    EfeitoVisual::getInstance().setCamera();
    insereLuzes();

    desenhaBackground();

	for (auto i = inimigos.begin(); i != inimigos.end(); ++i)
		(*i)->desenha();

	for (auto i = projeteis.begin(); i != projeteis.end(); ++i)
        (*i)->desenha();

    principal->desenha();
	glFogf(GL_FOG_DENSITY, fog);

    desenhaHUD();

	glutSwapBuffers();
}

void Fase_Canhao::terminou()
{
    jogo->setProxFase(0);
    jogo->proximaFase();
}

void Fase_Canhao::atualiza(int value)
{

    if (contAnimacao == 450)
    {
        terminou();
    }
    else if (contAnimacao == 300)
    {
        projeteis.push_back(new Moises(0, 0, -90, 27));
        EfeitoSonoro::getInstance().playAnimacao();
    }
    
    if (nObjetosDestruidos >= 100)
    {
        contAnimacao++;
    }

    if (principal->contadorRecuo != 0)
    {
        principal->contadorRecuo++;
        if (principal->contadorRecuo == 15)
        {
            principal->setPos(make_tuple(0, 0, 0));
            principal->contadorRecuo = 0;
        }
    }
        
    principal->acao();

    //insere novos tiros
    if (rand() % (2000 / TEMPOQUADRO) == 0 && nObjetosCriados < 100)
    {
        nObjetosCriados++;
        GLfloat x = gambi::x[rand() % 2];
        GLfloat z = gambi::z[rand() % 6];
        if (rand() % 10 == 0)
        {
            inimigos.push_back(new SuperRelogio(x, -50 + z, z, 3));
            inimigos.back()->setVel(std::make_tuple(-x / (rand() % 100 + 20), 4, z / (rand() % 100 + 20)));
            inimigos.back()->setAcel(std::make_tuple(0, -0.02, 0));
        }
        else if (rand() % 20 == 0)
        {
            inimigos.push_back(new Silvio(x, -50 + z, z, 3));
            inimigos.back()->gira(-90, 0, 0);
            inimigos.back()->setVel(std::make_tuple(-x / (rand() % 100 + 20), 4, z / (rand() % 150 + 30)));
            inimigos.back()->setAcel(std::make_tuple(0, -0.02, 0));
        }
        else if (rand() % 15 == 0)
        {
            inimigos.push_back(new Moises(x, -50 + z, z, 6));
            inimigos.back()->setVel(std::make_tuple(-x / (rand() % 50 + 10) / 2, 2.5, z / (rand() % 50 + 10) / 2));
            inimigos.back()->setAcel(std::make_tuple(0, -0.01, 0));
            inimigos.back()->gira(0, (x > 0 ? -45 : 45), 0);
        }
        else
        {
            inimigos.push_back(new Relogio(x, -50 + z, z, 10));
            inimigos.back()->setVel(std::make_tuple(-x / (rand() % 100 + 20), 4, z / (rand() % 100 + 20)));
            inimigos.back()->setAcel(std::make_tuple(0, -0.02, 0));
            inimigos.back()->gira(0, (x > 0 ? -45 : 45), 0);
        }
    }

    //remocao de coisas fora da tela
    for (auto i = inimigos.begin(); i != inimigos.end();)
    {
        auto pos = (*i)->getPos();

        if (abs(std::get<0>(pos)) > 1000 ||
            abs(std::get<1>(pos)) > 1000 ||
            std::get<2>(pos) > 2000)
        {
            i = inimigos.erase(i);
            nObjetosDestruidos++;
        }
        else
        {
            (*i)->acao();
            i++;
        }
    }
    for (auto i = projeteis.begin(); i != projeteis.end();)
    {
        auto pos = (*i)->getPos();

        if (abs(std::get<0>(pos)) > 1000 ||
            abs(std::get<1>(pos)) > 1000 ||
            std::get<2>(pos) > 2000)
        {
            i = projeteis.erase(i);
        }
        else
        {
            (*i)->acao();
            i++;
        }
    }


    //Deteccao de colisoes

    for (auto i = projeteis.begin(); i != projeteis.end();)
    {
        bool destruiu = false;
        for (auto j = inimigos.begin(); j != inimigos.end();)
        {
            if (EfeitoVisual::getInstance().colisao(*i, *j))
            {
                jogo->controlaScore += (*j)->getPontos();
                i = projeteis.erase(i);
                j = inimigos.erase(j);
                destruiu = true;
                nObjetosDestruidos++;
                break;
            }
            else
                ++j;
        }
        if (!destruiu)
            ++i;
    }
}

void Fase_Canhao::mouse(int button, int state, int x, int y)
{
}

void Fase_Canhao::keyDown(unsigned char key, int x, int y)
{
    switch (key){
        default:
            principal->keyDown(key);
            break;
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
		case '+':
			fog = fog * 1.1;
			break;
		case '-':
			fog = fog / 1.1;
			break;
    }
}

void Fase_Canhao::keyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            terminou();
            break;
        default:
            principal->keyUp(key);
            break;
    }
}

void Fase_Canhao::specialKeyDown(int key, int x, int y)
{
    principal->keyDown(key);
}

void Fase_Canhao::specialKeyUp(int key, int x, int y)
{
    switch (key)
    {
        case 27: //Tecla ESC -> Volta para o menu
            jogo->setProxFase(0);
            jogo->proximaFase();
            break;
        default:
            principal->keyUp(key);
            break;
    }
}

void Fase_Canhao::inicializa()
{
    
    
	/*glEnable(GL_TEXTURE_2D);
	glGenTextures(1, texturas);
	texturas[TEXTURA_CENTRO] = SOIL_load_OGL_texture("textures/center.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_DIREITA] = SOIL_load_OGL_texture("textures/right.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_CIMA] = SOIL_load_OGL_texture("textures/top.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_ESQUERDA] = SOIL_load_OGL_texture("textures/left.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_BAIXO] = SOIL_load_OGL_texture("textures/bottom.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glClearDepth(1.0);*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    insereLuzes();

	glEnable(GL_TEXTURE_2D);
	//glGenTextures(1, texturas);
	texturas[TEXTURA_CENTRO] = SOIL_load_OGL_texture("textures/center.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_DIREITA] = SOIL_load_OGL_texture("textures/right.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_CIMA] = SOIL_load_OGL_texture("textures/top.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_ESQUERDA] = SOIL_load_OGL_texture("textures/left.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texturas[TEXTURA_BAIXO] = SOIL_load_OGL_texture("textures/bottom.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	/*glClearColor(0.0, 0.0, 1.0, 1.0);
	glClearDepth(1.0);*/
   

    std::srand(time(NULL));

    jogo->controlaScore = 0;

    EfeitoSonoro::getInstance().initAudios_Canhao();
    EfeitoSonoro::getInstance().playMainTheme();

    principal = new Canhao(0, 0, 0, 0.5, this);
}
 