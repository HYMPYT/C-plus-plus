#pragma once
#include <iostream>
template <class T>
class Test
{
	T data;
public:
	Test(T);
	void setData(T);
	T getData();
	Test operator+(const Test&);
	void print();
};

template <>
class Test <char*>
{
	char* data= nullptr;
public:
	Test(char*);
	Test() = default;
	Test(const Test &);
	void setData(char*);
	char* getData();
	Test operator+(const Test&);
	void print();
};

template <class T>
class Test<T*>
{
	T* data = nullptr;
	int size = 0;
public:
	Test(int);
	T&operator[](int);
	void print();
	Test operator+(const Test &);
};

template <class T>
void Test<T>::print()
{
	std::cout << data << std::endl;
}
template <class T>
Test<T> Test<T>::operator+(const Test<T> & obj)
{
	return Test(data + obj.data);
}
template <class T>
Test<T>::Test(T val)
{
	data = val;
}
template <class T>
void Test<T>::setData(T val)
{
	data = val;
}
template <class T>
T Test<T>::getData()
{
	return data;
}

Test<char *>::Test(char*s)
{
	data = _strdup(s);
}
Test<char *> ::Test(const Test &obj)
{
	data = obj.data;
}
void Test<char*>::setData(char * s)
{
	data = _strdup(s);
}
void Test<char *>::print()
{
	std::cout << data << std::endl;
}
Test<char *> Test<char *> :: operator+(const Test &obj)
{
	Test<char *> tmp;
	tmp.data = new char[strlen(data) + strlen(obj.data) + 1];
	strcpy(tmp.data, data);
	strcat(tmp.data, obj.data);
	return tmp;
}

template <class T>
Test<T*>::Test(int val)
{
	size = val;
	data = new T[size]{};
}
template <class T>
T& Test<T*>::operator[](int position)
{
	return data[position];
}
template <class T>
void Test<T*>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
template <class T>
Test<T*> Test<T*>::operator+(const Test & obj)
{
	Test<T*> tmp(size + obj.size);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i];
	}
	for (int i = size; i < tmp.size; i++)
	{
		tmp.data[i] = obj.data[i - size];
	}
	return tmp;
}