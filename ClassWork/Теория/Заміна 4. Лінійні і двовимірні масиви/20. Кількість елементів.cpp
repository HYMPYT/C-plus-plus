#include <iostream>
#include <time.h>
using namespace std;

/* ������ 11. "ʳ������ ��������".
������ ������������ ������� Y ������� n*m.
������ ������� ��� �������� �������, �� ��� �������� a. */

void main()
{
	srand(time(0));

	// 1. ���������� ������
	// row_size � col_size ���������� ������� �������������� ��������
	const int row_size = 30; // �-�� �����
	const int col_size = 20; // �-�� ��������
	int mas[row_size][col_size];
	
	// 2. �������� ������ ������� ����� � ��������
	// row � col - ������� ���������� ����� � �������
	int row, col; // (row <= row_size) && (col <=col_size)
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 3. ����������� ������� ������
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mas[i][j] = -10 + rand() % 21; // -10 .. 10	
	// �������� ���� ����� �� ���

	// 4. ��������� ������ � ������ ������� (���������� ����)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << "\t" << mas[i][j];
		cout << endl;
	}

	// 5. �������� ���������� �����
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. ������� ������
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (mas[i][j] % a == 0)
				cnt++;

	// 7. ��������� ����������
	cout << " Count: " << cnt << endl;
}