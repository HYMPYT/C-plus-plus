#include <iostream>
#include <time.h>
using namespace std;

/* ������ 12. ������ ��������.
� �������� ����������� ����� ������� �� ��������,
�� ��� �������� � �� �������� Y. */

void main()
{
	// 1. ���������� ������
	// row_size � col_size ���������� ������� �������������� ��������
	const int row_size = 15; // �-�� �����
	const int col_size = 20; // �-�� ��������
	double mas[row_size][col_size];

	// 2. �������� ������ ������� ����� � ��������
	// row � col - ������� ���������� ����� � �������
	// (row <= row_size) && (col <=col_size)
	int row, col;
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 3. ����������� ������ (�������� � ���������)
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cout << " Enter mas[" << i << "][" << j << "]=";
			cin >> mas[i][j];
		}

	// 4. ��������� ������ � ������ ������� (���������� ����)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << " " << mas[i][j];
		cout << endl;
	}
	cout << endl;

	// 5. �������� ���������� �����
	double x, y;
	cout << " Enter x=";
	cin >> x;
	cout << " Enter y=";
	cin >> y;

	// 6. ������� ������
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (mas[i][j] == x)
				mas[i][j] = y;

	// 7. ��������� ����������
	// � ��� ������ ����������� � ��� �����
	// ��������� ������ (������� ����)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << " " << mas[i][j];
		cout << endl;
	}
	cout << endl;

	system("Pause");
}