#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*double x, y;
	cout << "������� �������� x -> ";
	cin >> x;
	y = -2.7*pow(x,3) + 0.23*pow(x,2) - 1.4;
	cout << "y = " << y << "\n";*/

	//2
	/*int chislo;
	cout << "������� ����������� ����� -> ";
	cin >> chislo;
	int soten = chislo / 100;
	chislo = chislo % 100;
	int desyatkov = chislo / 10;
	chislo = chislo % 10;
	int edinic = chislo;
	int summa_cifr = soten + desyatkov + edinic;
	int dobytok = soten * desyatkov * edinic;
	cout << "����� ����� -> " << soten;
	cout << "\n����� �������� -> " << desyatkov;
	cout << "\n����� ������ -> " << edinic;
	cout << "\n����� ��� ���� -> " << summa_cifr;
	cout << "\n������������ ��� ���� -> " << dobytok << "\n";*/

	//3
	/*const double const_d = 27.4339;
	const double const_r = 0.4043;
	const double const_e = 31.3131;
	double UAH, Dollar, Euro, Ruble;
	cout << "������� ����� ����� � ������� -> ";
	cin >> UAH;
	Dollar = UAH / const_d;
	Euro = UAH / const_e;
	Ruble = UAH / const_r;
	cout << "���������� �������� -> " << Dollar;
	cout << "\n���������� ���� -> " << Euro;
	cout << "\n���������� ������ -> " << Ruble << "\n";*/

	//4
	/*const double const_m = 100;
	double Height;
	double Height_metr;
	cout << "������� ���� ���� -> ";
	cin >> Height;
	Height_metr = Height / const_m;
	cout << "��� ���� � ���������� -> " << Height << " (��)";
	cout << "\n��� ���� � ������ -> " << Height_metr << " (�)\n";*/
	system("pause");
}