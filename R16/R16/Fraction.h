#pragma once
#ifndef FRACTIONH
#define FRACTIONH

class Fraction
{
private:
    int nom;
    int den;
public:
    Fraction(char*);
    Fraction(int, int);
    operator char* ();
    void reduce();
};

#endif
