#include <iostream>
using namespace std;

/* ������. ��������� �������� �������, ���������� ���. */
void main()
{
	double x;
	cout << "Enter x=";
	cin >> x;

	// ������ 1
	if ((x + 1 > 0) && (x != 0))
	{
		// ���� ������� ����, ����������
		double y = log(3) / log(x + 1);
		cout << " y: " << y << endl;
	}
	else 
		cout << " Function does not exist " << endl;

	// ������ 2 - �������� �����
	if ((x <= -1) || (x == 0))
		cout << "Function does not exist" << endl;
	else
	{
		// ���� ������� ����, ����������
		double y = log(3) / log(x + 1);
		cout << "y: " << y << endl;
	}
	system("Pause");
}