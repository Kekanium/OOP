#pragma once
#ifndef GAMBLERH
#define GAMBLERH
#include "Heap.h"
#include <iostream>
class Gambler
{
protected:
	Heap* heap;
	const int limit;
	const char* name;
public:
	Gambler(Heap&, int);
	void query();
	virtual bool move() = 0;
};

#endif