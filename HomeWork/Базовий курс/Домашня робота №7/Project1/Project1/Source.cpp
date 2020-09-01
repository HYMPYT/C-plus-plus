#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
void filling_array(int *arr, int a)
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
		cout << arr[i] << " ";
	}
	cout << endl;
}
void remove_paired_items(int *&arr, int &a)
{
	int b = 0;
	for (int i = 0; i < a; i++)
	{
		if (arr[i] % 2 == 0)
		{
			b++;
		}
	}
	int *tmp = new int[a - b];
	for (int i = 0, j = 0; i < a; i++)
	{
		if (arr[i] % 2 != 0)
		{
			tmp[j] = arr[i];
			j++;
		}
	}
	a = a - b;
	delete[]arr;
	arr = tmp;
}
void add_new_item(int *&arr, int &a, int k, int val)
{
	if ((k >= 0) && (k < a))
	{
		int *tmp = new int[++a];
		for (int i = 0; i < k; i++)
		{
			tmp[i] = arr[i];
		}
		tmp[k] = val;
		for (int i = k + 1; i < a; i++)
		{
			tmp[i] = arr[i - 1];
		}
		delete[]arr;
		arr = tmp;
	}
}
void remove_numbers_in_the_range(int *&arr, int &a, int m, int n)
{
	if (n > m)
	{
		int b = a - (n - m) - 1;
		int *tmp = new int[b];
		for (int i = 0; i < m; i++)
		{
			tmp[i] = arr[i];
		}
		for (int i = n + 1, j = m; i < a; i++)
		{
			tmp[j] = arr[i];
			j++;
		}
		a = a - (n - m) - 1;
		delete[]arr;
		arr = tmp;
	}
	else
	{
		int b = a - (m - n) - 1;
		int *tmp = new int[b];
		for (int i = 0; i < n; i++)
		{
			tmp[i] = arr[i];
		}
		for (int i = m + 1, j = n; i < a; i++)
		{
			tmp[j] = arr[i];
			j++;
		}
		a = a - (m - n) - 1;
		delete[]arr;
		arr = tmp;
	}
}
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	int a = 10;
	int *arr = new int[a];
	filling_array(arr, a);

	//1
	/*cout << "‘ункци€ дл€ удалени€ четных чисел:" << endl;
	cout << endl;
	cout << "ѕервый массив -> ";
	print_array(arr, a);
	remove_paired_items(arr, a);*/

	//2
	/*int val, k;
	cout << "¬ведите число -> ";
	cin >> val;
	cout << "¬ведите позицию на которую вы хотите поставить элемент -> ";
	cin >> k;
	cout << endl;
	cout << "ѕервый массив -> ";
	print_array(arr, a);
	add_new_item(arr, a, k, val);*/

	//3
	/*int m, n;
	cout << "¬ведите диапазон от m до n:" << endl;
	cout << "¬ведите m -> ";
	cin >> m;
	cout << "¬ведите n -> ";
	cin >> n;
	cout << endl;
	cout << "ѕервый массив -> ";
	print_array(arr, a);
	remove_numbers_in_the_range(arr, a, m, n);*/

	cout << endl;
	cout << "¬торой массив -> ";
	print_array(arr, a);
	cout << endl;
	delete[]arr;
	system("pause");
}