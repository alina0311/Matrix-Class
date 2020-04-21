#include "matrice_pp.h"
#include "matrice_o.h"
#include "matricex.h"
#include <iostream>
Matrice_patratica::Matrice_patratica(int dim, int value) : Matrice(dim * 2) {
	this->dim = dim;
	linii = new Vector[dim];
	Vector aux(dim, dim, value);
	for (int i = 0; i < dim; i++) {
		linii[i] = aux;
	}
}
Matrice_patratica::Matrice_patratica(const Matrice_patratica& M) : Matrice(M) {
	this->dim = M.dim;
	linii = new Vector[dim];
	for (int i = 0; i < dim; i++) {
		linii[i] = M.linii[i];
	}
}

Matrice_patratica& Matrice_patratica::operator=(const Matrice_patratica& M) {
	if (this == &M) return *this;
	Matrice::operator=(M);
	if (linii != NULL) delete[] linii;
	dim = M.dim;
	linii = new Vector[dim];
	for (int i = 0; i < dim; i++) {
		linii[i] = M.linii[i];
	}
	return *this;
}

Matrice_patratica::~Matrice_patratica() {
	dim = 0;
}

void Matrice_patratica::citire(istream& in) {
	cout << "Dati dimensiunea matricei patratice: ";
	in >> dim;
	linii = new Vector[dim];
	Vector aux(2 * dim, dim);
	for (int i = 0; i < dim; i++) {
		linii[i] = aux;
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			in >> linii[i][j];
		}
	}
}

Vector& Matrice_patratica::operator[](int index) {
	if (index < 0 || index >= dim) throw invalid_argument("Indexul nu se afla in range-ul matricei patratice");
	return linii[index];
}

void Matrice_patratica::afisare(ostream& out) {
	out << "\n";
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			out << linii[i][j] << " ";
		}
		out << "\n";
	}
	out << "Determinantul matricei patratice este: " << this->Determinant() << "\n";
}

bool Matrice_patratica::Triunghiulara() {
	for (int i = 0; i < dim; ++i)
		for (int j = i + 1; j < dim; ++j) {
			if (i == j and linii[i][j] == 0) return false;
			else if (linii[i][j] == 0 and linii[j][i] == 0) return false;
				else if (linii[i][j] != 0 and linii[j][i] != 0) return false;
		}
	for (int i = 0; i < dim; ++i)
		if (linii[i][i] == 0) return false;
	return true;
}
bool Matrice_patratica::Diagonala() {
	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j) {
			if (i != j)
				if (linii[i][j] != 0) return false;
		}
	return true;
}

double Matrice_patratica::Determinant() {
	double det = 0;
	if (dim == 2) {
		det = linii[0][0] * linii[1][1] - linii[0][1] * linii[1][0];
	}
	else if (dim == 3) {
		det = linii[0][0] * linii[1][1] * linii[2][2] + linii[1][0] * linii[2][1] * linii[0][2] + linii[0][1] * linii[1][2] * linii[2][0] - linii[0][2] * linii[1][1] * linii[2][0] - linii[1][2] * linii[2][1] * linii[0][0] - linii[1][0] * linii[0][1] * linii[2][2];
	}
	return det;
}
ostream& operator<<(ostream& out, Matrice_patratica& M) {
	M.afisare(out);
	return out;
}
istream& operator>>(istream& in, Matrice_patratica& M) {
	M.citire(in);
	return in;
}