#ifndef OBJETOS_H
#define OBJETOS_H
#include "Solido.hpp"


class Bala : public SolidoComposto
{
	public:
		Bala();
		~Bala();

		void acao() {}
};

#endif