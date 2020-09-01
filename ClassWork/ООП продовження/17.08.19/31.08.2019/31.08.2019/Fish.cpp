#include"Fish.h"
Fish::Fish(const string &n) :Animal(n)
{

}
void Fish::move()
{
	cout << getName() << " is swimming" << endl;
}
Fish::~Fish()
{
	cout << "~Fish()" << endl;
}