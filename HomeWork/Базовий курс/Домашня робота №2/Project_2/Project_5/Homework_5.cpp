#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	
	/*int variant;
	cout << "�������� �������\n";
	cout << "1. ����\n" << "2. �����\n" << "3. ����\n" << "4. �����\n";
	cout << ">>> ";
	cin >> variant;
	switch (variant)
	{
	case 1: 
		cout << "������ ������:\n";
		cout << "����\n" << "����\n" << "������\n";
		break;
	case 2: 
		cout << "������� ������:\n";
		cout << "��������\n" << "�������\n" << "������\n";
		break;
	case 3:
		cout << "������ ������:\n";
		cout << "�������\n" << "������\n" << "�������\n";
		break;
	case 4:
		cout << "�������� ������:\n";
		cout << "����\n" << "������\n" << "���\n";
		break;
	default:
		break;
	}*/

	//2
	
	/*int b;
	cout << "������� ����� ������ -> ";
	cin >> b;
	switch (b)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		cout << "� ���� ������ 31 ����\n";
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "� ���� ������ 30 ����\n";
		break;
	case 2: 
		cout << "� ���� ������ 28 ���� ��� 29 ���� ������ ���������� ���\n";
	default:
		cout << "������!!! ������ ������ �� ����������\n";
		break;
	}*/
	
	//3
	
	/*float a, b; 
	int variant;
	cout << "������� ��� ����� ����� ����� ������ -> ";
	cin >> a >> b;
	cout << "�������� �������\n";
	cout << "1.��������� ���� �����\n"
		<< "2.�������� ���� �����\n"
		<< "3.��������� ���� �����\n"
		<< "4.������� ���� �����\n"
		<< "5.���������� � �������\n"
		<< "6.���������� ��������\n"
		<< "7.���������� �����������\n";
	cout << ">>>> ";
	cin >> variant; 
	switch (variant)
	{
	case 1:
		cout << "a * b = " << a * b << "\n";
		break;
	case 2:
		cout << "a + b = " << a + b << "\n";
		break;
	case 3:
		cout << "a - b = " << a - b << "\n";
		break;
	case 4:
		if (b != 0)
			cout << "a / b = " << a / b << "\n";
		else
			cout << "������!!! �� ���� ������ ������\n";
		break;
	case 5:
		cout << "a ^ b = " << pow(a, b) << "\n";
		break;
	case 6:
		cout << "(a + b) / 2 = " << (a + b) / 2 << "\n";
		break;
	case 7:
		if (a > b)
		{
			cout << "a > b\n";
		}
		else
			cout << "b > a\n";
		break;
	default:
		cout << "������!!! ����� �������� ���\n";
		break;
	}*/
	system("pause");
}