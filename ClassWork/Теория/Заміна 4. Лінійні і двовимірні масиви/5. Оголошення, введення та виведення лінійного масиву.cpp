#include <iostream>
using namespace std;

/* ������� ����������, �������� �� ��������� 
	�������� ������� ������ */

void main()
{
	// ���������� ������� ������
	const int size = 20;
	// size - ��������� ������ (�-�� �������������� ��������)
	int a[size];

	// cnt - ������ ������� ��������
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// �������� ������� ������
	for (int i = 0; i < cnt; i++)
	{
		cout << " Enter a[" << i << "]=";
		cin >> a[i];
	}

	// ��������� ������� ������
	for (int i = 0; i < cnt; i++)
		cout << " " << a[i];
	cout << endl;
}