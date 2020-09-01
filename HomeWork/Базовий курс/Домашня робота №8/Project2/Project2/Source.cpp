#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void del_element(int *&arr, int &a, int k)
{
	if (k < a&&k >= 0)
	{
		int *tmp = new int[a];
		for (int i = 0; i < k; i++)
		{
			tmp[i] = arr[i];
		}
		for (int i = k + 1; i < a; i++)
		{
			tmp[i - 1] = arr[i];
		}
		delete[]arr;
		arr = tmp;
		a = a - 1;
	}
	else
		cout << "Ошыбка! Такой позиции не существует." << endl;
}
void fill_array(int *arr, int a)
{
	for (int i = 0; i < a; i++)
	{
		arr[i] = -5 + rand() % 11;
	}
}
void print_array(int *arr, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << setw(3) << arr[i];
	}
	cout << endl;
}
void print_matrix(int **arr, int row, int colum)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colum; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	cout << endl;
}
int sum(int **arr, int *col, int i)
{
	int s = 0;
	for (int j = 0; j < col[i]; j++)
	{
		s = s + arr[i][j];
	}
	return s;
}
int main()
{
	srand(time(NULL));
	setlocale(0, "rus");
	//1
	/*int a = 10, k;
	int *arr = new int[a];
	fill_array(arr, a);
	cout << "Массив до изменений -> ";
	print_array(arr, a);
	cout << "Введите позицию елемента который нужно удалить -> ";
	cin >> k;
	del_element(arr, a, k);
	cout << "Массив после удаления елемента -> ";
	print_array(arr, a);
	delete[]arr;*/

	//2
	//int row, colum;
	//cout << "Введите количество строк -> ";
	//cin >> row;
	//cout << "Введите количество столбцов -> ";
	//cin >> colum;
	//int **arr = new int *[row];
	//for (int i = 0; i < row; i++)
	//{
	//	arr[i] = new int[colum];
	//}
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < colum; j++)
	//		arr[i][j] = 3 + rand() % 10;
	//}
	//cout << "Матрица до изменений: " << endl;
	//print_matrix(arr, row, colum);

	////a
	///*for (int j = 0; j < colum; j++)
	//{
	//	int i = 0;
	//	while (i < row - 1)
	//	{
	//		swap(arr[i][j], arr[i + 1][j]);
	//		i += 2;
	//	}
	//}
	//cout << "Матрица после того как мы поменяли четные и нечетные строки: " << endl;
	//print_matrix(arr, row, colum);*/

	////b
	///*for (int i = 0; i < row; i++)
	//{
	//	int j = 0;
	//	while (j < colum - 1)
	//	{
	//		swap(arr[i][j], arr[i][j + 1]);
	//		j += 2;
	//	}
	//}
	//cout << "Матрица после того как мы поменяли четные и нечетные столбцы: " << endl;
	//print_matrix(arr, row, colum);*/
	//for (int i = 0; i < row; i++)
	//{
	//	delete[]arr[i];
	//}
	//delete[]arr;

	//3
	/*int row;
	cout << "Введите количество строк -> ";
	cin >> row;
	int **arr = new int*[row];
	int *col = new int[row];
	for (int i = 0; i < row; i++)
	{
		col[i] = 5 + rand() % 6;
		arr[i] = new int[col[i]];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			arr[i][j] = rand() % 101;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}
	int max_i = 0, max = sum(arr, col, 0);
	int b = 0;
	cout << "Сумма [" << 0 << "] -> " << max << endl;
	for (int i = 1; i < row; i++)
	{
		b = sum(arr, col, i);
		if (b > max)
		{
			max = b;
			max_i = i;
		}
		cout << "Сумма [" << i << "] -> " << b << endl;
	}
	cout << "Номер строки, сумма элементов которой является максимальной -> " << max_i << endl;
	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	delete[]col;*/
	system("pause");
}