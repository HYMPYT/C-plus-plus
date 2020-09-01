#pragma once

template <class T>
class Node
{
	T data;
	Node<T> * left = nullptr;
	Node<T> * right = nullptr;
	Node<T> * parent = nullptr;
public:
	Node(T);
	T getData();
	Node*getLeft();
	Node*getRight();
	Node*getParent();
	void setData(T);
	void setLeft(Node*);
	void setRight(Node*);
	void setParent(Node*);
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
Node<T>* Node<T>::getLeft()
{
	return left;
}
template <class T>
Node<T>* Node<T>::getRight()
{
	return right;
}
template <class T>
Node<T>* Node<T>::getParent()
{
	return parent;
}
template <class T>
void Node<T>::setData(T val)
{
	data = val;
}
template <class T>
void Node<T>::setLeft(Node*pt)
{
	left = pt;
}
template <class T>
void Node<T>::setRight(Node*pt)
{
	right = pt;
}
template <class T>
void Node<T>::setParent(Node*pt)
{
	parent = pt;
}