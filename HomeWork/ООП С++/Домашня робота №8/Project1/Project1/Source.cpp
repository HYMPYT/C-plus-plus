#include"CircleInSquare.h"
int main()
{
	double radius;
	cout << "Enter the radius of the circle -> ";
	cin >> radius;
	CircleInSquare myCircleInSquare(radius);
	myCircleInSquare.show();
	system("pause");
}