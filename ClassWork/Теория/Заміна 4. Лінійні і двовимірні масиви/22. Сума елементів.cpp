#include <iostream>
using namespace std;

/* Задача 13. "Знаходження суми елементів".
Задано матрицю Y розміром n*m.
Знайти суму тих елементів матриці, що рівні заданому a. */

void main()
{
	// 1. оголошення масиву
	// row_size і col_size визначають кількість зарезервованих елементів
	const int row_size = 15; // к-ть рядків
	const int col_size = 20; // к-ть стовпців
	double mas[row_size][col_size];

	// 2. Введення робочої кількості рядків і стовпців
	// row і col - реально використані рядки і стовпці
	// (row <= row_size) && (col <=col_size)
	int row, col;
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 3. ініціалізація масиву (введення з клавіатури)
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cout << " Enter mas[" << i << "][" << j << "]=";
			cin >> mas[i][j];
		}

	// 4. виведення масиву у вигляді матриці (початковий стан)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << " " << mas[i][j];
		cout << endl;
	}
	cout << endl;

	// 5. Введення додаткових даних
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. обробка масиву
	double suma = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (mas[i][j] == a)
				suma += mas[i][j];

	// 7. виведення результатів
	cout << " suma: " << suma << endl;
	cout << endl;

	system("Pause");
}