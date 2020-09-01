// підключення зовнішніх бібліотек
#include <iostream>
using namespace std;

/* Задача 1. “Обмін”. Задано змінні А і В.
Побудувати алгоритм обміну їх значень. */

void main()
{
	// 1. ВВЕДЕННЯ АРГУМЕНТІВ
	double a, b;
	cout << " Enter a=";
	cin >> a;
	cout << " Enter b=";
	cin >> b;

	// 2. ОБЧИСЛЕННЯ
	double c = a;
	a = b;
	b = c;

	// 3. ВИВЕДЕННЯ РЕЗУЛЬТАІВ
	cout << " a: " << a << endl;
	cout << " b: " << b << endl;

	system("Pause"); // затримка результатів
}