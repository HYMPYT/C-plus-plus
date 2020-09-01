#include <iostream>
#include <time.h>
using namespace std;

struct Tochka {
	double x, y;
};

void PrintTochka(Tochka U) {
	cout << " x: " << U.x << "\t y: " << U.y << endl;
}

// �������� ���� �������� � ������� [-100, 100]
void RandTochka(Tochka &U) {
	U.x = -100 + (double)rand() / RAND_MAX * 200;
	U.y = -100 + (double)rand() / RAND_MAX * 200;
}

void InputTochka(Tochka &U) {
	cout << " Enter x=";
	cin >> U.x;
	cout << " Enter y=";
	cin >> U.y;
}

void main() 
{
	srand(time(0));
	Tochka A;
	A.x = 3.12;
	A.y = 2.71;
	PrintTochka(A);
	
	Tochka B = {4.44, 5.24};
	PrintTochka(B);
	
	// ��������: ����������� ��� ����� � 
	// �������� ���� �������� � ������� [-100, 100]
	Tochka C = {0, 0 };
	RandTochka(C);
	PrintTochka(C);

	Tochka D = { 0, 0 };
	InputTochka(D);
	PrintTochka(D);

	system("Pause");
}