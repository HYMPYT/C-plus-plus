#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*float a, s = 1;
	do {
		cout << "������� ����� -> ";
		cin >> a;
		if (a >= 1)
			s = s * a;
	} while (a != 0);
	cout << "��������� s = " << s << endl;*/

	//2
	/*int a, i = 0;
	cout << "���� ������ �����." << endl << "��������� ������� ����� �� 1 �� 10." << endl << "�������� ��� �� 5 �������." << endl << "������� ����� � ������� <Enter>" << endl;
	do {
		cout << "-> ";
		cin >> a;
		if (a >= 0 && a < 7 || a>7 && a <= 10)
			cout << "���." << endl;
		else
			cout << "�� ��������! ����������!" << endl;
		i++;
	} while (i != 5);*/

	//3
	/*int a, i = 0, b = 0;
	do {
		cout << "������� ����� ����� -> ";
		cin >> a;
		if (a > 0)
			i++;
		if (i == 3)
		{
			while (a!=0)
			{
				a = a / 10;
				b++;
			}
			cout << "������ ������������� ����� ����� " << b << " ����." << endl;
		}
	} while (a != 0);*/
	
	//4
	/*int a, s = 0, d = 1;
	do {
		cout << "������� ����� -> ";
		cin >> a;
		if (a > 0)
			s = s + a;
		if (a < 0)
			d = d * a;
	} while (a != 0);
	if (s > d)
		cout << "����� ������������� ������ ������������ ������������� " << s << " > " << d << endl;
	else
		cout << "������������ ������������� ������ ����� ������������� " << d << " > " << s << endl;*/

	//for
	//1
	/*float a = 0, min = 0, min_i = -1;
	for (int i = 1; i <= 10; i++)
	{
		cout << "������� ����� -> ";
		cin >> a;
		if (a < 0 && ( min_i == -1||a > min))
		{
			min = a;
			min_i = i;
		}
	}
	if (min_i == -1)
	{
		cout << "���� ������������� �����!";
	}
	else
	{
		cout << "���������� ������������� ����� " << min << " ��� ���������� ����� " << min_i << endl;
	}*/

	//2
	/*int a, b, i;
	cout << "������� ��� ����� ����� -> ";
	cin >> a >> b;
	if (a > b)
	{
		for (i = a; i > 0; i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				cout << "���������� ����� �������� ���� ����� -> " << i << endl;
				break;
			}
		}
	}
	else
	{
		for (i = b; i > 0; i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				cout << "���������� ����� �������� ���� ����� -> " << i << endl;
				break;
			}
		}
	}*/

	//3
	/*int a, n = 0, b = 0, s, s1 = 0;
	for (int i = 1; i <= 5; i++)
	{
		cout << "������� ����� -> ";
		cin >> a;
		n = a;
		s = 0;
		while (n != 0)
		{
			s += n % 10;
			n /= 10;
		}
		if (s > s1)
		{
			s1 = s;
			b = a;
		}
	}
	cout << "����� � ���������� ������ ���� -> " << b << endl;*/
	system("pause");
}