#include <iostream>
using namespace std;

// приклад використання вказівника на функцію як параметра ф-ї

double Suma(double a, double b) { return a + b; }
double Dob(double a, double b) { return a * b; }

double Operation(double a, double b, double(*pf) (double, double))
{
	double res = (*pf)(a, b);
	return res;
}

void main()
{
	cout << "Operation(2,3, Suma): " << Operation(2, 3, Suma) << endl;
	cout << "Operation(2,3,  Dob): " << Operation(2, 3, Dob) << endl;

	system("Pause");
}