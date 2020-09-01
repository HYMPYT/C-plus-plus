#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	List<int> l;
	l.pushBack(123);
	l.pushBack(34);
	l.pushBack(54);
	l.pushBack(1234);
	l.pushBack(45);
	l.addelem(1, 1);
	l.print();
	l.remove_elem(4);
	l.print();
	List<int> a = l;
	a.print();
	List<int> b = move(l);
	b.print();
	system("pause");
}