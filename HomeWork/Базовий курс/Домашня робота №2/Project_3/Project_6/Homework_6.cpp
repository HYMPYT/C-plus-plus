#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1

	/*int a, b;
	cout << "������� ��� ����� ����� ������ -> ";
	cin >> a >> b;
	(a % b == 0) ? cout << "������ ����� ������� �������\n" : cout << "������ ����� �� ������� �������\n";*/

	//2

	/*float A, B, C;
	cout << "������� ��� ���������� -> ";
	cin >> A >> B >> C;
	((A < B)&&(A < C)&&(B < C)) ? cout << "A = " << 2 * A << " B = " << 2 * B << " C = " << 2 * C << "\n" : cout << "A = " << -1 * A << " B = " << -1 * B << " C = " << -1 * C << "\n";*/

	//3

	/*int A, B, C;
	cout << "������� ��� ���������� (��� ����������) -> ";
	cin >> A >> B >> C;
	(A == B) ? cout << "���������� ����� ����� -> 3\n" : (A == C) ? cout << "���������� ����� ����� -> 2\n" : (B == C) ? cout << "���������� ����� ����� -> 1\n" : cout << "���������� ����� ����� ���������� ���������� ��� ��� �� ��������� ������� ������\n";*/

	//4

	/*int A, B, C, AB, AC;
	cout << "������� ��� ����� -> ";
	cin >> A >> B >> C;
	AB = (A > B) ? A - B : B - A;
	AC = (A > C) ? A - C : C - A;
	(AB > AC) ? cout << "����� � ����������� ����� � A. ��������� -> " << AC << "\n" : cout << "����� B ����������� ����� � A. ��������� -> " << AB << "\n";*/
	system("pause");
}