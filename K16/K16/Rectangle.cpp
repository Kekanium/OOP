#include "Rectangle.h"
#include "Dot.h"
#include <math.h>
#define ACCURANCY 0.000000000001
Triangle::Triangle() {};

Triangle::Triangle(Dot A, Dot B, Dot C) :point{ A,B,C }
{
}

double Triangle::calcRadius()
{
	double S = abs((point[0]._x - point[2]._x) * (point[1]._y - point[2]._y) - (point[1]._x - point[2]._x) * (point[0]._y - point[2]._y)) / 2;
	if (S < ACCURANCY)
		return 0;
	double R, a, b, c;

	a = calcLine(0, 1);
	b = calcLine(0, 2);
	c = calcLine(1, 2);

	R = a * b * c / (4 * S);
	return R;
}

double Triangle::calcLine(int a, int b)
{
	return sqrt(pow(point[a]._x-point[b]._x,2)+ pow(point[a]._y - point[b]._y, 2));
}
