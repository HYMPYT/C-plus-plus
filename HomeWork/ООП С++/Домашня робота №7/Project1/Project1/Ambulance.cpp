#include"Ambulance.h"
Ambulance::Ambulance(const string&org, int val) :Emergency(org, val) {}
Ambulance::~Ambulance()
{
	cout << "~Ambulance()" << endl;
}
void Ambulance::signal()
{
	cout << "Ambulance signal" << endl;
}