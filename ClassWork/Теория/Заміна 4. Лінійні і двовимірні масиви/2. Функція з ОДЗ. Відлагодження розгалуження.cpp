#include <iostream>
using namespace std;

/* Задача. Обчислити значення функції, враховуючи ОДЗ. */
void main()
{
	double x;
	cout << "Enter x=";
	cin >> x;

	// варіант 1
	if ((x + 1 > 0) && (x != 0))
	{
		// якщо функція існує, обчислюємо
		double y = log(3) / log(x + 1);
		cout << " y: " << y << endl;
	}
	else 
		cout << " Function does not exist " << endl;

	// варіант 2 - обернена умова
	if ((x <= -1) || (x == 0))
		cout << "Function does not exist" << endl;
	else
	{
		// якщо функція існує, обчислюємо
		double y = log(3) / log(x + 1);
		cout << "y: " << y << endl;
	}
	system("Pause");
}