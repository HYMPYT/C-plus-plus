#include <iostream>
using namespace std;

/* ������ 5. ������ ��������. 
� �������� ����� ������� �� ��������, 
�� ��� �������� � �� �������� Y. */

void main()
{
	// 1. ���������� ������� ������
	const int size = 20;
	// size - ��������� ������ (�-�� �������������� ��������)
	double mas[size];
	
	// 2. �������� ������ ������� ��������
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

	// 5. �������� ���������� �����
	double x, y;
	cout << " Enter x=";
	cin >> x;
	cout << " Enter y=";
	cin >> y;
	
	// 6. ������� ������
	for (int i = 0; i < cnt; i++)
		if (mas[i] == x)
			mas[i] = y;

	// 7. ��������� ����������
	// � ��� ������ ����������� � ��� �����
	// ��������� ������ (������� ����)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;
}