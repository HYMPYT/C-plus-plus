#include <iostream>
using namespace std;

// Задача 4. «Вилучення елемента». 
// Із заданого масиву вилучити елемент з індексом k

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

	// 5. Введення додаткових даних
	int k; // індекс елемента, який будемо вилучати k <= cnt
	cout << " Enter index k=";
	cin >> k;

	// 6. обробка масиву - зсуваємо елементи починаючи з позиції k
	for (int i = k; i < cnt; i++)
		mas[i] = mas[i + 1];

	cnt--;  // елемент видалено, довжина зменшилася

	// 7. виведення результатів
	// в цій задачі результатом є сам масив
	// виведення масиву (кінцевий стан)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	system("pause");
}