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
	void removingstuff(int, int);
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
void List<T>::addelem(int pos, int val)
{
	if (pos > size)
	{
		pushBack(val);
		return;
	}
	if (pos == 1)
	{
		pushFront(val);
		return;
	}
	int num = 1;
	Node<T>*cur = head;
	Node<T>*tmp = head;
	Node<T>*elem = new Node<T>(val);
	while (num != pos)
	{
		tmp = tmp->getNext();
		num++;
	}
	while (cur->getNext() != tmp)
	{
		cur = cur->getNext();
	}
	elem->setNext(tmp);
	cur->setNext(elem);
	size++;
}
template <class T>
void List<T>::remove_elem(int pos)
{
	if (pos >= size)
	{
		popBack();
		return;
	}
	if (pos == 1)
	{
		popFront();
		return;
	}
	int num = 1;
	Node<T>*cur = head;
	Node<T>*tmp = head;
	while (num != pos + 1)
	{
		tmp = tmp->getNext();
		num++;
	}
	num = 1;
	while (num < pos - 1)
	{
		cur = cur->getNext();
		num++;
	}
	cur->setNext(tmp);
	size--;
}
template <class T>
void List<T>::removingstuff(int pos1, int pos2)
{
	int num = 1, _size = pos2 - pos1 + 1;
	Node<T>*cur = head;
	Node<T>*tmp = head;
	while (num != pos2 + 1)
	{
		tmp = tmp->getNext();
		num++;
	}
	num = 1;
	while (num < pos1 - 1)
	{
		cur = cur->getNext();
		num++;
	}
	cur->setNext(tmp);
	size -= _size;
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