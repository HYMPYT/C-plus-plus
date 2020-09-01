#include"Special.h"
Special::Special(const string &org, int val) :Automobile(val)
{
	organization = org;
}
const string& Special::getOrganization()const
{
	return organization;
}
void Special::setOrganization(const string&org)
{
	organization = org;
}
Special::~Special()
{
	cout << "~Special()" << endl;
}