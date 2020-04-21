#pragma once
#include <iostream>
#include "vectorr2.h"
class Matrice
{
protected:
	int rmax;
public:
	Vector* linii;
	Matrice(int rmax = 10); 
	Matrice(const Matrice&);
	virtual ~Matrice();
	virtual void citire(istream& in) = 0;
	virtual void afisare(ostream& out) = 0;
	virtual Vector& operator[](int) = 0;
	Matrice& operator=(const Matrice&);
	friend istream& operator>>(istream& in, Matrice& M);
	friend ostream& operator<<(ostream& out, const Matrice& M);
};



