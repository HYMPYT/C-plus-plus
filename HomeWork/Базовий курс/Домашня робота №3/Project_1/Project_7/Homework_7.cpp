#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*int i = 1, a, b, s;
	cout << "������� ����� -> ";
	cin >> a;
	cout << "������� ������� -> ";
	cin >> b;
	s = a;
	while (i < b)
	{
		s = s * a;
		i++;
	}
	cout << "���� ����� " << a << " � ������� " << b << " = " << s << endl;*/

	//2
	/*int n, r, a;
	cout << "������� ����� -> ";
	cin >> n;
	a = n;
	r = n % 10;
	while (n /= 10)
	{
		r = r * 10 + n % 10;
	}
	if (a == r)
	{
		cout << "����� ���� ����������� -> " << a << endl;
	}
	else
		cout << "����� ������� �� ����� �� �������� �����������" << endl;*/

	//3
	/*float x = -4, y;
	cout << "\tx\t|\ty\t" << endl;
	cout << "---------------------------------" << endl;
	while (x >= -4 && x <= 4)
	{
		y = 2 * x*x - 5 * x - 8;
		cout << "\t" << x << "\t|\t" << y << "\t" << endl;
		x = x + 0.5;
	}*/

	//4
	/*int f = 0, f1 = 1, f2 = 1, n;
	cout << "������� ����� -> ";
	cin >> n;
	while (f1 <= n)
	{
		cout << f1 << " ";
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	cout << endl;*/
	system("pause");
}