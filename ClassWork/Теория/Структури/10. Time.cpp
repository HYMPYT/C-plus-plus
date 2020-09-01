#include <iostream>
#include <time.h>
using namespace std;

struct Time {
	int h, m, s;
};

// друк часу A
void PrintTime(Time A) {
	if (A.h < 10) cout << "0";
	cout << A.h << ":";
	if (A.m < 10) cout << "0";
	cout << A.m << ":";
	if (A.s < 10) cout << "0";
	cout << A.s << endl;
}

// функція генерування часу, яка повертає час як результат 
Time RandTime() {
	Time U;
	U.h = rand() % 24;
	U.m = rand() % 60;
	U.s = rand() % 60;
	return U;
}

//  перевести час А в секунди
int ToSeconds(Time A) {
	return A.s + A.m * 60 + A.h * 3600;
}

// перевести секунди s в час і повернути як результат 
Time ToTime(int s) {
	Time X;
	X.h = s / 3600;
	X.m = s % 3600 / 60;
	X.s = s % 60;
	return X;
}

void RandArrayTime(Time MAS[], int cnt) {
	for (int i = 0; i < cnt; i++)
		MAS[i] = RandTime();
}

void PrintArrayTime(Time MAS[], int cnt) {
	for (int i = 0; i < cnt; i++)
		PrintTime(MAS[i]);
}

// ф-я повертає найбільший час як результат
Time MaxTime(Time MAS[], int cnt) {
	int ind = 0;
	for (int i = 1; i < cnt; i++)
		if (ToSeconds(MAS[i]) > ToSeconds(MAS[ind]))
			ind = i;
	return MAS[ind];
}

// додати всі елементи масиву і повернути час як результат
Time TotalTime(Time MAS[], int cnt) {
	int suma = 0;
	for (int i = 0; i < cnt; i++)
		suma += ToSeconds(MAS[i]);
	return ToTime(suma);
}

void main() {
	srand(time(0));
	Time Z = { 14, 30, 20 };
	PrintTime(Z);
	Time Y = { 1, 1, 1 };
	PrintTime(Y);
	cout << " ToSeconds(Y): " << ToSeconds(Y) << endl;
	Time X = RandTime();
	PrintTime(X);
	Time A = ToTime(7262);
	PrintTime(A);
	cout << endl;

	int cnt = 8;
	Time *Mas = new Time[cnt];
	RandArrayTime(Mas, cnt);
	PrintArrayTime(Mas, cnt);
	Time MT = MaxTime(Mas, cnt);
	cout << endl;
	PrintTime(MT);
	system("Pause");
}