#include <iostream>
using namespace std;

/* ������ 6. ����� �� ������� ��������. 
������ ���� �� ������� �������� �������� ������. */

void main()
{
	// 1. ���������� ������� ������
	const int size = 20;
	// size - ��������� ������ (�-�� �������������� ��������)
	double mas[size];
	
	// 2. �������� ������ ������� �������� cnt
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// 3. ����������� (��������) ������
	for (int i = 0; i < cnt; i++)
	{
		cout << " Enter mas[" << i << "]=";
		cin >> mas[i];
	}

	// 4. ��������� ������ (���������� ����)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	// ���������� ����� � ��� ������ ����
	
	// 6. ������� ������
	double suma = 0;
	double dobutok = 1;
	for (int i = 0; i < cnt; i++)
	{
		suma +=mas[i];
		dobutok *= mas[i];
	}

	// 7. ��������� ����������
	cout << "    suma: " << suma << endl;
	cout << " dobutok: " << dobutok << endl;
}