#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Point()
	{
		x = y = 0;
	}
	int getX()
	{
		return x;
	}
	void setX(int val)
	{
		x = val;
	}
	int getY()
	{
		return y;
	}
	void setY(int val)
	{
		y = val;
	}
};
class Person
{
	static int n;
	char *name ;
	int age;  //mutable щоб змінювати в константних методах параметри
public:
	Person(const char * name, int age)
	{
		n++;
		cout << "Constructor with parametrs" << endl;
		//---------------------------------------------//
		this->name = new char[strlen(name) + 1];       //
		strcpy(this->name, name);				       //_strdup("string")
		//---------------------------------------------//
		this->age = age;
	}
	//Person(const Person &obj) = delete;
	Person(const Person &obj)
	{
		n++;
		cout << "Copy constructor for " << obj.getName() << endl;
		this->age = obj.age;
		this->name = _strdup(obj.name);
	}
	Person()
	{
		n++;
		cout << "Default constructor" << endl;
		this->name = _strdup("Noname");
		this->age = 0;
	}
	Person(Person &&obj)
	{
		n++;
		cout << "Move constructor" << endl;
		this->age = obj.age;
		this->name = _strdup(obj.name);
		obj.name = nullptr;
	}
	~Person()
	{
		n--;
		cout << "Destructor for " << endl;
		delete[]name;
	}
	const char * getName()	const
	{
		return name;
	}
	void setName(const char * name)
	{
		delete[]this->name;
		this->name = _strdup(name);
	}
	int getAge() const
	{
		return age;
	}
	void setAge(int val)
	{
		age = val;
	}
	void print() const
	{
		cout << "Count: " << n << endl << "Name: " << name << endl << "Age: " << age << endl;
	}
	static int getN()
	{
		return n;
	}
	Person & operator=(Person && obj)
	{
		if (this == &obj)
			return *this;
		delete[]name;
		this->age = obj.age;
		this->name = _strdup(obj.name);
		obj.name = nullptr;
		return *this;
	}
};
int Person::n = 0;
void show(Person &obj)
{
	obj.print();
}
int main()
{
	/*int a = 5;
	int  &ra = a;
	int && rl = 5;
	rl += 23;
	cout << rl << endl;*/
	/*Point a(12, 45);
	cout << a.getX() << " " << a.getY() << endl;
	Point b;
	cout << b.getX() << " " << b.getY() << endl;*/
	{
		Person a("yevhen", 12);
		Person b = move(a);
		b.print();
		/*cout << Person::getN() << endl;
		Person a("Yevhen", 18);
		show(a);
		cout << a.getN() << endl;
		const Person b("Masha", 19);
		b.print();
		cout << b.getN() << endl;
		Person b;
		b.setName("Masha");
		b.print();
		Person *pt = new Person("Sveta", 19);
		pt->print();
		delete pt;*/
	}
	system("pause");
}