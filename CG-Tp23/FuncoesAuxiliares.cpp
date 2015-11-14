#include "FuncoesAuxiliares.hpp"


FuncoesAuxiliares::FuncoesAuxiliares()
{
}

FuncoesAuxiliares::~FuncoesAuxiliares()
{
}

vector<string> FuncoesAuxiliares::split(const string &s, char delim)
{
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

void FuncoesAuxiliares::desenha(int ix, int iy)
{
	glBegin(GL_POINTS);
	glVertex2i(ix, iy);
	glEnd();
}

void FuncoesAuxiliares::bresenham(int x1, int y1, int x2, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
		dx = -dx;

	if (dy < 0)
		dy = -dy;

	incx = 1;
	if (x2 < x1)
		incx = -1;

	incy = 1;
	if (y2 < y1)
		incy = -1;

	x = x1;
	y = y1;

	if (dx > dy)
	{
		FuncoesAuxiliares::desenha(x, y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			x += incx;
			FuncoesAuxiliares::desenha(x, y);
		}
	}
	else
	{
		FuncoesAuxiliares::desenha(x, y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			y += incy;
			FuncoesAuxiliares::desenha(x, y);
		}
	}
}

void FuncoesAuxiliares::bresenhamCircle(int x, int y, int a, int b)
{
	int wx, wy;
	int thresh;
	int asq = a * a;
	int bsq = b * b;
	int xa, ya;
	FuncoesAuxiliares::bresenham(x, y + b, x, y - b);
	wx = 0;
	wy = b;
	xa = 0;
	ya = asq * 2 * b;
	thresh = asq / 4 - asq * b;
	while (xa < ya) {
		thresh += xa + bsq;
		if (thresh >= 0) {
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}
		xa += bsq * 2;
		wx++;
		if (xa >= ya)
			break;
		FuncoesAuxiliares::bresenham(x + wx, y - wy, x - wx, y - wy);
		FuncoesAuxiliares::bresenham(x + wx, y + wy, x - wx, y + wy);
	}
	FuncoesAuxiliares::bresenham(x + a, y, x - a, y);
	wx = a;
	wy = 0;
	xa = bsq * 2 * a;
	ya = 0;
	thresh = bsq / 4 - bsq * a;
	while (ya <= xa) {
		thresh += ya + asq;
		if (thresh >= 0) {
			xa -= bsq * 2;
			thresh = thresh - xa;
			wx--;
		}
		ya += asq * 2;
		wy++;
		if (ya > xa)
			break;
		FuncoesAuxiliares::bresenham(x + wx, y - wy, x - wx, y - wy);
		FuncoesAuxiliares::bresenham(x + wx, y + wy, x - wx, y + wy);
	}
}

void FuncoesAuxiliares::writeWord_BITMAP(string word, void(*fontStyle)) {
	for (int i = 0; i < word.length(); i++) {
		glutBitmapCharacter(fontStyle, word[i]);
	}
}
