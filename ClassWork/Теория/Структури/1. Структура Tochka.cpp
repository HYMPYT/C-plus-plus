#include <iostream>
#include <time.h>
using namespace std;

struct Tochka {
	double x, y;
};

void main() 
{
	srand(time(0));
	Tochka A;
	A.x = 3.12;
	A.y = 2.71;

	cout << " A x: " << A.x << "\t y: " << A.y << endl;

	// уніфікована ініціалізація при оголошенні
	/* ініціалізація структури,	 аналогічно
	 B.x = 4.4;
	 B.y = 5.2; */
	Tochka B = {4.44, 5.24};
	cout << " B x: " << B.x << "\t y: " << B.y << endl;
	
	// Завдання: згенерувати для точки С 
	// випадкові дійсні значення з проміжку [-100, 100]
	Tochka C;
	C.x = -100 + (double)rand()/RAND_MAX * 200;
	C.y = -100 + (double)rand()/RAND_MAX * 200;

	cout << " C x: " << C.x << "\t y: " << C.y << endl;

	Tochka D;
	D.x = -100 + 0.01 * (rand() % 20000);
	D.y = -100 + 0.01 * (rand() % 20000);

	cout << " D x: " << D.x << "\t y: " << D.y << endl;

	Tochka E;
	// введення полів структури з клавіатури
	cout << " Enter E.x=";
	cin >> C.x;
	cout << " Enter C.y=";
	cin >> C.y;

	system("Pause");
}