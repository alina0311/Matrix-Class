#include <iostream>
#include "vectorr2.h"
#include "matricex.h"
#include "matrice_o.h"
#include "matrice_pp.h"
using namespace std;
int main()
{
	
	Matrice_oarecare A(2, 3);
	Matrice_oarecare B = A;
	for (int i = 0; i < B.GetL(); i++) {
		for (int j = 0; j < B.GetC(); j++) {
			cout << B.linii[i][j] << " ";
		}
		cout << "\n";
	}
	try {
		A[6][1] = 1;
	}
	catch (invalid_argument exc) {
		cout << exc.what();
	}
	A.afisare(cout);
	cout << "\n";
	try {
		A[1][1] = 1;
	}
	catch (invalid_argument exc) {
		cout << exc.what();
	}
	A.afisare(cout);
	Matrice_patratica C(3);
	C.citire(cin);
	Matrice_patratica D(3);
	D = C;
	if (D.Diagonala() == true) cout << "Matricea este diagonala!";
	else cout << "Matricea NU e diagonala!";
	cout << "\n";
	if (D.Triunghiulara() == true) cout << "Matricea este triunghiulara!";
	else cout << "Matricea NU e triunghiulara!";
	cout << D;

	cout << "\n" << "Dati numarul de matrici: ";
	int n;
	cin >> n;
	//Matrice* p = new Matrice_oarecare();
	Matrice** matr = new Matrice * [n];
	for (int i = 0; i < n; i++) {
		cout << "Matrice oarecare sau patratica?\n";
		string tip;
		cin >> tip;
		if (tip == "oarecare") {
			matr[i] = new Matrice_oarecare();
			matr[i]->citire(cin);
		}
		else if (tip == "patratica") {
			matr[i] = new Matrice_patratica();
			matr[i]->citire(cin);
		}
		else {
			cout << "Dati o matrice oarecare sau patratica!";
			i--;
			}
	}

	for (int i = 0; i < n; i++) {
		matr[i]->afisare(cout);
		cout << "\n";
	}
	return 0;
}

