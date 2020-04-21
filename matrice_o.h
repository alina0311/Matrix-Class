#pragma once
#include "vectorr2.h"
#include "matricex.h"
class Matrice_oarecare: public Matrice
{
	int lin;
	int col;
public:
	Matrice_oarecare(int l = 1, int c = 1, int value = 0);
	Matrice_oarecare(const Matrice_oarecare&);
	virtual ~Matrice_oarecare();
	int GetL();
	int GetC();
	Matrice_oarecare& operator=(const Matrice_oarecare&);
	friend istream& operator>>(istream& in, Matrice_oarecare& M);
	friend ostream& operator<<(ostream& out, Matrice_oarecare& M);
	virtual void citire(istream& in);
	virtual void afisare(ostream& out);
	Vector& operator[](int index);
};

