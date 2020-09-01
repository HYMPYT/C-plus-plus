#include <iostream>
using namespace std;

// приклад оголошення і використання вказівника на фукнцію

// площа круга радиуса R
double AreaCircle(double r) { return 3.14 * r * r; }

// площа квадрата зі стороною а
double AreaSquare(double a) { return a*a; }

void main()
{
	double x = 1.0;
	cout << "AreaCircle: " << AreaCircle(x) << endl;
	cout << "AreaSquare: " << AreaSquare(x) << endl;

	double(*pf)(double);  // вказівник на функцію
	pf = AreaCircle;
	cout << "AreaCircle: " << (*pf)(x) << endl;
	pf = AreaSquare;
	cout << "AreaSquare: " << (*pf)(x) << endl;

	system("Pause");
}