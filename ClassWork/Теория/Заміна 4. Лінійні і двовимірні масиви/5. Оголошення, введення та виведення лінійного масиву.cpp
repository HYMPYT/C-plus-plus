#include <iostream>
using namespace std;

/* Приклад оголошення, введення та виведення 
	елементів лінійного масиву */

void main()
{
	// оголошення лінійного масиву
	const int size = 20;
	// size - розмірність масиву (к-ть зарезервованих елементів)
	int a[size];

	// cnt - робоча кількість елементів
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// введення лінійного масиву
	for (int i = 0; i < cnt; i++)
	{
		cout << " Enter a[" << i << "]=";
		cin >> a[i];
	}

	// виведення лінійного масиву
	for (int i = 0; i < cnt; i++)
		cout << " " << a[i];
	cout << endl;
}