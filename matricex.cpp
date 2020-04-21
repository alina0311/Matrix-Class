#include "matricex.h"
#include "vectorr2.h"

Matrice::Matrice(const Matrice& M) {
	rmax = M.rmax;
}

Matrice::Matrice(int rmax) {
	this->rmax = rmax;
}
Matrice::~Matrice() {
	if (linii != NULL) {
		delete[] linii;
	}
}
istream& operator >> (istream& in, Matrice& M) {
	in >> M.rmax;
	return in;
	/*M.citire(in);*/
}
ostream& operator << (ostream& out, const Matrice& M) {
	out << M.rmax;
	return out;
}
Matrice& Matrice::operator = (const Matrice& M) {
	rmax = M.rmax;
	return *this;
}