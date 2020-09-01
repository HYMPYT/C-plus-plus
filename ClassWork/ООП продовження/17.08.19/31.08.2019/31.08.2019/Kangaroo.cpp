#include"Kangaroo.h"
Kangaroo::Kangaroo(const string &n) :Animal(n)
{

}
void Kangaroo::move()
{
	cout << getName() << " is jumping" << endl;
}
Kangaroo::~Kangaroo()
{
	cout << "~Kangoroo()" << endl;
}