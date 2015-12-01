#ifndef SOLIDO_H
#define SOLIDO_H

class Solido;
class SolidoBase;
class SolidoComposto;

#ifdef _WIN32
#include <windows.h>
#endif
#include "FuncoesAuxiliares.hpp"
#include "Fase.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>


/*
	Classe abstrata para servir como "interface" para
		os objetos do jogo.
*/

#define SOLIDO

class Solido
{
	protected:
        //Fase a qual o solido pertence
        Fase *fase;
		//Posicao central do solido
		GLfloat posX, posY, posZ;
        //Velocidade de movimentação do solido
        GLfloat velX, velY, velZ;
        //Aceleracao do solido
        GLfloat acelX, acelY, acelZ;
        //Escala do solido
        GLfloat tamX, tamY, tamZ;
        //Escala do solido
        GLfloat escala;
        //Rotacao do solido
        GLfloat rotX, rotY, rotZ;
        //Textura do solido
        GLuint textura;

	public:
        Solido(Fase* fase) { this->fase = fase; }
        Solido(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat escala, Fase* fase);
        virtual ~Solido() {}

		//Desenha o solido na tela
        virtual void carrega(std::vector<std::string> linhas) = 0;

        //Carrega a textura do solido 
        virtual void carregaTextura(GLuint textura) = 0;

		//Desenha o solido na tela
        virtual void desenha() = 0;

		//Getters
		std::tuple<GLfloat, GLfloat, GLfloat> getPos() { return std::make_tuple(posX, posY, posZ); }
		std::tuple<GLfloat, GLfloat, GLfloat> getVel() { return std::make_tuple(velX, velY, velZ); }
		std::tuple<GLfloat, GLfloat, GLfloat> getAcel() { return std::make_tuple(acelX, acelY, acelZ); }
        std::tuple<GLfloat, GLfloat, GLfloat> getTam() { return std::make_tuple(tamX, tamY, tamZ); }
        std::tuple<GLfloat, GLfloat, GLfloat> getRot() { return std::make_tuple(rotX, rotY, rotZ); }

		//Setter
        void setPos(std::tuple<GLfloat, GLfloat, GLfloat> pos);
        void setVel(std::tuple<GLfloat, GLfloat, GLfloat> vel);
        void setAcel(std::tuple<GLfloat, GLfloat, GLfloat> acel);
        void setTam(std::tuple<GLfloat, GLfloat, GLfloat> tam);

		//Teta gira no plano XY e phi gira no plano YZ
        virtual void gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ) = 0;
};

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

class SolidoBase : public Solido {
	protected:

        std::string tipo;
        GLfloat cor[4];

        GLUquadric* quad;
        GLuint textura;

    public:
        SolidoBase() : 
            Solido(0, 0, 0, 1, nullptr) {}
        SolidoBase(GLfloat escala) : 
            Solido(0, 0, 0, escala, nullptr) {}
        ~SolidoBase() {}

		//Carrega a forma do solido
        void carrega(std::vector<std::string> linhas);

        //Carrega a textura do solido 
        void carregaTextura(GLuint textura);

		//Desenha o solido na tela
		void desenha();

		//Teta gira no plano XY e phi gira no plano YZ
        void gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ);
};

//////////////////////////////////////////////////////////////////

class SolidoComposto : public Solido {
	protected:
		//Vetor de solidos base
		std::vector<Solido*> solidos;


	public:
        SolidoComposto(Fase* fase) : Solido(fase) {}
        SolidoComposto(GLfloat posX, GLfloat posY, GLfloat posZ, float escala, Fase* fase) :
            Solido(posX, posY, posZ, escala, fase) {}
        ~SolidoComposto() {}

		//Desenha o solido na tela
        void carrega(std::string forma, GLuint textura);

        void carrega(std::vector<std::string> linhas) {}
        void carregaTextura(GLuint textura) {}

		//Desenha o solido na tela
		void desenha();

		//Define as acoes do solido
		//	(movimento, destruicao, ...)
		virtual void acao() = 0;

        //Numero de pontos quando o objeto eh destruido
        virtual int getPontos() = 0;

		//Calcula o tamanho do solido
        virtual tuple<GLfloat, GLfloat, GLfloat> calculaTamanho();

		//Teta gira no plano XY e phi gira no plano YZ
        void gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ);
};

#include "Fase.hpp"

#endif
 