#pragma once
class Stack
{
	int* arr = nullptr;
	int top = -1;
	int capacity = 0;
public:
	Stack();
	Stack(int);
	Stack(const Stack&);
	Stack(Stack&&);
	~Stack();
	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);
	void push(int);
	int pop();
	int peek() const;
	bool is_empty() const;
	bool is_full() const;
};

