#include <iostream>
using namespace std;
int product(int a, int b)
{
	return a * b;
}
int number_of_digits(int a)
{
	int b = 0;
	if (a < 10)
		return 1;
	else
	{
		while (a != 0)
		{
			a = a / 10;
			b++;
		}
		return b;
	}
}
int max_number(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int comparing_two_numbers(int a, int b)
{
	if (a == b)
		return 3;
	if (a > b)
		return 1;
	else
		return 2;
}
float product_1(float a, float b)
{
	return a * b;
}
float addition(float a, float b)
{
	return a + b;
}
float subtraction(float a, float b)
{
	return a - b;
}
float division(float a, float b)
{
	if (b == 0)
	{
		cout << "������!!! ������� �� ����" << endl;
		return false;
	}
	else
		return a / b;
}
int calculator(int x, float a, float b)
{
	switch (x)
	{
	case 1:
		cout << "�������� ���� ����� -> " << addition(a, b) << endl;
		break;
	case 2:
		cout << "������������ ���� ����� -> " << product_1(a, b) << endl;
		break;
	case 3:
		cout << "��������� ���� ����� -> " << subtraction(a, b) << endl;
		break;
	case 4:
		if (division(a, b) == 0)
			break;
		else
		{
			cout << "������� ���� ����� -> " << division(a, b) << endl;
			break;
		}
	default:
	{
		cout << "����� �������� ����!" << endl;
		return 0;
	}
	}
}
double Procent(double a, double procent)
{
	return a * procent / 100;
}
int main()
{
	setlocale(0, "rus");
	//1
	/*int a, b;
	cout << "������� ��� ����� ����� ����� ������ -> ";
	cin >> a >> b;
	cout << "������������ ���� ����� ����� " << product(a, b) << endl;*/

	//2
	/*int a;
	cout << "������� ����� ����� -> ";
	cin >> a;
	cout << "���������� ���� � ����� ����� " << number_of_digits(a) << endl;*/

	//3
	/*int a, b;
	cout << "������� ��� ����� ����� ����� ������ -> ";
	cin >> a >> b;
	cout << "������������ �� ���� ����� " << max_number(a, b) << endl;*/

	//4 
	/*int a, b;
	cout << "������� ��� ����� ����� ����� ������ -> ";
	cin >> a >> b;
	switch (comparing_two_numbers(a, b))
	{
		case 1:
		{
			cout << a << " > " << b << endl;
			break;
		}
		case 2: 
		{
			cout << a << " < " << b << endl;
			break;
		}
		case 3: 
		{
			cout << a << " = " << b << endl;
			break;
		}
	}*/

	//5
	/*double a, procent;
	cout << "������� ����� -> ";
	cin >> a;
	cout << "������� ������� -> ";
	cin >> procent;
	cout << "������� �� ����� -> " << Procent(a, procent) << endl;*/

	//6
	/*float a, b;
	int x;
	cout << "������� ��� ����� ����� ������ -> ";
	cin >> a >> b;
	cout << "�������� ���� ����� ������� 1" << endl;
	cout << "������������ ���� ����� ������� 2" << endl;
	cout << "��������� ���� ����� ������� 3" << endl;
	cout << "������� ���� ����� ������� 4" << endl;
	cout << "������� ����� �������� -> ";
	cin >> x;
	calculator(x, a, b);*/
	system("pause");
}