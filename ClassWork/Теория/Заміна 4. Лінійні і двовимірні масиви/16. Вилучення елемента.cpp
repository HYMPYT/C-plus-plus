#include <iostream>
using namespace std;

// ������ 4. ���������� ��������. 
// �� �������� ������ �������� ������� � �������� k

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

	// 5. �������� ���������� �����
	int k; // ������ ��������, ���� ������ �������� k <= cnt
	cout << " Enter index k=";
	cin >> k;

	// 6. ������� ������ - ������� �������� ��������� � ������� k
	for (int i = k; i < cnt; i++)
		mas[i] = mas[i + 1];

	cnt--;  // ������� ��������, ������� ����������

	// 7. ��������� ����������
	// � ��� ������ ����������� � ��� �����
	// ��������� ������ (������� ����)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;

	system("pause");
}