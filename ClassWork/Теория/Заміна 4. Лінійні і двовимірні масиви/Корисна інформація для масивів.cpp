#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int main()
{
	//Задача 1. “Обмін”.
	/*int a, b, c;
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter b = ";
	cin >> b;
	c = a;
	a = b;
	b = c;
	cout << "a = " << a << endl << "b = " << b << endl;*/



	//Задача 2. Функція з ОДЗ
	/*float y, x;
	cout << "Enter x -> ";
	cin >> x;
	if (x > -1 && x < 0 || x>0)
	{
		y = log(3) / log(x + 1);
		cout << "y = " << y << endl;
	}
	else
		cout << "Function doesn't exist" << endl;*/


	//Приклад 3. «Друк кратних чисел»
	/*int N;
	cout << "Enter N = ";
	cin >> N;
	for (int i = 100; i <= N; i++)
	{
		if (i % 3 == 0)
			cout << i << endl;
	}*/





	//Задача 8. ”Заміна елементів”. 
	/*int const n = 20;
	int cnt, A[n], i, x, y;
	cout << "Enter cnt = ";
	cin >> cnt;
	for (i = 0; i < cnt; i++)
	{
		cout << "Enter A[i] = ";
		cin >> A[i];
	}
	cout << "Enter x = ";
	cin >> x;
	cout << "Enter y = ";
	cin >> y;
	for (i = 0; i < cnt; i++)
	{
		if (x == A[i])
			A[i] = y;
	}
	for (i = 0; i < cnt; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/


	//Задача 9. «Сума та добуток елементів». 
	/*int const n = 20;
	double A[n], s = 0, d = 1;
	int i, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	for (i = 0; i < cnt; i++)
	{
		cout << "Enter A[" << i << "] = ";
		cin >> A[i];
	}
	for (i = 0; i < cnt; i++)
	{
		s = s + A[i];
		d = d * A[i];
	}
	cout << "Suma = " << s << endl;
	cout << "Dobutok = " << d << endl;*/



	//Задача 10. «Заповнення масиву квадратами».
	/*int const n = 20;
	double A[n];
	int i, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	
	for (i = 0; i < cnt; i++)
	{
		A[i] = pow(i + 1, 2);
	}
	for (i = 0; i < cnt; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/



	//Задача 11. «Кількість елементів». 
	/*int const n = 20;
	double A[n];
	int i, a, b = 0, cnt;
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter cnt = ";
	cin >> cnt;
	for (i = 0; i < cnt; i++)
	{
		cout << "Enter A[" << i << "] = ";
		cin >> A[i];
	}
	for (i = 0; i < cnt; i++)
	{
		if (A[i] > a)
			b++;
	}
	cout << "chisel bolshuh za a = " << a << " est' " << b << endl;*/


	//Задача 14. «Максимальне значення». 
	/*int const n = 20;
	double A[n];
	int i, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	for (i = 0; i < cnt/2; i++)
	{
		A[i] = 1;
	}
	for (i = cnt / 2; i < cnt; i++)
	{
		A[i] = 0;
	}
	for (i = 0; i < cnt; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/



	//Задача 14. «Максимальне значення». 
	/*int const n = 20;
	double A[n];
	int i, max, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	srand(time(NULL));
	for (i = 0; i < cnt; i++)
	{
		A[i] = rand() % 30;
		cout << A[i] << " ";
	}
	max = A[0];
	for (i = 1; i < cnt; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	cout << "Max = " << max << endl;*/




	//Задача 15. «Вставка елемента». 
	/*int const n = 20;
	double A[n];
	int i, k, x, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	cout << "Enter k = ";
	cin >> k;
	cout << "Enter x = ";
	cin >> x;
	srand(time(NULL));
	for (i = 0; i < cnt; i++)
	{
		A[i] = rand() % 30;
	}
	for (i = cnt + 1; i >= k; i--)
	{
		A[i] = A[i - 1];
	}
	A[k] = x;
	for (i = 0; i < cnt + 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;*/


	//Задача 16. «Вилучення елемента».
	/*int const n = 20;
	double A[n];
	int i, k, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	cout << "Enter k = ";
	cin >> k;
	srand(time(NULL));
	for (i = 0; i < cnt; i++)
	{
		A[i] = rand() % 30;
	}
	for (i = k + 1; i < cnt; i++)
	{
		A[i - 1] = A[i];
	}
	cnt = cnt - 1;
	for (i = 0; i < cnt; i++)
	{
		cout << A[i] << " ";
	}*/



	//Задача 20. "Кількість елементів".
	/*const int N = 5, M = 3;
	int A[N][M], i, j, a, b = 0;
	cout << "Enter a -> ";
	cin >> a;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][j]= 1 + rand() % 9;
			cout << A[i][j] << " ";
			if (A[i][j] % a == 0)
				b++;
		}
		cout << endl;
	}
	cout << "Kolichestvo chisel kratnuh chislu a " << b << endl;*/


	//Задача 21. ”Заміна елементів”. 
	/*const int N = 5, M = 3;
	double A[N][M], x, y;
	int i, j;
	cout << "Enter x = ";
	cin >> x;
	cout << "Enter y = ";
	cin >> y;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][j] = 1 + rand() % 9;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (A[i][j] == x)
				A[i][j] = y;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}*/



	//Задача 22. "Знаходження суми елементів". 
	/*const int N = 5, M = 3;
	double A[N][M], s = 0, a;
	int i, j;
	cout << "Enter a = ";
	cin >> a;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			A[i][j] = 1 + rand() % 9;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (A[i][j] == a)
				s = s + A[i][j];
		}
		cout << endl;
	}
	cout << "Suma = " << s << endl;*/

	//Числа Фибоначи
	/*int const n = 20;
	double A[n];
	int i, cnt;
	cout << "Enter cnt = ";
	cin >> cnt;
	A[0] = 1;
	A[1] = 1;
	for (i = 2; i < cnt; i++)
	{
		A[i] = A[i - 2] + A[i - 1];
	}
	for (i = 0; i < cnt; i++)
	{
		cout << A[i] << " ";
	}*/
	system("pause");
}