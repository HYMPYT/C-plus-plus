#pragma once

template <class T>
class Node
{
	T data;
	Node<T> * next = nullptr;
	Node<T> * prev = nullptr;
public:
	Node(T);
	T getData();
	Node*getNext();
	Node*getPrev();
	void setData(T);
	void setNext(Node*);
	void setPrev(Node*);
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
Node<T>* Node<T>::getPrev()
{
	return prev;
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
template <class T>
void Node<T>::setPrev(Node*pt)
{
	prev = pt;
}