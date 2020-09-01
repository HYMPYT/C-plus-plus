#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
template <typename T>
double Arithmetic_mean(T A[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += A[i];
	}
	return sum / n;
}
template<typename T>
void equation(T a, T b, int k, T c = 0)
{
	if (k == 1)
	{
		if (a == 0)
		{
			cout << "”равнение решений не имеет" << endl;
			return;
		}
		cout << "x -> " << -b / a << endl;
	}
	if (k == 2)
	{
		T D = b * b - 4 * a * c;
		if (D < 0)
		{
			cout << " вадратное уравнение корней не имеет" << endl;
			return;
		}
		if (D == 0)
		{
			cout << "x -> " << -b / (2 * a) << endl;
		}
		else
		{
			cout << setprecision(4) << "x1 -> " << (-b - sqrtf(D)) / (2 * a) << endl;
			cout << setprecision(4) << "x2 -> " << (-b + sqrtf(D)) / (2 * a) << endl;
		}
	}
}
int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	//1
	/*const int n = 10;
	double A[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 21;
		cout << setw(4) << A[i];
	}
	cout << endl;
	cout << "Arithmetic mean the value of the array -> " << Arithmetic_mean(A, n) << endl;*/

	//2
	/*double a, b, c;
	int x;
	cout << "¬ыберите уравнение которое вам нужно" << endl;
	cout << "Ћинейное уравнение -> 1" << endl;
	cout << " вадратное уравнение -> 2" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "¬ведите коэффициенты:" << endl;
		cout << "¬ведите a -> ";
		cin >> a;
		cout << "¬ведите b -> ";
		cin >> b;
		equation(a, b, x);
		break;
	case 2:
		cout << "¬ведите коэффициенты:" << endl;
		cout << "¬ведите a -> ";
		cin >> a;
		cout << "¬ведите b -> ";
		cin >> b;
		cout << "¬ведите c -> ";
		cin >> c;
		equation(a, b, x, c);
		break;
	default:
		cout << "¬веден неверный номер" << endl;
		break;
	}*/
	system("pause");
}