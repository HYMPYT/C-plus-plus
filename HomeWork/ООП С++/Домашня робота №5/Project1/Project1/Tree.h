#pragma once
#include <iostream>
#include"Node.h"
template <class T>
class Tree
{
	Node<T>*root = nullptr;
public:
	Tree() = default;
	Tree(const Tree&);
	Tree(Tree &&obj);
	~Tree();

	void insert(T);
	void del(Node<T>*);
	void copy(Node<T>*);
	void print(Node<T> *);
	void print();
	Node<T> *find(T);
	int getSize(Node<T> *node, int);

	Node<T>*getRoot();
	Node<T>*getMin(Node<T>*);
	Node<T> *getMax(Node<T> *);
	Node<T>*getNext(Node<T>*);

	Tree<T>& operator=(const Tree<T> &obj);
	Tree<T>& operator= (Tree &&obj);
};
template <class T>
Tree<T>::Tree(Tree &&obj)
{
	std::swap(root, obj.root);
}
template <class T>
Node<T>* Tree<T>::getRoot()
{
	return root;
}
template <class T>
Tree<T>::Tree(const Tree & obj)
{
	copy(obj.root);
}
template<class T>
Tree<T>::~Tree()
{
	if (root)
	{
		while (root->getLeft())
		{
			del(getMin(root));
		}
		while (root->getRight())
		{
			del(getMax(root));
		}
		delete root;
	}
}
template <class T>
void Tree<T>::insert(T val)
{
	Node<T>* tmp = new Node<T>(val);
	if (root == nullptr)
	{
		root = tmp;
		return;
	}
	Node<T>*cur;
	Node<T>*prev = nullptr;
	cur = root;
	while (cur)
	{
		prev = cur;
		if (val < cur->getData())
			cur = cur->getLeft();
		else
			cur = cur->getRight();
	}
	tmp->setParent(prev);
	if (val < prev->getData())
		prev->setLeft(tmp);
	else
		prev->setRight(tmp);
}
template <class T>
void Tree<T>::print(Node<T>* node)
{
	if (node == nullptr)
		return;
	print(node->getLeft());
	std::cout << node->getData() << " ";
	print(node->getRight());
}
template <class T>
void Tree<T>::print()
{
	print(root);
}
template <class T>
void Tree<T>::copy(Node<T>*node)
{
	if (node == nullptr)
		return;
	insert(node->getData());
	copy(node->getLeft());
	copy(node->getRight());
}
template <class T>
Node<T>* Tree<T>::getMin(Node<T>*node)
{
	if (node == nullptr)
		return nullptr;
	while (node->getLeft())
	{
		node = node->getLeft();
	}
	return node;
}
template <class T>
Node<T>* Tree<T>::getNext(Node<T>*node)
{
	if (node == nullptr)
		return nullptr;
	if (node->getRight())
		return getMin(node->getRight());
	Node<T>*tmp = node->getParent();
	while (tmp && node == tmp->getRight())
	{
		node = tmp;
		tmp = node->getParent();
	}
	return tmp;
}
template <class T>
void Tree<T>::del(Node<T>*node)
{
	if (node == nullptr)
		return;
	Node<T>*target, *son;
	if (node->getRight() && node->getLeft())
		target = getNext(node);
	else
		target = node;

	if (target->getLeft())
		son = target->getLeft();
	else
		son = target->getRight();

	if (son)
		son->setParent(target->getParent());

	if (target->getParent() == nullptr)
		root = son;
	else
	{
		if (target == target->getParent()->getLeft())
			target->getParent()->setLeft(son);
		else
			target->getParent()->setRight(son);
	}

	if (node != target)
		node->setData(target->getData());

	delete target;
}
template<class T>
Node<T> *Tree<T>::getMax(Node<T> *node)
{
	if (node == nullptr)
		return nullptr;
	while (node->getRight())
	{
		node = node->getRight();
	}
	return node;
}
template<class T>
int Tree<T>::getSize(Node<T> *node, int val)
{
	int i = val;
	if (node)
	{
		i = getSize(node->getLeft(), i);
		i++;
		i = getSize(node->getRight(), i);
	}
	return i;
}
template<class T>
Node<T> *Tree<T>::find(T val)
{
	Node<T> *cur = root;
	while (cur)
	{
		if (val == cur->getData())
			return cur;
		if (val < cur->getData())
			cur = cur->getLeft();
		else
			cur = cur->getRight();
	}
	return cur;
}
template<class T>
Tree<T>& Tree<T>::operator=(const Tree<T> &obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (root)
	{
		while (root->getLeft())
		{
			del(getMin(root));
		}
		while (root->getRight())
		{
			del(getMax(root));
		}
		delete root;
	}
	copy(obj.root);
	return *this;
}
template<class T>
Tree<T>& Tree<T>::operator= (Tree &&obj)
{
	if (this == &obj)
		return *this;

	if (root)
	{
		while (root->getLeft())
		{
			del(getMin(root));
		}
		while (root->getRight())
		{
			del(getMax(root));
		}
		delete root;
	}
	std::swap(root, obj.root);
	return *this;
}