#pragma once
#ifndef FIGUREH
#define FIGUREH
//#include <string>
#include <iostream>
#include <string.h>
class Figure
{
protected:
	char _position[2];
public:
	Figure(const char*);
	Figure();
	virtual char isA() = 0;
	virtual int attack(char*) = 0;
	static int deskout(char*);
	void printBoard();
	Figure& operator=(char*);
	int operator!=(char*);
	int operator==(char*);
	friend std::ostream& operator<<(std::ostream&, Figure&);
	friend std::istream & operator>>(std::istream&, Figure&);
};

#endif 