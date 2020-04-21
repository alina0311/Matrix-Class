#include "vectorr2.h"
using namespace std;
Vector::Vector(int dim, int n, int value) {
	this->dim = dim;
	this->n = n;
	arr = new int[dim];
	for (int i = 0; i < n; ++i)
		arr[i] = value;
}
Vector::~Vector() {
	/*if (arr) {
		delete[] arr;
	}*/
}

int Vector::Get_n() {
	return n;
}
Vector::Vector(const Vector& v) {
	this->dim = v.dim;
	this->n = v.n;
	arr = new int[dim];
	for (int i = 0; i < n; ++i)
		arr[i] = v.arr[i];
}
Vector& Vector::operator=(const Vector& v) { //[1,2,3] [1,2,3,4,5]
	if (this == &v) {
		return *this;
	}
	if (arr != NULL) delete[]arr;
	dim = v.dim;
	n = v.n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		arr[i] = v.arr[i];
	return *this;
}
ostream& operator<<(ostream& out, const Vector& v) {
	for (int i = 0; i < v.n; ++i)
		out << v.arr[i] << ' ';
	return out;
}
istream& operator>>(istream& in, Vector& v) {
	cout << "Introduceti numarul de elemente: ";
	in >> v.n;
	cout << "Introduceti elementele vectorului: ";
	for (int i = 0; i < v.n; ++i)
		in >> v.arr[i];
	return in;
}

int& Vector::operator[](int index) {
	if (index >= n or index < 0)
		throw std::invalid_argument("Index-ul nu se afla in range.");
	return arr[index];
}