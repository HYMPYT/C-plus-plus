#include<iostream>
#include "Tree.h"
using namespace std;
int main()
{
	Tree<int> a;
	a.insert(50);
	a.insert(30);
	a.insert(70);
	a.insert(20);
	a.insert(10);
	a.insert(40);
	a.insert(60);
	a.insert(80);
	a.insert(90);
	a.insert(100);
	a.print();
	cout << endl;
	a.del(a.getRoot());
	a.print();
	system("pause");
}