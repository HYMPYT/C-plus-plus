#include "Circle.h"
Circle::Circle(double radius)
{
	this->radius = radius;
}
double Circle::getRadius()const
{
	return radius;
}
void Circle::setRadius(double val)
{
	radius = val;
}