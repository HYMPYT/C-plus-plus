#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*int const n = 10;
	double A[n], b = 0;
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = -5 + rand() % 11;
	}
	cout << "Исходный массив -> ";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	for (i = 0; i < n / 2; i++)
	{
		b = A[i];
		A[i] = A[n - 1 - i];
		A[n - 1 - i] = b;
	}
	cout << endl << endl << "Измененный массив -> ";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/

	//2
	/*int const n = 10;
	int A[n], i, k;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 11;
	}
	cout << "Исходный массив -> \t";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << "Укажите индекс элемента для удаления -> ";
	cin >> k;
	for (i = k + 1; i < n; i++)
	{
		A[i - 1] = A[i];
	}
	A[9] = 0;
	cout << "Измененный массив -> \t";
	for (i = 0; i < n - 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/

	//3
	/*int const n = 10;
	int A[n], i, max_i, max = 0;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = -9 + rand() % 20;
	}
	cout << "Исходный массив -> \t";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		int b = A[i];

		for (int j = 0; j < n; ++j)
		{
			if (A[j] == b)
			{
				k++;
			}
		}
		if (k > max)
		{
			max = k;
			max_i = i;
		}
	}
	cout << endl << "Чаще всего встречается элемент -> " << A[max_i] << endl;*/

	//4
	/*int const n = 10;
	int A[n], i, k, b;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = 1 + rand() % 10;
	}
	cout << "Исходный массив -> \t";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << "Укажите шаг сдвига -> ";
	cin >> k;
	for (i = 0; i < k; ++i)
	{
		b = A[n - 1];
		for (int j = n - 1; j > 0; j--)
			A[j] = A[j - 1];
		A[0] = b;
	}
	cout << "Измененный массив -> \t";
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/
	system("pause");
}