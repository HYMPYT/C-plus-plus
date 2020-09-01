#include <iostream>
#include <time.h>
using namespace std;

// Приклади 9. Введення двовимірного масиву

void main()
{
	// 1. оголошення масиву
	// row_size і col_size визначають кількість зарезервованих елементів
	const int row_size = 15; // к-ть рядків
	const int col_size = 20; // к-ть стовпців
	double mas[row_size][col_size];

	// 2. Введення робочої кількості рядків і стовпців
	// row і col -  використані рядки і стовпці
	// (row <= row_size) && (col <=col_size)
	int row, col;
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 3. ініціалізація масиву (введення з клавіатури)
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cout << " Enter mas["<< i <<"]["<<j<<"]=";
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

	// 6. обробка масиву

	// 7. виведення результатів
	system("Pause");
}