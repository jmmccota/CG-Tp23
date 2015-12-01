#ifndef EFEITOVISUAL_H
#define EFEITOVISUAL_H

class Explosao;
class EfeitoVisual;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL.h>
#include "Solido.hpp"
#include "EfeitoSonoro.hpp"
#include <tuple>
#include <ctime>

/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar:
		EfeitoVisal::getInstance().FUNCAOQUEEUQUEROCHAMAR(PARAMETROS);
		...
    Porque:
        Somente uma instancia pode existir para que as informacoes
        de estado da tela sejam consistentes durante o jogo todo.

	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/

class EfeitoVisual
{
	private:

		bool fullscreen;
		int sizeX ;
		int sizeY;
		EfeitoVisual();
		EfeitoVisual(EfeitoVisual const&);
		void operator=(EfeitoVisual const&);
		bool isFinish = false;

	public:
        GLfloat posX = 0;
        GLfloat posY = 0.2;
        GLfloat posZ = 0;

        GLuint texturaBala, texturaRelogio, texturaSuperRelogio,
            texturaSilvio, texturaMoises, texturaCanhao;

        void carregaTexturas_FaseCanhao();

		~EfeitoVisual();
		
		//Funcoes de configuracoes basicas
		void ortho2D();

		//Pegar os valores do ortho2D: First = Eixo X; Second = Eixo Y;
		pair<float, float> getOrtho2D();

		//Retorna true caso objetos tenham colidido, false caso contrario
        bool colisao(SolidoComposto *a, SolidoComposto *b);

		//Retorna se a tela está em fullScreen ou não
		bool isFullScreen();
		void desenhaTitulo(int posX,int posY);
		//Retorna a resolução padrão da Tela: First = Eixo X; Second = Eixo Y;
		pair<int, int> sizeScreen();

		//Posição da tela: First = Eixo X; Second = Eixo Y;
		pair<double, double> positionScreen(char *type);

		//Metodo de pressionamento de teclas
		void setFullScreen();

        static EfeitoVisual& getInstance();

        //Reajusta o tamanho da tela
        void static resize(GLsizei w, GLsizei h);

		void static setCamera();
};
#endif
 