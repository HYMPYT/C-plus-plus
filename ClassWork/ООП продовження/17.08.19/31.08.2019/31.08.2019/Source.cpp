#include<iostream>
#include<string>
#include<ctime>
#include"Kangaroo.h"
#include"Fish.h"
#include"Penguin.h"
using namespace std;
int main()
{
	srand(time(NULL));
	Animal *zoo[10];
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 4)
		{
		case 0:
			zoo[i] = new Penguin("Lolo");
			break;
		case 1:
			zoo[i] = new Bird("Kesha");
			break;
		case 2:
			zoo[i] = new Fish("Nemo");
			break;
		case 3:
			zoo[i] = new Kangaroo("Roo");
			break;
		}
	}
	for (Animal* item : zoo)
	{
		item->move();
	}
	for (auto item : zoo)
	{
		delete item;
	}
	/*Animal a("Animal");
	Bird b("Kesha");
	Fish c("Nemo");
	Kangaroo d("Roo");
	a.move();
	b.move();
	c.move();
	d.move();*/
	system("pause");
}
//астрактний клас це клас об'єткт якого не можна створити
//для того щоб клас став абстракним для потрібно описати хочаб одну віртуальну функцію
//чиста віртуальна функція описується як прототип прирівнений до нуля у чистої віртуальної функції не існує реалізації
//але кожен клас як наслідує абстракний клас зобов'язаний реалізувати всі його чисті функції