#include <iostream>
#include <time.h>
using namespace std;

struct Tochka {
	char name;
	double x, y;
};

void PrintTochka(Tochka U) {
	cout << U.name;
	cout << " x: " << U.x << " ";
	cout << " y: " << U.y << endl;
}

// �������� ���� �������� � ������� [-100, 100]
void RandTochka(Tochka &U) {
	U.name = 65 + rand() % 25; // 'A'+ 25
	U.x = -100 + (double)rand() / RAND_MAX * 200;
	U.y = -100 + (double)rand() / RAND_MAX * 200;
}

void InputTochka(Tochka &U) {
	cout << " Enter name=";
	cin >> U.name;
	cout << " Enter x=";
	cin >> U.x;
	cout << " Enter y=";
	cin >> U.y;
}

void main() 
{
	srand(time(0));
	Tochka A;
	A.name = 'A';
	A.x = 3.12;
	A.y = 2.71;
	PrintTochka(A);
	
	// ���������� ����������� ��� ���������
	Tochka B = {'B', 4.44, 5.24};
	PrintTochka(B);
	
	// ��������: ����������� ��� ����� � 
	// �������� ���� �������� � ������� [-100, 100]
	Tochka C = { 'C', 0, 0 };
	RandTochka(C);
	PrintTochka(C);

	Tochka D = {'D', 0, 0 };
	InputTochka(D);
	PrintTochka(D);

	system("Pause");
}