#include"Bird.h"
Bird::Bird(const string & n) :Animal(n)
{

}
void Bird::move()
{
	cout << getName() << " is flying" << endl;
}
Bird::~Bird()
{
	cout << "~Bird()" << endl;
}