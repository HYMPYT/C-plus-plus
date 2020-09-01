#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack S(100);
	const char* str = "(45 - 5) + <{5465}> - [2323]([{<>}])";
	while (*str)
	{
		switch (*str)
		{
		case 40:
			if (S.is_full())
			{
				cout << "Error. The Stack is full." << endl;
				system("pause");
			}
			S.push(40);
			break;
		case 41:
			if (S.is_empty() || S.peek() != 40)
			{
				cout << "Error. There is no opening \"(\". The expression is not correct." << endl;
				system("pause");
			}
			S.pop();
			break;
		case 91:
			if (S.is_full())
			{
				cout << "Error. The Stack is full." << endl;
				system("pause");
			}
			S.push(91);
			break;
		case 93:
			if (S.is_empty() || S.peek() != 91)
			{
				cout << "Error. There is no opening \"[\". The expression is not correct." << endl;
				system("pause");
			}
			S.pop();
			break;
		case 123:
			if (S.is_full())
			{
				cout << "Error. The Stack is full." << endl;
				system("pause");
			}
			S.push(123);
			break;
		case 125:
			if (S.is_empty() || S.peek() != 123)
			{
				cout << "Error. There is no opening \"{\". The expression is not correct." << endl;
				system("pause");
			}
			S.pop();
			break;
		case 60:
			if (S.is_full())
			{
				cout << "Error. The Stack is full." << endl;
				system("pause");
			}
			S.push(60);
			break;
		case 62:
			if (S.is_empty() || S.peek() != 60)
			{
				cout << "Error. There is no opening \"<\". The expression is not correct." << endl;
				system("pause");
			}
			S.pop();
			break;
		}
		str++;
	}
	if (!S.is_empty())
	{
		cout << "Error. There are not enough closing elements for: ";
		while (!S.is_empty())
		{
			cout << char(S.peek()) << " ";
			S.pop();
		}
		system("pause");
	}
	cout << "Congratulations! The expression is correct!" << endl;
	system("pause");
}