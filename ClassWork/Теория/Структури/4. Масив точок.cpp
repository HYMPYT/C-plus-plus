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

// випадкові дійсні значення з проміжку [-100, 100]
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
	Tochka MAS[10];
	for (int i = 0; i < 10; i++) {
		MAS[i].name = 65+i;
		MAS[i].x = i;
		MAS[i].y = i;
	}

	for (int i = 0; i < 10; i++) {
		cout << MAS[i].name;
		cout << " x: " << MAS[i].x << " ";
		cout << " y: " << MAS[i].y << endl;
	}
	
	system("Pause");
}