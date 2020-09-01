#include<iostream>
#include"List.h"
using namespace std;

int main()
{
	List<int> l;
	l.pushBack(123);
	l.pushBack(3);
	l.pushBack(54);
	l.pushBack(1234);
	l.pushFront(45);
	l.print();
	l.popFront();
	l.print();
	l.popBack();
	l.print();
	system("pause");
}