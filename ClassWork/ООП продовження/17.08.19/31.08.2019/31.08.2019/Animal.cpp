#include"Animal.h"
Animal::Animal(const string&n)
{
	name = n;
}
const string&Animal::getName()const
{
	return name;
}
void Animal::setName(const string&n)
{
	name = n;
}
Animal::~Animal()
{
	cout << "~Animal()" << endl;
}