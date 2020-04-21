#include "matrice_o.h"
#include "matricex.h"
Matrice_oarecare::Matrice_oarecare(int l, int c, int value): Matrice(l*2){
	this->lin = l;
	this->col = c;
	linii = new Vector[lin];
	Vector aux(c, c, value);
	for (int i = 0; i < lin; i++) {
		linii[i] = aux;
	}
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& M) : Matrice(M) {
	this->lin = M.lin;
	this->col = M.col;
	linii = new Vector[lin];
	for (int i = 0; i < lin; i++) {
		linii[i] = M.linii[i];
	}
}
int Matrice_oarecare::GetC(){
	return col;
}
int Matrice_oarecare::GetL(){
	return lin;
}
Matrice_oarecare& Matrice_oarecare::operator=(const Matrice_oarecare& M) {
	if (this == &M) return *this;
	Matrice::operator=(M);
	if (linii != NULL) delete[] linii;
	lin = M.lin;
	col = M.col;
	linii = new Vector[lin];
	for (int i = 0; i < lin; i++) {
		linii[i] = M.linii[i];
	}
	return *this;
}

Matrice_oarecare::~Matrice_oarecare() {
	lin = col = 0;
}

void Matrice_oarecare::citire(istream &in) {
	cout << "Dati numarul de linii: ";
	in >> lin;
	cout << "Dati numarul de coloane: ";
	in >> col;
	linii = new Vector[lin];
	Vector aux(2*col, col);
	for (int i = 0; i < lin; i++) {
		linii[i] = aux;
	}
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			in >> linii[i][j];
		}
	}
}

Vector& Matrice_oarecare::operator[](int index) {
	if (index < 0 || index >= lin) throw invalid_argument("Indexul nu se afla in range-ul matricei oarecare \n");
	return linii[index];
}

void Matrice_oarecare::afisare(ostream& out){
	out << "\n";
	for (int i = 0; i < lin; i++) {
		for (int j = 0; j < col; j++) {
			out << linii[i][j] << " ";
		}
		out << "\n";
	}
}

ostream& operator<<(ostream& out, Matrice_oarecare& M) {
	M.afisare(out);
	return out;
}
istream& operator>>(istream& in, Matrice_oarecare& M) {
	M.citire(in);
	return in;
}