#include"ConcreteMixer.h"
ConcreteMixer::ConcreteMixer(const string&org, int val) :Builder(org, val) {}
ConcreteMixer::~ConcreteMixer()
{
	cout << "~ConcreteMixer()" << endl;
}
void ConcreteMixer::work()
{
	cout << "ConcreteMixer is working" << endl;
}