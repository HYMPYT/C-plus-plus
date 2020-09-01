#include"Sedan.h"
Sedan::Sedan(const string&c, int val) :Common(c, val) {}
Sedan::~Sedan()
{
	cout << "~Sedan()" << endl;
}