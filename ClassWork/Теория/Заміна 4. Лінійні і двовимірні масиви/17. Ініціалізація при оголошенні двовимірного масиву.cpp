#include <iostream>
#include <time.h>
using namespace std;

// Приклад 7. Ініціалізація двовимірного масиву при оголошенні
void main()
{
	// ініціалізація двовимірного масиву при оголошенні
	int b[4][4] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << " " << b[i][j];
		cout << endl;
	}
	cout << endl;

	// виведення неініціалізованого двовимірного масиву - сміття
	int c[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << " " << c[i][j];
		cout << endl;
	}
	cout << endl;
	system("Pause");
}