#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Test.h"
using namespace std;
int main()
{
	/*Test<int> a(123);
	Test<int> c(15);
	Test<double> b(1.23);
	a.print();
	(a+c).print();
	b.print();

	char s1[] = { "Hello " }, s2[] = { "World" };
	Test <char*> str_1(s1), str_2(s2);
	str_1.print();
	str_2.print();
	(str_1 + str_2).print();*/

	Test<int*> arr(15);
	for(int i = 0; i<15; i++)
	{
		arr[i] = rand() % 20;
	}
	Test<int*> mas(15);
	for (int i = 0; i < 15; i++)
	{
		mas[i] = rand() % 20;
	}
	(arr + mas).print();
	system("pause");
}