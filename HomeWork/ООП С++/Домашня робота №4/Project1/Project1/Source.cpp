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
	l.addelem(3, 1);
	l.print();
	l.removingstuff(2, 4);
	l.print();
	List<int> q = l;
	q.print();
	List<int> w;
	(w = q).print();
	system("pause");
}