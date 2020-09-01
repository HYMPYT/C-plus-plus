#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	
	/*int variant;
	cout << "Выберите вариант\n";
	cout << "1. лето\n" << "2. осень\n" << "3. зима\n" << "4. весна\n";
	cout << ">>> ";
	cin >> variant;
	switch (variant)
	{
	case 1: 
		cout << "Летние месяцы:\n";
		cout << "Июнь\n" << "Июль\n" << "Август\n";
		break;
	case 2: 
		cout << "Осенние месяцы:\n";
		cout << "Сентябрь\n" << "Октябрь\n" << "Ноябрь\n";
		break;
	case 3:
		cout << "Зимние месяцы:\n";
		cout << "Декабрь\n" << "Январь\n" << "Февраль\n";
		break;
	case 4:
		cout << "Весенние месяцы:\n";
		cout << "Март\n" << "Апрель\n" << "Май\n";
		break;
	default:
		break;
	}*/

	//2
	
	/*int b;
	cout << "Введите номер месяца -> ";
	cin >> b;
	switch (b)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		cout << "В этом месяце 31 день\n";
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cout << "В этом месяце 30 дней\n";
		break;
	case 2: 
		cout << "В этом месяце 28 дней или 29 если сейчас высокосный год\n";
	default:
		cout << "Ошибка!!! Такого месяца не существует\n";
		break;
	}*/
	
	//3
	
	/*float a, b; 
	int variant;
	cout << "Введите два целых числа через пробел -> ";
	cin >> a >> b;
	cout << "Выберите вариант\n";
	cout << "1.умножение двух чисел\n"
		<< "2.сложение двух чисел\n"
		<< "3.вычитание двух чисел\n"
		<< "4.деление двух чисел\n"
		<< "5.возведение в степень\n"
		<< "6.нахождение среднего\n"
		<< "7.нахождение наибольшего\n";
	cout << ">>>> ";
	cin >> variant; 
	switch (variant)
	{
	case 1:
		cout << "a * b = " << a * b << "\n";
		break;
	case 2:
		cout << "a + b = " << a + b << "\n";
		break;
	case 3:
		cout << "a - b = " << a - b << "\n";
		break;
	case 4:
		if (b != 0)
			cout << "a / b = " << a / b << "\n";
		else
			cout << "Ошибка!!! На ноль делить нельзя\n";
		break;
	case 5:
		cout << "a ^ b = " << pow(a, b) << "\n";
		break;
	case 6:
		cout << "(a + b) / 2 = " << (a + b) / 2 << "\n";
		break;
	case 7:
		if (a > b)
		{
			cout << "a > b\n";
		}
		else
			cout << "b > a\n";
		break;
	default:
		cout << "Ошибка!!! Такой операции нет\n";
		break;
	}*/
	system("pause");
}