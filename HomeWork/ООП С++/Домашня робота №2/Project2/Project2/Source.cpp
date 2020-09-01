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
		cout << "++++++++++++++++++++++++++++" << endl;
		cout << str << endl;
		cout << "++++++++++++++++++++++++++++" << endl << endl;
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
		capacity = strlen(buf) + 1;
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
	MyString operator+(const MyString &obj)
	{
		MyString tmp(strlen(str) + strlen(obj.str) + 1);
		strcpy(tmp.str, str);
		strcat(tmp.str, obj.str);
		return tmp;
	}
	MyString operator-(const MyString &obj)
	{
		MyString tmp(strlen(str) + 1);
		strcpy(tmp.str, str);
		char *t = nullptr;
		do {
			t = strstr(tmp.str, obj.str);
			if (t != NULL)
			{
				char* t_ = t + strlen(obj.str);
				strcpy(t, t_);
			}
			else
				break;
		} while (true);
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
	MyString &operator++(int value)
	{
		char *tmp = new char[strlen(str) * 2 + 1];
		char *buf = new char[strlen(str) + 1];
		strcpy(buf, str);
		for (int i = 0, k = 0; i < strlen(str) + 1; i++)
		{
			tmp[k] = buf[i];
			tmp[k + 1] = ' ';
			k += 2;
		}
		if (strlen(tmp) < capacity)
		{
			strcpy(str, tmp);
			return *this;
		}
		delete[]str;
		capacity = strlen(tmp) + 1;
		str = _strdup(tmp);
		delete[]tmp;
		delete[]buf;
		return *this;
	}
	MyString & operator--(int value)
	{
		char *buf = new char[strlen(str) + 1];
		strcpy(buf, str);
		for (int i = 1; i < strlen(str) + 1;)
		{
			if (buf[i] == ' ')
			{
				i += 2;
				continue;
			}
			delete[]buf;
			cout << "Error" << endl;
			return *this;
		}
		int size = 0;
		for (int i = 0; i < strlen(str) + 1; i++)
		{
			if (buf[i] != ' ')
				size++;
			if (buf[i] == ' ' && buf[i + 1] == ' ' && buf[i+2]==' ')
				size++;
		}
		char *tmp = new char[size] {};
		for (int i = 1, j = 0; i < strlen(str) + 1;)
		{
			tmp[j] = buf[i - 1];
			j++;
			i += 2;
		}
		if (strlen(tmp) < capacity)
		{
			strcpy(str, tmp);
			return *this;
		}
		delete[]str;
		capacity = strlen(tmp) + 1;
		str = _strdup(tmp);
		delete[]tmp;
		delete[]buf;
		return *this;
	}
	friend ostream&operator<<(ostream&os, const MyString&obj)
	{
		os << "+++++++++++++++++++++++++++++" << endl;
		os << obj.str << endl;
		os << "+++++++++++++++++++++++++++++" << endl;
		return os;
	}
	friend istream&operator>>(istream&is, MyString&obj)
	{
		char buf[1000];
		cout << "Enter the line" << endl;
		is.getline(buf, 1000);
		if (strlen(buf) < obj.capacity)
		{
			strcpy(obj.str, buf);
			return is;
		}
		delete[]obj.str;
		obj.capacity = strlen(buf) + 1;
		obj.str = _strdup(buf);
		return is;
	}
};
int main()
{
	{
		MyString a;
		cin >> a;
		cout << a << endl;
		a++;
		cout << "S++" << endl << a << endl;
		a--;
		cout << "S--" << endl << a << endl;
		/*a.input();
		a.print();
		cout << "S++" << endl;
		a++;
		a.print();
		cout << "S++" << endl;
		a++;
		a.print();
		cout << "S--" << endl;
		a--;
		a.print();
		cout << "S--" << endl;
		a--;
		a.print();*/
	}
	system("pause");
}