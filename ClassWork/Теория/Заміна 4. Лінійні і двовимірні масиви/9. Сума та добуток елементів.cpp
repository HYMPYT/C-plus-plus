#include <iostream>
using namespace std;

/* Задача 6. «Сума та добуток елементів». 
Знайти суму та добуток елементів заданого масиву. */

void main()
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

	// додаткових даних в цій задачі немає
	
	// 6. обробка масиву
	double suma = 0;
	double dobutok = 1;
	for (int i = 0; i < cnt; i++)
	{
		suma +=mas[i];
		dobutok *= mas[i];
	}

	// 7. виведення результатів
	cout << "    suma: " << suma << endl;
	cout << " dobutok: " << dobutok << endl;
}