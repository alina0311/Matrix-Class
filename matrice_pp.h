#pragma once
#include <iostream>
#include "matricex.h"
#include "vectorr2.h"
class Matrice_patratica: public Matrice
{
	int dim;
public:
	Matrice_patratica(int dim = 1, int value = 0);
	Matrice_patratica(const Matrice_patratica&);
	virtual ~Matrice_patratica();
	Matrice_patratica& operator=(const Matrice_patratica&);
	friend istream& operator>>(istream& in, Matrice_patratica& M);
	friend ostream& operator<<(ostream& out, Matrice_patratica& M);
	virtual void citire(istream& in);
	virtual void afisare(ostream& out);
	Vector& operator[](int index);
	bool Diagonala();
	bool Triunghiulara();
	double Determinant();
};

