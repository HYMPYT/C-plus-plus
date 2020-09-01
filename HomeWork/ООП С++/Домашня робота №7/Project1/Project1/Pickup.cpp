#include"Pickup.h"
Pickup::Pickup(const string&c, int val) :Common(c, val) {}
Pickup::~Pickup()
{
	cout << "~Pickup()" << endl;
}