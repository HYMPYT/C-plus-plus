#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*int const n = 10;
	int A[n], i, a = -1;
	for (i = 0; i < n; i++)
	{
		A[i] = a + 2;
		a += 2;
	}
	for (i = 0; i < n; i++)
	{
		cout << "[" << i << "]" << " -> " << A[i] << endl;
	}
	cout << endl;*/

	//2
	/*int const n = 10;
	double A[n];
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "������� A[" << i << "] = ";
		cin >> A[i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/

	//3
	/*int const n = 10;
	double A[n], d = 1, max, min, min_i = 0;
	int i, b = 0;
	for (i = 0; i < n; i++)
	{
		cout << "������� A[" << i << "] = ";
		cin >> A[i];
		if (A[i] == 0)
			b++;
	}
	cout << "���������� ��������� ������ ���� -> " << b << endl;
	for (i = 0; i < n; i++)
	{
		d = d * A[i];
	}
	cout << "������������ ���� ��������� ������� -> " << d << endl;
	max = A[0];
	min = A[0];
	for (i = 1; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
		if (A[i] < min)
		{
			min = A[i];
			min_i = i;
		}
	}
	cout << "������������ ������� -> " << max << endl;
	cout << "������� ������������ �������� -> " << min_i << endl;*/

	//4
	/*int const n = 5;
	double A[n];
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "������� A[" << i << "] = ";
		cin >> A[i];
	}
	cout << "������������� �������� -> ";
	for (i = 0; i < n; i++)
	{
		if (A[i] >= 0)
			cout << A[i] << " ";
	}
	cout << endl << "������������� �������� -> ";
	for (i = 0; i < n; i++)
	{
		if (A[i] < 0)
			cout << A[i] << " ";
	}
	cout << endl;*/
	system("pause");
}