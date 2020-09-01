#include <iostream>
using namespace std;

// ������ 3. �������� ���������. 
// � ������� ����� �������� �� k-�� ���� �������� �.

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
	int k; // ������ ������ ��������
	cout << " Enter index k=";
	cin >> k;
	double x; // �������� ������ ��������
	cout << " Enter value x=";
	cin >> x;

	// 6. ������� ������ - ������� ������� �������� � ����
	for (int i = cnt; i > k; i--)
		mas[i] = mas[i - 1]; 

	mas[k] = x; // ���������� �������� �� ������� � �������� k
	
	cnt++;  // ������� ���������, ������� ����������

	// 7. ��������� ����������
	// � ��� ������ ����������� � ��� �����
	// ��������� ������ (������� ����)
	cout << " Array mas: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << mas[i];
	cout << endl;
}