// ���������� ������� �������
#include <iostream>
using namespace std;

/* ������ 1. �����. ������ ���� � � �.
���������� �������� ����� �� �������. */

void main()
{
	// 1. �������� �������Ҳ�
	double a, b;
	cout << " Enter a=";
	cin >> a;
	cout << " Enter b=";
	cin >> b;

	// 2. ����������
	double c = a;
	a = b;
	b = c;

	// 3. ��������� ����������
	cout << " a: " << a << endl;
	cout << " b: " << b << endl;

	system("Pause"); // �������� ����������
}