#include <iostream>
#include <time.h>
using namespace std;

/* Задача 11. "Кількість елементів".
Задано цілочисельну матрицю Y розміром n*m.
Знайти кількість тих елементів матриці, що рівні заданому a. */

void main()
{
	srand(time(0));

	// 1. оголошення масиву
	// row_size і col_size визначають кількість зарезервованих елементів
	const int row_size = 30; // к-ть рядків
	const int col_size = 20; // к-ть стовпців
	int mas[row_size][col_size];
	
	// 2. Введення робочої кількості рядків і стовпців
	// row і col - реально використані рядки і стовпці
	int row, col; // (row <= row_size) && (col <=col_size)
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 3. генерування дійсного масиву
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mas[i][j] = -10 + rand() % 21; // -10 .. 10	
	// генеруємо дійсні числа як цілі

	// 4. виведення масиву у вигляді матриці (початковий стан)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << "\t" << mas[i][j];
		cout << endl;
	}

	// 5. Введення додаткових даних
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. обробка масиву
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (mas[i][j] % a == 0)
				cnt++;

	// 7. виведення результатів
	cout << " Count: " << cnt << endl;
}