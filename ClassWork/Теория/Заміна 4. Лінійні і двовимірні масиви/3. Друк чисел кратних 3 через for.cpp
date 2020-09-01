#include <iostream>
using namespace std;

// задача: вивести числа від 100 до N, які кратні 3
void main()
{
	int N;
	cout << " Enter N=";
	cin >> N;

	// спосіб 1 (проходимо всі числа, вибираємо кратні)
	for (int i = 100; i <= N; i++)
		if (i % 3 == 0) // вибираються лише кратні 3
			cout << " " << i;
	cout << endl;

	// спосіб 2 (проходимо лише кратні числа )
	// оптимальне рішення
	for (int i = 102; i <= N; i += 3)
		cout << " " << i;
	cout << endl;	
}