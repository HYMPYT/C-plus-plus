#pragma once
#include"Node.h"
#include<iostream>
template <class T>
class List
{
	Node<T>*head = nullptr;
	Node<T>*tail = nullptr;
	int size = 0;
public:
	List() = default;
	List(const List &);
	List(List &&);
	~List();
	List & operator=(const List&);
	List& operator=(List<T> &&);
	void addelem(int, int);
	void remove_elem(int);
	void pushBack(T);
	void print();
	void popFront();
};

template <class T>
void List<T>::pushBack(T val)
{
	Node<T>*tmp = new Node<T>(val);
	if (size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->setNext(tmp);
		tmp->setPrev(tail);
		tail = tmp;
	}
	size++;
}
template <class T>
void List<T>::print()
{
	Node<T>*cur = head;
	while (cur)
	{
		std::cout << cur->getData() << " ";
		cur = cur->getNext();
	}
	std::cout << std::endl;
}
template <class T>
void List<T>::popFront()
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete head;
		head = tail = nullptr;
		size = 0;
		return;
	}
	head = head->getNext();
	delete head->getPrev();
	size--;
}
template <class T>
List<T>::List(const List & obj)
{
	std::cout << "Copy constructor" << std::endl;
	Node<T>*cur = obj.head;
	while (cur)
	{
		pushBack(cur->getData());
		cur = cur->getNext();
	}
}
template <class T>
List<T>::List(List&&obj)
{ 
	std::cout << "Move constructor" << std::endl;
	std::swap(head, obj.head);
	std::swap(tail, obj.tail);
	std::swap(size, obj.size);
}
template <class T>
void List<T>::addelem(int pos, int val)
{
	if (pos > size)
	{
		pushBack(val);
		return;
	}
	if (pos == 1)
	{
		Node<T>*tmp = new Node<T>(val);
		tmp->setNext(head);
		head->setPrev(tmp);
		head = tmp;
		size++;
		return;
	}
	int num = 1;
	Node<T>*tmp = head;
	Node<T>*elem = new Node<T>(val);
	while (num != pos)
	{
		tmp = tmp->getNext();
		num++;
	}
	elem->setNext(tmp);
	elem->setPrev(elem->getNext()->getPrev());
	tmp->getPrev()->setNext(elem);
	tmp->setPrev(elem);
	size++;
}
template <class T>
void List<T>::remove_elem(int pos)
{
	if (pos == size)
	{
		tail = tail->getPrev();
		delete tail->getNext();
		tail->setNext(nullptr);
		size--;
		return;
	}
	if (pos == 1)
	{
		popFront();
		return;
	}
	int num = 1;
	Node<T>*tmp = head;
	while (num != pos)
	{
		tmp = tmp->getNext();
		num++;
	}
	tmp->getPrev()->setNext(tmp->getNext());
	tmp->getNext()->setPrev(tmp->getPrev());
	delete tmp;
	size--;
}
template <class T>
List<T> &List<T>::operator=(const List &obj)
{
	if (this == &obj)
		return *this;
	if (size)
		size = 0;
	Node<T>*cur = obj.head;
	while (cur)
	{
		pushBack(cur->getData());
		cur = cur->getNext();
	}
	return *this;
}
template <class T>
List<T> &List<T>::operator=(List<T> &&obj)
{
	if (this == &obj)
		return *this;
	if (size)
		size = 0;
	std::swap(head, obj.head);
	std::swap(tail, obj.tail);
	std::swap(size, obj.size);
	return *this;
}
template <class T>
List<T>::~List()
{
	while (size)
		popFront();
}