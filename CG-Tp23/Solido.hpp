#ifndef SOLIDO_H
#define SOLIDO_H

class Solido;
class SolidoBase;
class SolidoComposto;

#ifdef _WIN32
#include <windows.h>
#endif
#include "FuncoesAuxiliares.hpp"
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


class Solido
{
	protected:
		//Posicao central do solido
		GLfloat posX, posY, posZ;
        //Velocidade de movimentação do solido
        GLfloat velX, velY, velZ;
        //Aceleracao do solido
        GLfloat acelX, acelY, acelZ;
        //Escala do solido
        GLfloat tamX, tamY, tamZ;
        //Rotacao do solido
        GLfloat rotX, rotY, rotZ;

	public:
        Solido() {}
        Solido(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat tamX, GLfloat tamY, GLfloat tamZ);
        virtual ~Solido() {}

		//Desenha o solido na tela
		virtual void carrega(std::vector<std::string> linhas) = 0;

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

	public:
        SolidoBase();
        SolidoBase(GLfloat tamX, GLfloat tamY, GLfloat tamZ) : 
            Solido (0, 0, 0, tamX, tamY, tamZ) {}
        ~SolidoBase() {}

		//Desenha o solido na tela
		void carrega(std::vector<std::string> linhas);

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
        SolidoComposto() : Solido() {}
        SolidoComposto(GLfloat posX, GLfloat posY, GLfloat posZ, float escala) : 
            Solido(posX, posY, posZ, escala, escala, escala) {}
        ~SolidoComposto() {}

		//Desenha o solido na tela
		void carrega(std::string arquivo);

		void carrega(std::vector<std::string> linhas) {}

		//Desenha o solido na tela
		void desenha();

		//Define as acoes do solido
		//	(movimento, destruicao, ...)
		virtual void acao() = 0;

		//Calcula o tamanho do solido
		void calculaTamanho();

		//Teta gira no plano XY e phi gira no plano YZ
        void gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ);
};

#endif
 