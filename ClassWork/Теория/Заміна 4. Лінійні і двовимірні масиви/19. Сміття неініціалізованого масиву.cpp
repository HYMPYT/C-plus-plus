#include <iostream>
using namespace std;

// �������� 10. ����� ��������������� ������
void main()
{
	// 1. ���������� �� �Ͳֲ�˲��ֲ� ������
	const int row_size = 10;
	const int col_size = 15;
	double mas[row_size][col_size];
	// �������������� �����

	// 2. �������� ���̲������� ������
	int row, col;
	cout << " Enter row=";
	cin >> row;
	cout << " Enter col=";
	cin >> col;

	// 4. ��������� ������ (���������� ����)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << " " << mas[i][j];
		cout << endl;
	}
}