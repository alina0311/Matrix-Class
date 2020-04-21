#pragma once
#include <iostream>
using namespace std;
class Vector
{
	int dim, n;
	int* arr;
public:
	Vector(int dim = 1, int n = 0, int value = 0);
	virtual ~Vector();
	Vector(const Vector&);
	int Get_n();
	int& operator[](int index);
	Vector& operator=(const Vector&);
	friend istream& operator>>(istream& in, Vector& V);
	friend ostream& operator<<(ostream& out, const Vector& V);
};

