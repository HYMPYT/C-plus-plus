#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
	char *str;
	int capacity;
public:
	MyString()
	{
		cout << "Default constructor" << endl;
		capacity = 80;
		str = new char[capacity] {};
	}
	MyString(int c)
	{
		cout << "Constructor with int param" << endl;
		capacity = c > 0 ? c : 80;
		str = new char[capacity] {};
	}
	MyString(const char*s)
	{
		cout << "Constructor with char param" << endl;
		capacity = strlen(s) + 1;
		str = _strdup(s);
	}
	MyString(const MyString&obj)
	{
		cout << "Copy constructor" << endl;
		capacity = obj.capacity;
		str = new char[capacity];
		strcpy(str, obj.str);
	}
	MyString(MyString&&obj)
	{
		cout << "Move constructor" << endl;
		capacity = obj.capacity;
		str = obj.str;
		obj.str = nullptr;
		obj.capacity = 0;
	}
	~MyString()
	{
		cout << "destructor" << endl;
		if (capacity)
			delete[]str;
	}
	int getSize() const
	{
		return strlen(str);
	}
	int getCapacity() const
	{
		return capacity;
	}
	void print()
	{
		cout << str << endl;
	}
	void input()
	{
		char buf[1000];
		cout << "Enter the line" << endl;
		cin.getline(buf, 1000);
		if (strlen(buf) < capacity)
		{
			strcpy(str, buf);
			return;
		}
		delete[]str;
		capacity = strlen(str) + 1;
		str = _strdup(buf);
	}
	MyString operator+(char t)
	{
		MyString tmp(strlen(str) + 2);
		strcpy(tmp.str, str);
		tmp.str[strlen(str)] = t;
		return tmp;
	}
	MyString operator+(const char *s)
	{
		MyString tmp(strlen(str) + strlen(s) + 1);
		strcpy(tmp.str, str);
		strcat(tmp.str, s);
		return tmp;
	}
	bool operator==(const MyString &obj)
	{
		return strcmp(str, obj.str) == 0;
	}
	bool operator>(MyString &obj)
	{
		return strcmp(str, obj.str) > 0;
	}
	bool operator<(MyString &obj)
	{
		return strcmp(str, obj.str) < 0;
	}
	MyString & operator=(const MyString & obj)
	{
		if (this == &obj)
			return *this;

		if (capacity)
			delete[]str;
		capacity = obj.capacity;
		str = new char[capacity];
		strcpy(str, obj.str);
		return *this;
	}
	MyString & operator=(MyString &&obj)
	{
		if (this == &obj)
			return *this;

		if (capacity)
			delete[]str;
		capacity = obj.capacity;
		str = obj.str;
		obj.capacity = 0;
		obj.str = nullptr;
		return *this;
	}
};
int main()
{
	{
		MyString a("Hello");
		MyString b("World");
		MyString c = move(b);
		
		c.print();
	}
	system("pause");
}