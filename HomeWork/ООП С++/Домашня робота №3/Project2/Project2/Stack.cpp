#include <utility>
#include "Stack.h"

Stack::Stack()
{
	capacity = 100;
	arr = new int[capacity] {};
}

Stack::Stack(int c)
{
	capacity = c;
	arr = new int[capacity] {};
}

Stack::Stack(const Stack& obj)
{
	capacity = obj.capacity;
	top = obj.top;
	arr = new int[capacity];
	for (int i = 0; i <= top; ++i)
	{
		arr[i] = obj.arr[i];
	}
}

Stack::Stack(Stack&& obj) //свопаем так как есть дефолтные значения, чтобы потом не присваивать нули и nullptr
{
	std::swap(capacity, obj.capacity);
	std::swap(top, obj.top);
	std::swap(arr, obj.arr);
}

Stack::~Stack()
{
	if (capacity)
		delete[] arr;
}

Stack& Stack::operator=(const Stack& obj)
{
	if (this == &obj)
		return *this;
	if (capacity)
		delete[] arr;
	capacity = obj.capacity;
	top = obj.top;
	arr = new int[capacity];
	for (int i = 0; i <= top; ++i)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
};

Stack& Stack::operator=(Stack&& obj)
{
	if (this == &obj)
		return *this;
	if (capacity)
		delete[] arr;
	arr = obj.arr;
	capacity = obj.capacity;
	top = obj.top;
	obj.arr = nullptr;
	obj.capacity = 0;
	return *this;
};

void Stack::push(int val)
{
	arr[++top] = val;
};

int Stack::pop()
{
	return arr[top--];
};

int Stack::peek() const
{
	return arr[top];
};

bool Stack::is_empty() const
{
	return top < 0;
};

bool Stack::is_full() const
{
	return top == capacity - 1;
};
