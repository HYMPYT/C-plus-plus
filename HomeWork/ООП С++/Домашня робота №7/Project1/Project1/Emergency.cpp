#include"Emergency.h"
Emergency::Emergency(const string& org, int val) :Special(org, val) {}
Emergency::~Emergency()
{
	cout << "~Emergency()" << endl;
}