#include"Minivan.h"
Minivan::Minivan(const string&c, int val) :Common(c, val) {}
Minivan::~Minivan()
{
	cout << "~Minivan()" << endl;
}