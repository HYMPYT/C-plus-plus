#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
double min_element(double A[], int n)
{
	double min = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}
void fill_the_array(double A[], int n)
{
	cout << "Заполните массив действительными числами" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]  ";
		cin >> A[i];
	}
}
void output_of_the_array(double A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}
double first_pos_max_element(double A[], int n)
{
	double max = A[0];
	int max_i = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			max_i = i;
		}
	}
	return max_i;
}
double last_pos_max_element(double A[], int n)
{
	double max = A[0];
	int max_i = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] >= max)
		{
			max = A[i];
			max_i = i;
		}
	}
	return max_i;
}
double product(double A[], int n)
{
	double d = 1;
	for (int i = 0; i < n; i++)
	{
		if ((int)A[i] % 2 != 0)
			d = d * A[i];
	}
	return d;
}
double sum(double A[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			s = s + A[i];
	}
	return s;
}
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	const int n = 5;
	double A[n];
	int i;
	fill_the_array(A, n);
	output_of_the_array(A, n);
	cout << endl;
	//1
	//cout << "Минимальный элемент -> " << min_element(A, n) << endl;

	//2
	//cout << "Позиция первого вхождения максимального элемента -> " << first_pos_max_element(A, n) << endl;

	//3
	//cout << "Позиция последнего вхождения максимального элемента -> " << last_pos_max_element(A, n) << endl;

	//4
	//cout << "Произведение нечетных элементов -> " << product(A, n) << endl;

	//5
	//cout << "Сумма элементов находящихся на четных позициях ->" << sum(A, n) << endl;
	system("pause");
}