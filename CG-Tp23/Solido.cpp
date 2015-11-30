#include "Solido.hpp"

Solido::Solido(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat tamX, GLfloat tamY, GLfloat tamZ, Fase* fase)
{
    this->fase = fase;
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->tamX = tamX;
    this->tamY = tamY;
    this->tamZ = tamZ;
}


void Solido::setPos(std::tuple<GLfloat, GLfloat, GLfloat> pos)
{
	posX = std::get<0>(pos);
	posY = std::get<1>(pos);
	posZ = std::get<2>(pos);
}

void Solido::setVel(std::tuple<GLfloat, GLfloat, GLfloat> vel)
{
    velX = std::get<0>(vel);
    velY = std::get<1>(vel);
    velZ = std::get<2>(vel);
}

void Solido::setAcel(std::tuple<GLfloat, GLfloat, GLfloat> acel)
{
    acelX = std::get<0>(acel);
    acelY = std::get<1>(acel);
    acelZ = std::get<2>(acel);
}

void Solido::setTam(std::tuple<GLfloat, GLfloat, GLfloat> tam)
{
    tamX = std::get<0>(tam);
    tamY = std::get<1>(tam);
    tamZ = std::get<2>(tam);
}


///////////////////////////////////////////////////////////////////////

SolidoBase::SolidoBase() : Solido(nullptr)
{
    quad = nullptr;
    tamX = 1;
    tamY = 1;
    tamZ = 1;
}

void SolidoBase::carrega(std::vector<std::string> linhas)
{
	std::vector<std::string> campos = FuncoesAuxiliares::split(linhas[0], ' ');
	tipo = campos[0];
	for (int i = 0; i < 4; i++)
		cor[i] = stof(campos[i + 1]);

	campos = FuncoesAuxiliares::split(linhas[1], ' ');
	posX = stof(campos[0]);
	posY = stof(campos[1]);
	posZ = stof(campos[2]);

	campos = FuncoesAuxiliares::split(linhas[2], ' ');
	tamX *= stof(campos[0]);
	tamY *= stof(campos[1]);
	tamZ *= stof(campos[2]);
}
void SolidoBase::carregaTextura(GLuint textura)
{
    this->textura = textura;
}

void SolidoBase::desenha()
{
    glPushMatrix();
//    glColor4f(cor[0], cor[1], cor[2], cor[3]);
    glTranslatef(posX, posY, posZ);
    glScalef(tamX, tamY, tamZ);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);
    if (tipo == "C")
    {
        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5, -0.5, -0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5, -0.5, -0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5, 0.5, -0.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.5, -0.5, -0.5);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5, -0.5, 0.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5, 0.5, 0.5);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-0.5, 0.5, -0.5);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-0.5, -0.5, -0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5, 0.5, -0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5, 0.5, -0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5, 0.5, 0.5);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5, -0.5, 0.5);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5, -0.5, -0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5, -0.5, -0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glEnd();	

        glBindTexture(GL_TEXTURE_2D, textura);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5, 0.5, 0.5);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5, -0.5, 0.5);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5, 0.5, 0.5);
        glEnd();
    }
    else if (tipo == "K")
    {
        if (nullptr == quad)
        {
            quad = gluNewQuadric();
            gluQuadricDrawStyle(quad, GLU_SMOOTH);
            gluQuadricNormals(quad, GLU_SMOOTH);
            gluQuadricOrientation(quad, GLU_OUTSIDE);
            gluQuadricTexture(quad, GL_TRUE);
        }

        glBindTexture(GL_TEXTURE_2D, textura);
        gluCylinder(quad, 0.5, 0.5, 1, 24, 24);
    }
    else if (tipo == "E")
    {
        if (nullptr == quad)
        {
            quad = gluNewQuadric();
            gluQuadricDrawStyle(quad, GLU_SMOOTH);
            gluQuadricNormals(quad, GLU_SMOOTH);
            gluQuadricOrientation(quad, GLU_OUTSIDE);
            gluQuadricTexture(quad, GL_TRUE);
        }

        glBindTexture(GL_TEXTURE_2D, textura);
        gluSphere(quad, 1, 24, 24);
    }
    glPopMatrix();
}

void SolidoBase::gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ)
{
	this->rotX += rotX;
	this->rotY += rotY;
	this->rotZ += rotZ;
}


///////////////////////////////////////////////////////////


void SolidoComposto::carrega(std::string forma, GLuint textura)
{
	solidos.clear();

	std::ifstream fs;
    fs.open(forma, std::fstream::in);
	while (!fs.eof())
	{
		std::string linha;
		std::getline(fs, linha);
		if (linha == "")
			continue;
		std::vector<std::string> linhas;
		linhas.push_back(linha);
		std::getline(fs, linha);
		linhas.push_back(linha);
		std::getline(fs, linha);
		linhas.push_back(linha);

		solidos.push_back(new SolidoBase(tamX, tamY, tamZ));
		solidos.back()->carrega(linhas);
        solidos.back()->carregaTextura(textura);

        std::tuple<GLfloat, GLfloat, GLfloat> tam = solidos.back()->getTam();
	}

	calculaTamanho();
}

void SolidoComposto::desenha()
{
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);
    glScalef(tamX, tamY, tamZ);

	for (int i = 0; i < solidos.size(); i++)
		solidos[i]->desenha();

    glPopMatrix();
}

tuple<GLfloat, GLfloat, GLfloat> SolidoComposto::calculaTamanho()
{
	GLfloat tamX = 0; tamY = 0; tamZ = 0;

	for (int i = 0; i < solidos.size(); i++)
	{
		std::tuple<GLfloat, GLfloat, GLfloat> tam = solidos[i]->getTam();
		std::tuple<GLfloat, GLfloat, GLfloat> pos = solidos[i]->getPos();

		if (abs(std::get<0>(tam)) + abs(std::get<0>(pos)) > tamX)
			tamX = abs(std::get<0>(tam)) + abs(std::get<0>(pos));
		if (abs(std::get<1>(tam)) + abs(std::get<1>(pos)) > tamY)
			tamY = abs(std::get<1>(tam)) + abs(std::get<1>(pos));
		if (abs(std::get<2>(tam)) + abs(std::get<2>(pos)) > tamZ)
			tamZ = abs(std::get<2>(tam)) + abs(std::get<2>(pos));
	}

    this->tamX = tamX;
    this->tamY = tamY;
    this->tamZ = tamZ;

    return make_tuple(tamX, tamY, tamZ);
}

void SolidoComposto::gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ)
{
    this->rotX += rotX;
    this->rotY += rotY;
    this->rotZ += rotZ;
}
