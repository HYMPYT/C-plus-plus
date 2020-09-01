#include <iostream>
using namespace std;
int sum_range(int min, int max)
{
	if (min > max)
		return 0;
	if (min <= max)
		return max + sum_range(min, max - 1);
	else
		return 0;
}
void direct_order(int x) 
{
	if (x % 10 == x) 
	{
		cout << x << endl;
		return;
	}
	direct_order(x / 10);
	cout << x % 10 << endl;
}
int fibonachi(int n) 
{
	int sum = 0;
	if (n <= 0) 
		return 1;
	else 
		return sum = fibonachi(n - 1) + fibonachi(n - 2);
}
int fib(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	setlocale(0, "rus");
	//1
	/*int x;
	cout << "¬ведите число -> ";
	cin >> x;
	direct_order(x);*/

	//2
	/*int min, max;
	cout << "¬ведите граници" << endl;
	cout << "min -> ";
	cin >> min;
	cout << "max -> ";
	cin >> max;
	cout << "—умма чисел в заданном диапазоне -> " << sum_range(min, max) << endl;*/

	//3
	/*int n;
	cout << "¬ведите число n - > ";
	cin >> n;
	cout << "—умма n чисел ‘ибоначчи -> " << fibonachi(n) - 1 << endl;*/

	//4
	/*int n;
	cout << "¬ведите n -> ";
	cin >> n;
	for (int i = 0; i < n; ++i)
		cout << fib(i) << ' ';*/
	system("pause");
}