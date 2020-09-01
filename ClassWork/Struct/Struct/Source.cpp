#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
struct Time
{
	int h;
	int m;
	int s;
};
int Toseconds(Time A)
{
	return A.s + A.m * 60 + A.h * 3600;
}
Time ToTime(int s)
{
	Time X;
	X.h = s / 3600;
	X.m = s % 3600 / 60;
	X.s = s % 3600 % 60;
	return X;
}
Time TotalTime(Time mas[], int cnt)
{
	int s = 0;
	for (int i = 0; i < cnt; i++)
	{
		s += Toseconds(mas[i]);
	}
	return ToTime(s);
}
void print_time(Time A)
{
	if (A.h < 10)
		cout << "0";
	cout << A.h << ":";
	if (A.m < 10)
		cout << "0";
	cout << A.m << ":";
	if (A.s < 10)
		cout << "0";
	cout << A.s << endl;
}
Time randomTime()
{
	Time A;
	A.h = rand() % 24;
	A.m = rand() % 60;
	A.s = rand() % 60;
	return A;
}
void RandArrayTime(Time mas[], int cnt)
{
	for (int i = 0; i < cnt; i++)
		mas[i] = randomTime();
}
void PrintArrayTime(Time mas[], int cnt)
{
	for (int i = 0; i < cnt; i++)
		print_time(mas[i]);
}
struct tochka
{
	char name;
	double x, y;
};
void print_tochka(tochka B)
{
	cout << B.name << " (" << setprecision(5) << B.x << ", " << setprecision(5) << B.y << ")" << endl;
}
void Enter_tochka(tochka &B)
{
	cout << "Enter name -> ";
	cin >> B.name;
	cout << "Enter B.x -> ";
	cin >> B.x;
	cout << "Enter B.y -> ";
	cin >> B.y;
}
void random_tochka(tochka &B)
{
	B.name = 'A' + rand() % 26;
	B.x = -100 + rand() % 201;
	B.y = -100 + rand() % 201;
}
void random_double_tochka(tochka &B)
{
	static int n = 'A';
	B.name = n++;
	B.x = -100 + double(200) *rand() / RAND_MAX;
	B.y = -100 + double(200) *rand() / RAND_MAX;
}
int main()
{
	srand(time(NULL));
	Time U;
	/*U = randomTime();
	print_time(U);
	cout << Toseconds(U) << endl;
	U = ToTime(1234);
	print_time(U);*/
	int cnt = 8;
	Time *mas = new Time[cnt];
	RandArrayTime(mas, cnt);
	U = TotalTime(mas, cnt);
	print_time(U);
	/*tochka A, B;
	A.x = 1.12;
	A.y = 3.24;
	cout << "A.x -> " << A.x << endl << "A.y -> " << A.y << endl;
	Enter_tochka(B);
	print_tochka(B);
	random_tochka(B);
	print_tochka(B);
	random_double_tochka(B);
	print_tochka(B);*/
	/*tochka mas[10];
	for (int i = 0; i < size(mas); i++)
	{
		random_double_tochka(mas[i]);
	}
	for (int i = 0; i < size(mas); i++)
	{
		print_tochka(mas[i]);
	}*/
	system("pause");
}