#include <iostream>
using namespace std;

/* Сміття неініціалізованого масиву */

void main()
{
	// оголошення лінійного масиву
	int x[10];
	int y[10];

	// виведення лінійного масиву
	for (int i = 0; i < 10; i++)
		cout << " " << x[i];
	cout << endl;
}