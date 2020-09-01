#include <iostream>
using namespace std;

// приклад масиву вказівників на функцію як параметра ф-ї

double Diff(double a, double b) { return a - b; }
double Suma(double a, double b) { return a + b; }
double Dob(double a, double b) { return a * b; }

void main()
{
	double(*operations[3])(double, double) = { Diff, Suma, Dob };

	int length = sizeof(operations) / sizeof(operations[0]);

	for (int i = 0; i < length; i++)
		cout << "Operation(4, 2): " << operations[i](4, 2) << endl;

	system("Pause");
}