#include<iostream>
#include<string>
using namespace std;
class A
{
	int data;
public:
	A(int d)
	{
		data = d;
	}
	int getData()const
	{
		return data;
	}
	void setData(int val)
	{
		data = val;
	}
	virtual void info()
	{
		cout << "class A with param " << data << endl;
	}
	virtual ~A() = default;
};
class B :public A
{
	string line;
public:
	B(const string& l, int d) :A(d)
	{
		line = l;
	}
	const string&getLine()const
	{
		return line;
	}
	void setLine(const string&l)
	{
		line = l;
	}
	void info()override
	{
		cout << "class B with params " << getData() << " " << line << endl;
	}
	void methodB()
	{
		cout << "Method of class B: " << line << endl;
	}
};
int main()
{
	int a = 123;
	int *ipa = &a;
	short* spa = reinterpret_cast<short*>(ipa);
	cout << *spa << endl;

	/*const char* hello = "Hello";
	long h = reinterpret_cast<long>(hello);
	cout << h << endl;
	char * str = reinterpret_cast<char*>(h);
	cout << str << endl;*/

	/*A*pt = new B("Test", 123);
	pt->info();
	A*ptr = new A(123);
	ptr->info();
	B*b = dynamic_cast<B*>(pt);
	if (b)
		b->methodB();
	else
		cout << "Erorr" << endl;
	b = dynamic_cast<B*>(ptr);
	if (b)
		b->methodB();
	else
		cout << "Erorr" << endl;
	delete pt;
	delete ptr;
	delete b;*/

	/*int a = 34;
	int *ipa = &a;
	void*vpa = static_cast<void*>(ipa);
	short*spa = static_cast<short*>(vpa);
	cout << *spa << endl;*/

	/*double a = 2.5;
	cout << static_cast<int>(a) << endl;
	cout << (int)a << endl;*/
	system("pause");
}