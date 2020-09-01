#include <iostream>
using namespace std;
int product(int a, int b)
{
	return a * b;
}
int number_of_digits(int a)
{
	int b = 0;
	if (a < 10)
		return 1;
	else
	{
		while (a != 0)
		{
			a = a / 10;
			b++;
		}
		return b;
	}
}
int max_number(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int comparing_two_numbers(int a, int b)
{
	if (a == b)
		return 3;
	if (a > b)
		return 1;
	else
		return 2;
}
float product_1(float a, float b)
{
	return a * b;
}
float addition(float a, float b)
{
	return a + b;
}
float subtraction(float a, float b)
{
	return a - b;
}
float division(float a, float b)
{
	if (b == 0)
	{
		cout << "Ошибка!!! Деление на ноль" << endl;
		return false;
	}
	else
		return a / b;
}
int calculator(int x, float a, float b)
{
	switch (x)
	{
	case 1:
		cout << "Сложение двух чисел -> " << addition(a, b) << endl;
		break;
	case 2:
		cout << "Произведение двух чисел -> " << product_1(a, b) << endl;
		break;
	case 3:
		cout << "Вычитание двух чисел -> " << subtraction(a, b) << endl;
		break;
	case 4:
		if (division(a, b) == 0)
			break;
		else
		{
			cout << "Деление двух чисел -> " << division(a, b) << endl;
			break;
		}
	default:
	{
		cout << "Такой операции нету!" << endl;
		return 0;
	}
	}
}
double Procent(double a, double procent)
{
	return a * procent / 100;
}
int main()
{
	setlocale(0, "rus");
	//1
	/*int a, b;
	cout << "Введите два целых числа через пробел -> ";
	cin >> a >> b;
	cout << "Произведение двух целых чисел " << product(a, b) << endl;*/

	//2
	/*int a;
	cout << "Введите целое число -> ";
	cin >> a;
	cout << "Количество цифр в целом числе " << number_of_digits(a) << endl;*/

	//3
	/*int a, b;
	cout << "Введите два целых числа через пробел -> ";
	cin >> a >> b;
	cout << "Максимальное из двух чисел " << max_number(a, b) << endl;*/

	//4 
	/*int a, b;
	cout << "Введите два целых числа через пробел -> ";
	cin >> a >> b;
	switch (comparing_two_numbers(a, b))
	{
		case 1:
		{
			cout << a << " > " << b << endl;
			break;
		}
		case 2: 
		{
			cout << a << " < " << b << endl;
			break;
		}
		case 3: 
		{
			cout << a << " = " << b << endl;
			break;
		}
	}*/

	//5
	/*double a, procent;
	cout << "Введите число -> ";
	cin >> a;
	cout << "Введите процент -> ";
	cin >> procent;
	cout << "Процент от числа -> " << Procent(a, procent) << endl;*/

	//6
	/*float a, b;
	int x;
	cout << "Введите два числа через пробел -> ";
	cin >> a >> b;
	cout << "Сложение двух чисел нажмите 1" << endl;
	cout << "Произведение двух чисел нажмите 2" << endl;
	cout << "Вычитание двух чисел нажмите 3" << endl;
	cout << "Деление двух чисел нажмите 4" << endl;
	cout << "Введите номер операции -> ";
	cin >> x;
	calculator(x, a, b);*/
	system("pause");
}