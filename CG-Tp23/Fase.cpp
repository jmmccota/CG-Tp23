#include "Fase.hpp"

Fase::Fase(Jogo *jogo)
{
    this->jogo = jogo;
}

Fase::~Fase()
{

}

void Fase::novoProjetil(SolidoComposto *p)
{
	projeteis.push_back(p);
}

void Fase::reseta()
{
    inimigos.clear();
    projeteis.clear();
}
 