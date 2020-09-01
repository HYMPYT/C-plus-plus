#pragma once

template <class T>
class Node
{
	T data;
	Node<T> * next = nullptr;
public:
	Node(T);
	T getData();
	Node*getNext();
	void setData(T);
	void setNext(Node*);

};

template <class T>
Node<T>::Node(T val)
{
	data = val;
}
template <class T>
T Node<T>::getData()
{
	return data;
}
template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}
template <class T>
void Node<T>::setData(T val)
{
	data = val;
}
template <class T>
void Node<T>::setNext(Node*pt)
{
	next = pt;
}