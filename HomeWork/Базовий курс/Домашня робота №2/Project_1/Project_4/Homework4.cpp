#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*float a;
	cout << "������� ����� -> ";
	cin >> a;
	if ((a >= 25) && (a <= 50))
	{
		cout << "�������� ����� ��������� � �������� �� 25 �� 50\n";
	}
	else
		cout << "�������� ����� �� ��������� � �������� �� 25 �� 50\n";*/

	//2
	/*int a;
	cout << "������� ����� ����� � ������� <Enter>\n";
	cin >> a;
	if (a % 3 == 0)
	{
		cout << "����� " << a << " ������� ������ �� ���.\n";
	}
	else
		cout << "����� " << a << " ������ �� ��� �� �������.\n";*/

	//3
	/*int min, sec;
	cout << "������� ���������� ����� ";
	cin >> min;
	cout << "������� ���������� ������ ";
	cin >> sec;
	if (sec > 60)
	{
		cout << "������! ���������� ������ �� ����� ���� ������ 60\n";
	}
	else
		cout << "����� ����� " << (min * 60) + sec << " ���.\n";*/

	//4
	/*int day, month, year, last;
	cout << "������� ������� ����������� ���� (�����, �����, ���) -> ";
	cin >> day >> month >> year;
	last = 0;
	if (month == 2) 
	{
		if ((year % 4) != 0 && day == 28) 
		{
			last = 1;
		}
		if ((year % 4) == 0 && day == 29) 
		{
			last = 1;
		}
	}
	else 
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) 
		{
			month++;
			day = 0;
			cout << "��������� ���� ������!\n";
		}
		else
			if (day == 31) 
			{
				last = 1;
			}
	if (last == 1) 
	{
		cout << "��������� ���� ������!\n";
		day = 1;
		if (month == 12) 
		{
			month = 1;
			year++;
			cout << "C ����������� ����� �����!\n";
		}
		else
			month++;
	}
	else
		day++;
	cout << "������ " << day << "." << month << "." << year << "\n";*/
	system("pause");
}
