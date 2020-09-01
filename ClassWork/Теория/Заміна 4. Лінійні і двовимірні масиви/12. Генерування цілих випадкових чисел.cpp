#include <iostream>
#include <time.h>
using namespace std;

// Приклад 3. Генерування цілих випадкових чисел 0 .. 32767

void main()
{
	srand(time(0));
	// функція srand(int) задає точку відліку(номер елемента) для rand() 
	/* для того, щоб точка відліку була випадковою, її прив'язують до часу */

	// RAND_MAX - це стандартна константа 32767
	cout << " RAND_MAX: " << RAND_MAX << endl;

	int u = rand();
	cout << " u: " << u << endl;

	int h = rand();
	cout << " h: " << h << endl;

	const int size = 12;
	double x[size];
	int cnt = 10;

	for (int i = 0; i < cnt; i++)
		x[i] = rand(); // генерування значень 0 .. 32767

	cout << " Array x: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << x[i];
	cout << endl;

	// ВВЕДЕННЯ діапазону значень
	int a, b;
	cout << " Enter a=";
	cin >> a;
	cout << " Enter b=";
	cin >> b;

	for (int i = 0; i < cnt; i++)
		x[i] = a + rand() % (b - a + 1);
	// -200 + rand() % 401; // генерування значень з проміжку -200 .. 200

	cout << " Array x: ";
	for (int i = 0; i < cnt; i++)
		cout << " " << x[i];
	cout << endl;
}