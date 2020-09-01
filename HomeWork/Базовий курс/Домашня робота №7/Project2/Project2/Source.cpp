#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
void print_array(int *arr, int size);
void fill_array(int *arr, int size, int A, int B);
void SortMass(int arr[], int size);
int main()
{
	srand(time(NULL));
	//1
	/*int n;
	cout << "Enter n -> ";
	cin >> n;
	int *arr = new int[n];
	fill_array(arr, n, 10, 20);
	cout << "Mas -> ";
	print_array(arr, n);
	delete[]arr;*/

	//2
	/*const int n = 10;
	int arr[n], b = 0;
	fill_array(arr, n, 0, 5);
	cout << "Mas 1 -> ";
	print_array(arr, n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			b++;
	}
	int *mas = new int[b];
	for (int i = 0, j = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			mas[j] = arr[i];
			j++;
		}
	}
	cout << "Mas 2 -> ";
	print_array(mas, b);
	delete[]mas;*/
	
	//3 программа работает через раз

	/*const int n = 10;
	int arr[n], mas[n], b = 2 * n, t = 0;
	fill_array(arr, n, 0, 10);
	fill_array(mas, n, 0, 10);
	SortMass(arr, n);
	SortMass(mas, n);
	cout << "Arr -> ";
	print_array(arr, n);
	cout << "Mas -> ";
	print_array(mas, n);
	int *res = new int[b];
	int k = 0, i, j;
	for (i = 0, j = 0; i < n && j < n;)
	{
		if (mas[j] == arr[i])
		{
			res[k] = arr[i];
			res[k + 1] = mas[j];
			k = k + 2;
			if (i < n)
				i++;
			if (j < n)
				j++;
			continue;
		}
		if (arr[i] < mas[j])
		{
			res[k] = arr[i];
			k++;
			if (i < n)
				i++;
			continue;
		}
		if (mas[j] < arr[i])
		{
			res[k] = mas[j];
			k++;
			if (j < n)
				j++;
			continue;
		}
	}
	cout << "Res -> ";
	print_array(res, b);
	delete[]res;*/

	//4
	/*const int n = 10;
	int arr[n], mas[n], b = 0;
	fill_array(arr, n, -25, 25);
	fill_array(mas, n, -25, 25);
	cout << "Arr -> ";
	print_array(arr, n);
	cout << "Mas -> ";
	print_array(mas, n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			b = b + 1;
		if (mas[i] > 0)
			b = b + 1;
	}
	int *res = new int[b];
	for (int i = 0, j = 0; i < n, j < b; i++)
	{
		if (arr[i] > 0)
		{
			res[j] = arr[i];
			j++;
		}
		if (mas[i] > 0)
		{
			res[j] = mas[i];
			j++;
		}
	}
	cout << "Res -> ";
	print_array(res, b);
	delete[]res;*/

	//5
	/*const int n = 10;
	int arr[n], mas[n];
	fill_array(arr, n, 5, 20);
	fill_array(mas, n, 5, 20);
	cout << "Mas 1 -> ";
	print_array(arr, n);
	cout << "Mas 2 -> ";
	print_array(mas, n);
	SortMass(arr, n);
	SortMass(mas, n);
	int b = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i] == mas[j])
			{
				if (arr[i + 1] != arr[i])
				{
					++b;
					break;
				}
			}
		}
	}
	int* res = new int[b];
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i] == mas[j])
			{
				if (arr[i + 1] != arr[i])
				{
					res[k] = mas[j];
					++k;
					break;
				}
			}
		}
	}
	cout << "Res -> ";
	print_array(res, b);
	delete[]res;*/

	//6
	/*int n = 20, b = 0;
	int *arr = new int[n];
	fill_array(arr, n, 1, 9);
	cout << "Mas 1 -> ";
	print_array(arr, n);
	SortMass(arr, n);
	cout << "Sort mas 1 -> ";
	print_array(arr, n);
	if (arr[0] == arr[1] && arr[1] != arr[2])
		b++;
	for (int i = 1; i < 18; i++)
	{
		if (arr[i] == arr[i + 1] && arr[i] != arr[i + 2] && arr[i] != arr[i - 1])
			b++;
	}
	if (arr[19] == arr[18] && arr[18] != arr[17])
		b++;
	int* mas = new int[b];
	int k = 0;
	if (arr[0] == arr[1] && arr[1] != arr[2]) 
	{
		mas[k] = arr[0];
		++k;
	}
	for (int i = 1; i < 18; i++)
	{
		if (arr[i] == arr[i + 1] && arr[i] != arr[i + 2] && arr[i] != arr[i - 1]) {
			mas[k] = arr[i];
			++k;
		}
	}
	if (arr[19] == arr[18] && arr[18] != arr[17])
		mas[k] = arr[19];
	delete[]arr;
	cout << "Mas 2 -> ";
	print_array(mas, b);
	delete[]mas;*/
	system("pause");
}
void print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl;
}
void fill_array(int *arr, int size, int A, int B)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = A + rand() % (B - A + 1);
	}
}
void SortMass(int arr[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}