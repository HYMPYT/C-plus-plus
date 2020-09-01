#include"FireEngine.h"
FireEngine::FireEngine(const string&org, int val) :Emergency(org, val) {}
FireEngine::~FireEngine()
{
	cout << "~FireEngine()" << endl;
}
void FireEngine::signal()
{
	cout << "FireEngine signal" << endl;
}