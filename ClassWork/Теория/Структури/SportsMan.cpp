#include <iostream>
#include <time.h>
using namespace std;

struct SportsMan {
	char surname[50];
	char name[50];
	int age;
	int place;
};

void PrintSportsMan(SportsMan A) {
	cout << A.surname << " " << A.name << " " << A.age << " " << A.place << endl;
}

void InputSportsMan(SportsMan &U) {	
	cout << " Enter place=";
	cin >> U.place;
	cin.ignore();
	cout << " Enter name=";
	cin.getline(U.name, 50);
	cout << " Enter surname=";
	cin.getline(U.surname, 50);	
	cout << " Enter age=";
	cin >> U.age;
}

void PrintArraytSportsMan(SportsMan MAS[], int cnt) {
	for (int i = 0; i < cnt; i++)
		PrintSportsMan(MAS[i]);
}

SportsMan MaxAge(SportsMan MAS[], int cnt) {
	int ind = 0;
	for (int i = 1; i < cnt; i++)
		if (MAS[i].age > MAS[ind].age)
			ind = i;
	return MAS[ind];
}

void main() {
	//srand(time(0));
	//SportsMan A = { "Shevchenko", "Andriy", 27, 2 };
	//PrintSportsMan(A);
	//SportsMan B;
	//InputSportsMan(B);
	//SportsMan C;
	//InputSportsMan(C);

	SportsMan Mas[4];
	Mas[0] = { "Shevchenko", "Andriy", 27, 2 };
	Mas[1] = { "Rebrov", "Serhiy", 29, 3 };
	Mas[2] = { "Bubka", "Serhiy", 43, 5 };
	Mas[3] = { "Klochkova", "Yana", 21, 1 };
	PrintArraytSportsMan(Mas, 4);
	cout << endl;

	SportsMan R = MaxAge(Mas, 4);
	PrintSportsMan(R);
	system("Pause");
}