#include <iostream>
#include <time.h>
using namespace std;

/* Задача 1. «Максимальний елемент».
Дано лінійний масив. Знайти значення найбільшого елемента. */

void main()
{
	srand(time(0));
	// 1. оголошення лінійного масиву
	const int size = 20;
	// size - розмірність масиву (к-ть зарезервованих елементів)
	double mas[size];

	// 2. Введення робочої кількості елементів cnt 
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// 3. ініціалізація (генерування) масиву
	for (int i = 0; i < cnt; i++)
		mas[i] = rand() % 21 - 10; // -10 .. 10

	// 4. виведення масиву (початковий стан)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	// додаткових даних немає

	// 6. обробка масиву
	double max = mas[0];
	for (int i = 1; i < cnt; i++)
		if (mas[i] > max)
			max = mas[i];

	// 7. виведення результатів
	cout << " max: " << max << endl;
}