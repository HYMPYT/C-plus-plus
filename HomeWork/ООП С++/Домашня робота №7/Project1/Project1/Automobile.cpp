#include"Automobile.h"
int Automobile::getNumber()const
{
	return number;
}
void Automobile::setNumber(int val)
{
	number = val;
}
Automobile::Automobile(int val)
{
	number = val;
}
