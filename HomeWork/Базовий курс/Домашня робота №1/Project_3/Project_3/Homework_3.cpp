#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*double x, y;
	cout << "Введите значение x -> ";
	cin >> x;
	y = -2.7*pow(x,3) + 0.23*pow(x,2) - 1.4;
	cout << "y = " << y << "\n";*/

	//2
	/*int chislo;
	cout << "Введите трехзначное число -> ";
	cin >> chislo;
	int soten = chislo / 100;
	chislo = chislo % 100;
	int desyatkov = chislo / 10;
	chislo = chislo % 10;
	int edinic = chislo;
	int summa_cifr = soten + desyatkov + edinic;
	int dobytok = soten * desyatkov * edinic;
	cout << "Число сотен -> " << soten;
	cout << "\nЧисло десятков -> " << desyatkov;
	cout << "\nЧисло единиц -> " << edinic;
	cout << "\nСумма его цифр -> " << summa_cifr;
	cout << "\nПроизведение его цифр -> " << dobytok << "\n";*/

	//3
	/*const double const_d = 27.4339;
	const double const_r = 0.4043;
	const double const_e = 31.3131;
	double UAH, Dollar, Euro, Ruble;
	cout << "Введите сумму денег в гривнах -> ";
	cin >> UAH;
	Dollar = UAH / const_d;
	Euro = UAH / const_e;
	Ruble = UAH / const_r;
	cout << "Количество долларов -> " << Dollar;
	cout << "\nКоличество евро -> " << Euro;
	cout << "\nКоличество рублей -> " << Ruble << "\n";*/

	//4
	/*const double const_m = 100;
	double Height;
	double Height_metr;
	cout << "Введите свой рост -> ";
	cin >> Height;
	Height_metr = Height / const_m;
	cout << "Ваш рост в саниметрах -> " << Height << " (см)";
	cout << "\nВаш рост в метрах -> " << Height_metr << " (м)\n";*/
	system("pause");
}