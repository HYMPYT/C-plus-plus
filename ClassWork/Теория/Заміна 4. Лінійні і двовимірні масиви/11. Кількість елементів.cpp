#include <iostream>
using namespace std;

/* ������ 9. �ʳ������ ��������. ���� ������ ����� ������ �����. ������ ������� ��������, �� ����� �� ����� �. */

void main()
{
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

	// 5. �������� ���������� �����
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. ������� ������
	int count = 0;
	for (int i = 0; i < cnt; i++)
		if (mas[i] > a)
			count++;

	// 7. ��������� ����������
	cout << " count: " << count<< endl;
}