#include <iostream>
#include <time.h>
using namespace std;

// ������� 7. ����������� ����������� ������ ��� ���������
void main()
{
	// ����������� ����������� ������ ��� ���������
	int b[4][4] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << " " << b[i][j];
		cout << endl;
	}
	cout << endl;

	// ��������� ��������������� ����������� ������ - �����
	int c[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << " " << c[i][j];
		cout << endl;
	}
	cout << endl;
	system("Pause");
}