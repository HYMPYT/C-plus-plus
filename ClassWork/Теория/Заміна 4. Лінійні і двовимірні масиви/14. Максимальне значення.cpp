#include <iostream>
#include <time.h>
using namespace std;

/* ������ 1. ������������� �������.
���� ������ �����. ������ �������� ���������� ��������. */

void main()
{
	srand(time(0));
	// 1. ���������� ������� ������
	const int size = 20;
	// size - ��������� ������ (�-�� �������������� ��������)
	double mas[size];

	// 2. �������� ������ ������� �������� cnt 
	int cnt; // cnt <= size
	cout << " Enter cnt=";
	cin >> cnt;

	// 3. ����������� (�����������) ������
	for (int i = 0; i < cnt; i++)
		mas[i] = rand() % 21 - 10; // -10 .. 10

	// 4. ��������� ������ (���������� ����)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	// ���������� ����� ����

	// 6. ������� ������
	double max = mas[0];
	for (int i = 1; i < cnt; i++)
		if (mas[i] > max)
			max = mas[i];

	// 7. ��������� ����������
	cout << " max: " << max << endl;
}