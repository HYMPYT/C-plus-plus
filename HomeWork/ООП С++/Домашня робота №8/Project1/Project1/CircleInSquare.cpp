#include "CircleInSquare.h"
CircleInSquare::CircleInSquare(double radius) :Circle(radius), Square(radius * 2) {}
void CircleInSquare::show()
{
	cout << "Side of the square -> " << getSide() << endl;
	cout << "Circle radius -> " << getRadius() << endl;
}