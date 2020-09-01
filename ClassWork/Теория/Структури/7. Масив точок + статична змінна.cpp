#include <iostream>
#include <time.h>
using namespace std;

struct Tochka
{
	char name;
	double x;
	double y;
};

void PrintTochka(Tochka U)
{
	cout << U.name << "(" << U.x << "," << U.y << ")" << endl;
}



void RandTochka(Tochka &U)
{	
	static int index = 65;
	U.name = index++;
	U.x = 1 + double(rand() * 9) / RAND_MAX;
	U.y = 1 + double(rand() * 9) / RAND_MAX;
}

void main()
{
	srand(time(0));

	const int cnt = 10;
	Tochka Mas[cnt];
	for (int i = 0; i < cnt; i++)
		RandTochka(Mas[i]);

	for (int i = 0; i < cnt; i++)
		PrintTochka(Mas[i]);
	//RandTochka(A);
	//PrintTochka(A);

	system("Pause");
}