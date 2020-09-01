#include <iostream>
using namespace std;

double Suma(double a, double b) { return a + b; }
double Diff(double a, double b) { return a - b; }
double  Dob(double a, double b) { return a * b; }

void main() {
	// приклад оголошення вказівника на фукнцію
	double(*fp[3])(double, double);

	// прив'язка вказівника до ф-ї
	fp[0] = Suma;
	// виклик через вказівник ф-ї, на яку він вказує
	cout << " Suma(6,2): " << fp[0](6, 2) << endl;

	fp[1] = Diff;
	cout << " Diff(6,2): " << fp[1](6, 2) << endl;

	fp[2] = Dob;
	cout << "  Dob(6,2): " << fp[2](6, 2) << endl;

	system("Pause");
}