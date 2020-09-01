#include<iostream>
#include<ctime>
using namespace std;
union Test
{
	int a;
	short b;
};
struct Date
{
	unsigned day : 5;
	unsigned mounth : 4;
	unsigned year : 11;
};
void print_bit(char c)
{
	for (int i = 7; i >= 0 ; --i)
	{
		cout << ((c >> i) & 1);
	}
	cout << endl;
}
void print_bit(unsigned c)
{
	for (int i = 31; i >= 0; --i)
	{
		cout << ((c >> i) & 1);
	}
	cout << endl;
}
int main()
{
	/*short a;
	cin >> a;
	print_bit((unsigned)a);
	int num;
	num = a;
	cin >> a;
	print_bit((unsigned)a);
	num = (num << 16) | a;
	print_bit((unsigned)num);
	cout << ((num >> 16) & 0b1111111111111111) << endl;
	cout << (num & 0b1111111111111111) << endl;*/


	/*Test obj;
	obj.a = 5;
	cout << obj.b << endl;*/

	Date obj;
	obj.day = 25;
	obj.mounth = 5;
	obj.year = 2019;
	cout << obj.day << endl << obj.mounth << endl << obj.year << endl;
	system("pause");
}