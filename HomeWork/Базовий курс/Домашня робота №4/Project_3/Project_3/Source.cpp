#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	//1
	/*const int m = 3, n = 4;
	double A[m][n];
	int i, j, b = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = -20 + rand() % 31;
			if (A[i][j] < 0)
				b++;
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	cout << "Количество отрицательных элементов -> " << b << endl;*/

	//2
	/*const int n = 6;
	double A[n][n], B[n];
	int i, j, b = 0;
	cout << "Двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		B[i] = rand() % 11;
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 11;
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			for (j = 0; j < n; j++)
			{
				A[i][j] = B[j];
			}
		}
	}
	cout << endl << "Одномерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\t" << B[i];
	}
	cout << endl << "Измененный двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}*/

	//3
	/*const int m = 3, n = 4;
	double A[m][n];
	int i, j, d=1;
	cout << "Двумерный массив: " << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 5;
			if (A[i][j] != 0)
				d = d * A[i][j];
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	cout << "Произведение ненулевых элементов массива -> " << d << endl;*/

	//4
	/*const int n = 5;
	double A[n][n], b = 0;
	int i, j;
	cout << "Двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 11;
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		b = A[i][i];
		A[i][i] = A[i][n - 1 - i];
		A[i][n - 1 - i] = b;
	}
	cout << endl << "Измененный двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}*/

	//5
	/*const int n = 6;
	double A[n][n], b = 0;
	int i, j;
	cout << "Двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand() % 11;
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == 0 || i == 2 || i == 4)
			{
				b = A[i][j];
				A[i][j] = A[i + 1][j];
				A[i + 1][j] = b;
			}
		}
	}
	cout << endl << "Измененный двумерный массив: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "\t" << A[i][j];
		}
		cout << endl;
	}*/
	system("pause");
}