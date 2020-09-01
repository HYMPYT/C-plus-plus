#include"Police.h"
Police::Police(const string& org, int val) :Emergency(org, val) {}
Police::~Police()
{
	cout << "~Police()" << endl;
}
void Police::signal()
{
	cout << "Police signal" << endl;
}