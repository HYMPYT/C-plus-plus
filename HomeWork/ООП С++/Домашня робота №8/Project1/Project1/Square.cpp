#include "Square.h"

Square::Square(double side)
{
	this->side = side;
}
double Square::getSide()const
{
	return side;
}
void Square::setSide(double val)
{
	side = val;
}