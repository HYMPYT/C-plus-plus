#include <iostream>
#include <time.h>
using namespace std;

// Приклад 5. Генерування дійсних випадкових чисел
void main()
{
	srand(time(0));
	// функція srand(int) задає точку відліку(номер елемента) для rand() 
	/* для того, щоб точка відліку була випадковою, її прив'язують до часу */

	double c = (double)rand() / 32767;
	/* Генерування дійсних випадкових чисел від 0 до 1 */
	cout << "c: " << c << endl;

	// ВВЕДЕННЯ діапазону значень
	double a, b;
	cout << " Enter a=";
	cin >> a;
	cout << " Enter b=";
	cin >> b;

	// ГЕНЕРУВАННЯ ОДНОВИМІРНОГО МАСИВУ
	const int size = 12;
	double x[size];
	for (int i = 0; i < size; i++)
		/* Генерування дійсних випадкових чисел від a до b   [a,b] */
		x[i] = (double)rand() * (b - a) / RAND_MAX + a;
	/* Генерування дійсних випадкових чисел від 0 до 1 */
	// x[i] = (double)rand() / 32767;  

	for (int i = 0; i < size; i++)
		cout << " " << x[i];
	cout << endl;
}