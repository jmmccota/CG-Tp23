#include "Solido.hpp"

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
	tamX = stof(campos[0]);
	tamY = stof(campos[1]);
	tamZ = stof(campos[2]);
}

void SolidoBase::desenha()
{
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor4f(cor[0], cor[1], cor[2], cor[3]);
    glTranslatef(posX, posY, posZ);
    glScalef(tamX, tamY, tamZ);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);
    if (tipo == "C")
    {
        glutSolidCube(1);
    }
    else if (tipo == "K")
    {
        if (nullptr == quad)
        {
            gluCylinder(quad, 0.5, 0.5, 1, 24, 24);
            gluQuadricDrawStyle(quad, GLU_SILHOUETTE);
            gluQuadricNormals(quad, GLU_SMOOTH);
        }
		//Desenhar
    }
    else if (tipo == "E")
    {
        if (nullptr == quad)
        {
            gluSphere(quad, 1, 24, 24);
            gluQuadricDrawStyle(quad, GLU_SILHOUETTE);
        }
		//Desenhar
    }
    glPopMatrix();
    glFlush();
}

void SolidoBase::gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ)
{
	this->rotX += rotX;
	this->rotY += rotY;
	this->rotZ += rotZ;
}


///////////////////////////////////////////////////////////


void SolidoComposto::carrega(std::string arquivo)
{
	solidos.clear();

	std::ifstream fs;
	fs.open(arquivo, std::fstream::in);
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

		solidos.push_back(new SolidoBase());
		solidos.back()->carrega(linhas);
	}

	calculaTamanho();
}

void SolidoComposto::desenha()
{
	for (int i = 0; i < solidos.size(); i++)
		solidos[i]->desenha();
}

void SolidoComposto::calculaTamanho()
{
	this->tamX = 0; this->tamY = 0; this->tamZ = 0;

	for (int i = 0; i < solidos.size(); i++)
	{
		std::tuple<GLfloat, GLfloat, GLfloat> tam = solidos[i]->getTam();
		std::tuple<GLfloat, GLfloat, GLfloat> pos = solidos[i]->getPos();

		if (abs(std::get<0>(tam)) + abs(std::get<0>(pos)) > this->tamX)
			this->tamX = abs(std::get<0>(tam)) + abs(std::get<0>(pos));
		if (abs(std::get<1>(tam)) + abs(std::get<1>(pos)) > this->tamY)
			this->tamY = abs(std::get<1>(tam)) + abs(std::get<1>(pos));
		if (abs(std::get<2>(tam)) + abs(std::get<2>(pos)) > this->tamZ)
			this->tamZ = abs(std::get<2>(tam)) + abs(std::get<2>(pos));
	}
}

void SolidoComposto::gira(GLfloat rotX, GLfloat rotY, GLfloat rotZ)
{
	float senX = sin(rotX), cosX = cos(rotX),
		  senY = sin(rotY), cosY = cos(rotY),
		  senZ = sin(rotZ), cosZ = cos(rotZ);

	GLfloat x, y, z;

	for (int i = 0; i < solidos.size(); i++) 
	{
		solidos[i]->gira(rotX, rotY, rotZ);

		std::tie(x, y, z) = solidos[i]->getPos();

		y = y * cosX - z * senX;
		z = y * senX + z * cosX;

		x = x * cosY + z * senY;
		z = -x * senY + z * cosY;

		x = x * cosZ - y * senZ;
		y = x * senZ + y * cosZ;

		solidos[i]->setPos(std::make_tuple(x, y, z));
	}
}
