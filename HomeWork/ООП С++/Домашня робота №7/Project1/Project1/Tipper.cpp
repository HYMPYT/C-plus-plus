#include"Tipper.h"
Tipper::Tipper(const string&org, int val) :Builder(org, val) {}
Tipper::~Tipper()
{
	cout << "~Tipper()" << endl;
}
void Tipper::work()
{
	cout << "Tipper is working" << endl;
}