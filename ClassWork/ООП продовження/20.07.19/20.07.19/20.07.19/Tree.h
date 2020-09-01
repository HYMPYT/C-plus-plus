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
	void insert(T);
	void print(Node<T> *);
	void print();
	void copy(Node<T>*);
	Node<T>*getRoot();
	Node<T>*getMin(Node<T>*);
	Node<T>*getNext(Node<T>*);
	void del(Node<T>*);
};
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