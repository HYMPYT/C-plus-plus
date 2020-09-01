#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{

	Tree<int> tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(90);
	tree.insert(10);
	tree.insert(44);
	tree.insert(80);
	tree.insert(100);
	tree.print(tree.getRoot());
	tree.del(tree.find(70));
	cout << endl;

	tree.print(tree.getRoot());
	cout << endl;
	cout << "\nSize tree-> " << tree.getSize(tree.getRoot(), 0);

	Tree<int> TREE;
	TREE = tree;
	cout << endl;
	TREE.print(TREE.getRoot());
	cout << "\nSize TREE-> " << TREE.getSize(TREE.getRoot(), 0) << endl;

	system("pause");
}