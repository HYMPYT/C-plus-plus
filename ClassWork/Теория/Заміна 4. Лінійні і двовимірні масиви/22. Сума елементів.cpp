#include <iostream>
using namespace std;

/* ������ 13. "����������� ���� ��������".
������ ������� Y ������� n*m.
������ ���� ��� �������� �������, �� ��� �������� a. */

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
	double a;
	cout << " Enter a=";
	cin >> a;

	// 6. ������� ������
	double suma = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (mas[i][j] == a)
				suma += mas[i][j];

	// 7. ��������� ����������
	cout << " suma: " << suma << endl;
	cout << endl;

	system("Pause");
}