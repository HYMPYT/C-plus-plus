#include"Penguin.h"
Penguin::Penguin(const string&n) :Bird(n)
{

}
//void Penguin::move()
//{
//	cout << getName() << " is walking and swimming" << endl;
//}
Penguin::~Penguin()
{
	cout << "~Penguin()" << endl;
}