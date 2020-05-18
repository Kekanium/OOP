#include <stdio.h>
#include <iostream>
#include "Fraction.h"


int main(int argc, char* argv[])
{
	if (argc != 3)
		return(puts("Wrong input. Start with:\nInt_Number and complement Nomerator / Denomerator"));
	int a = atoi(argv[1]);
	Fraction b(argv[2]);


	return(0);
}