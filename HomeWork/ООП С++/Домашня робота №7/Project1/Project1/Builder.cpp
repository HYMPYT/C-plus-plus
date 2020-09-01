#include"Builder.h"
Builder::Builder(const string& org, int val) :Special(org, val) {}
Builder::~Builder()
{
	cout << "~Builder()" << endl;
}