#include<iostream>
using namespace std;
int main()
{
	setlocale(0, "rus");
	//1
	/*float a;
	cout << "Введите число -> ";
	cin >> a;
	if ((a >= 25) && (a <= 50))
	{
		cout << "Значение числа находится в пределах от 25 до 50\n";
	}
	else
		cout << "Значение числа не находится в пределах от 25 до 50\n";*/

	//2
	/*int a;
	cout << "Введите целое число и нажмите <Enter>\n";
	cin >> a;
	if (a % 3 == 0)
	{
		cout << "Число " << a << " делится нацело на три.\n";
	}
	else
		cout << "Число " << a << " нацело на три не делится.\n";*/

	//3
	/*int min, sec;
	cout << "Введите количество минут ";
	cin >> min;
	cout << "Введите количество секунд ";
	cin >> sec;
	if (sec > 60)
	{
		cout << "Ошибка! Количество секунд не может быть больше 60\n";
	}
	else
		cout << "Общие время " << (min * 60) + sec << " сек.\n";*/

	//4
	/*int day, month, year, last;
	cout << "Введите цифрами сегодняшнюю дату (число, месяц, год) -> ";
	cin >> day >> month >> year;
	last = 0;
	if (month == 2) 
	{
		if ((year % 4) != 0 && day == 28) 
		{
			last = 1;
		}
		if ((year % 4) == 0 && day == 29) 
		{
			last = 1;
		}
	}
	else 
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) 
		{
			month++;
			day = 0;
			cout << "Последний день месяца!\n";
		}
		else
			if (day == 31) 
			{
				last = 1;
			}
	if (last == 1) 
	{
		cout << "Последний день месяца!\n";
		day = 1;
		if (month == 12) 
		{
			month = 1;
			year++;
			cout << "C наступающим Новым годом!\n";
		}
		else
			month++;
	}
	else
		day++;
	cout << "Завтра " << day << "." << month << "." << year << "\n";*/
	system("pause");
}
