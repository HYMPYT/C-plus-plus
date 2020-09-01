#include"TruckCrane.h"
TruckCrane::TruckCrane(const string& org, int val) :Builder(org, val) {}
TruckCrane::~TruckCrane()
{
	cout << "~TruckCrane()" << endl;
}
void TruckCrane::work()
{
	cout << "TruckCrane is working" << endl;
}