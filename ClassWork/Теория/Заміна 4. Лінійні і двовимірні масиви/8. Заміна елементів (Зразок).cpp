#include <iostream>
using namespace std;

/* Задача 5. ”Заміна елементів”. 
У заданому масиві замінити всі елементи, 
що рівні значенню Х на значення Y. */

void main()
{
	// 1. оголошення лінійного масиву
	const int size = 20;
	// size - розмірність масиву (к-ть зарезервованих елементів)
	double mas[size];
	
	// 2. Введення робочої кількості елементів
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
	double x, y;
	cout << " Enter x=";
	cin >> x;
	cout << " Enter y=";
	cin >> y;
	
	// 6. обробка масиву
	for (int i = 0; i < cnt; i++)
		if (mas[i] == x)
			mas[i] = y;

	// 7. виведення результатів
	// в цій задачі результатом є сам масив
	// виведення масиву (кінцевий стан)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;
}