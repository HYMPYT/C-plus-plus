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

void main()
{
	srand(time(0));
	Time X = { 4, 2, 3};
	PrintTime(X);
	Time Y = RandTime();
	PrintTime(Y);
	system("Pause");
}