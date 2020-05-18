#pragma warning(disable:4996)
#include "Fraction.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int euclide(int n, int m)
{
	int r = 1;
	while (n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return(m);
}
Fraction::Fraction(int n = 0, int m = 1) : nom(n), den(m) {};
Fraction::Fraction(char* s)
{
	char* p = strchr(s, '/');
	den = 1;
	if (p != NULL)
	{
		*p++ = '\0';
		den = atoi(p);
	}
	nom = atoi(s);
}



Fraction::operator char* ()
{
	static char s[32];
	sprintf(s, "%d/%d", nom, den);
	return s;
}

void Fraction::reduce()
{
	int gcd;
	gcd = euclide(abs(nom), den);
	nom /= gcd;
	den /= gcd;
	return;
}