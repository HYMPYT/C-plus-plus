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
	void pushBack(T);
	void pushFront(T);
	void print();
	void popFront();
	void popBack();
};

template <class T>
void List<T>::pushFront(T val)
{
	Node<T>*tmp = new Node<T>(val);
	if (size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tmp->setNext(head);
		head = tmp;
	}
	size++;
}
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
	Node<T>*tmp = head;
	head = head->getNext();
	delete tmp;
	size--;
}
template <class T>
void List<T>::popBack()
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
	Node<T>*cur = head;
	while (cur->getNext() != tail)
	{
		cur = cur->getNext();
	}
	delete tail;
	tail = cur;
	tail->setNext(nullptr);
	size--;
}
template <class T>
List<T>::List(const List & obj)
{
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
	std::swap(head, obj.head);
	std::swap(tail, obj.tail);
	std::swap(size, obj.size);
}
template <class T>
List<T>::~List()
{
	while (size)
		popFront();
}