#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*float a, s = 1;
	do {
		cout << "Введите число -> ";
		cin >> a;
		if (a >= 1)
			s = s * a;
	} while (a != 0);
	cout << "Резудьтат s = " << s << endl;*/

	//2
	/*int a, i = 0;
	cout << "Игра Угадай число." << endl << "Компьютер задумал число от 1 до 10." << endl << "Угадайте его за 5 попыток." << endl << "Введите число и нажмите <Enter>" << endl;
	do {
		cout << "-> ";
		cin >> a;
		if (a >= 0 && a < 7 || a>7 && a <= 10)
			cout << "Нет." << endl;
		else
			cout << "Вы выиграли! Поздравляю!" << endl;
		i++;
	} while (i != 5);*/

	//3
	/*int a, i = 0, b = 0;
	do {
		cout << "Введите целое число -> ";
		cin >> a;
		if (a > 0)
			i++;
		if (i == 3)
		{
			while (a!=0)
			{
				a = a / 10;
				b++;
			}
			cout << "Третье положительное число имеет " << b << " цифр." << endl;
		}
	} while (a != 0);*/
	
	//4
	/*int a, s = 0, d = 1;
	do {
		cout << "Введите число -> ";
		cin >> a;
		if (a > 0)
			s = s + a;
		if (a < 0)
			d = d * a;
	} while (a != 0);
	if (s > d)
		cout << "Сумма положительных больше произведения отрицательных " << s << " > " << d << endl;
	else
		cout << "Произведение отрицательных больше суммы положительных " << d << " > " << s << endl;*/

	//for
	//1
	/*float a = 0, min = 0, min_i = -1;
	for (int i = 1; i <= 10; i++)
	{
		cout << "Введите число -> ";
		cin >> a;
		if (a < 0 && ( min_i == -1||a > min))
		{
			min = a;
			min_i = i;
		}
	}
	if (min_i == -1)
	{
		cout << "Нету отрицательных чисел!";
	}
	else
	{
		cout << "Наибольшее отрицательное число " << min << " его порядковый номер " << min_i << endl;
	}*/

	//2
	/*int a, b, i;
	cout << "Введите два целых числа -> ";
	cin >> a >> b;
	if (a > b)
	{
		for (i = a; i > 0; i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				cout << "Наибольший общий делитель двух чисел -> " << i << endl;
				break;
			}
		}
	}
	else
	{
		for (i = b; i > 0; i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				cout << "Наибольший общий делитель двух чисел -> " << i << endl;
				break;
			}
		}
	}*/

	//3
	/*int a, n = 0, b = 0, s, s1 = 0;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Введите число -> ";
		cin >> a;
		n = a;
		s = 0;
		while (n != 0)
		{
			s += n % 10;
			n /= 10;
		}
		if (s > s1)
		{
			s1 = s;
			b = a;
		}
	}
	cout << "Число с наибольшей суммой цифр -> " << b << endl;*/
	system("pause");
}