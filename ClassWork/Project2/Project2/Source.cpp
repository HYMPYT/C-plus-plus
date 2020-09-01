#include <iostream>
using namespace std;
int sum(int x, int y)
{
	return x + y;
}
int rizn(int x, int y)
{
	return x - y;
}
int dob(int x, int y)
{
	return x * y;
}
int operetion(int x, int y, int(*s)(int x, int y))
{
	int res = s(x, y);
	return res;
}
int main()
{
	int x = 5, y = 3;
	int(*s[3])(int, int) = { sum, rizn, dob };
	for (int i = 0; i < size(s); i++)
	{
		cout << "Opereshion -> " << s[i](x, y) << endl;
	}
	cout << "Operetion suma -> " << operetion(x, y, sum) << endl;
	cout << "Operetion diff -> " << operetion(x, y, rizn) << endl;
	cout << "Operetion dob -> " << operetion(x, y, dob) << endl;
	system("pause");
}
//тип змінної це властивість комірки яка визначає розмір коммірки. значення які можна в цю крмірку записати.
//операції які можна виконувати над змінною.
//типи змінних 1 - визначені програмістом. 2 - стандартні
