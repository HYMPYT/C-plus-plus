#include <iostream>
using namespace std;

// Приклади 10. Сміття неініціалізованого масиву
void main()
{
	// 1. ОГОЛОШЕННЯ ТА ІНІЦІАЛІЗАЦІЯ МАСИВУ
	const int row_size = 10;
	const int col_size = 15;
	double mas[row_size][col_size];
	// неініціалізований масив

	// 2. ВВЕДЕННЯ РОЗМІРНОСТЕЙ МАСИВУ
	int row, col;
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 4. ВИВЕДЕННЯ МАСИВУ (початковий стан)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << " " << mas[i][j];
		cout << endl;
	}
}