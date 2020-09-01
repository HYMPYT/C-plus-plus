#include <iostream>
#include <time.h>
using namespace std;

struct Time {
	int h, m, s;
};

void PrintTime(Time X) {
	X.h < 10 ? cout << "0" << X.h : cout << X.h;
	cout << ":";
	X.m < 10 ? cout << "0" << X.m : cout << X.m;
	cout << ":";
	X.s < 10 ? cout << "0" << X.s : cout << X.s;
	cout << endl;
}

Time RandTime() {
	Time A;
	A.h = rand() % 24;
	A.m = rand() % 60;
	A.s = rand() % 60;
	return A;
}

void RandArrayTime(Time MAS[], int cnt) {
	for (int i = 0; i < cnt; i++)
		MAS[i] = RandTime();
}

void PrintArrayTime(Time MAS[], int cnt) {
	for (int i = 0; i < cnt; i++) 
		PrintTime(MAS[i]);
}

void main() 
{
	srand(time(0));
	Time Z = { 14, 30, 20 };
	PrintTime(Z);
	Time Y = { 8, 5, 5 };
	PrintTime(Y);
	Time X = RandTime();
	PrintTime(X);
	cout << endl;

	int cnt = 8;
	Time *Mas = new Time[cnt];
	RandArrayTime(Mas, cnt);
	PrintArrayTime(Mas, cnt);
	system("Pause");
}