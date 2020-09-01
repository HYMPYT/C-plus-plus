#include <iostream>
using namespace std;

/* Задача 9. «Кількість елементів». Дано лінійний масив дійсних чисел. Знайти кількість елементів, що більші за змінну А. */

void main()
{
{
	// 1. оголошення лінійного масиву
	const int size = 20;
	// size - розмірність масиву (к-ть зарезервованих елементів)
	double mas[size];
	
	// 2. Введення робочої кількості елементів cnt
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// 3. ініціалізація (введення) масиву
	for (int i = 0; i < cnt; i++)
	{
		cout << " Enter mas[" << i << "]=";
		cin >> mas[i];
	}

	// 4. виведення масиву (початковий стан)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	// 5. Введення додаткових даних
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. обробка масиву
	int count = 0;
	for (int i = 0; i < cnt; i++)
		if (mas[i] > a)
			count++;

	// 7. виведення результатів
	cout << " count: " << count<< endl;
}