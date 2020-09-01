#include<iostream>
#include<string>
using namespace std;
//class Point
//{
//protected:
//	int x;
//	int y;
//public:
//	Point(int x = 0, int y = 0):x(x), y(y){}
//	int getX()const
//	{
//		return x;
//	}
//	void setX(int val)
//	{
//		x = val;
//	}
//	int getY()const
//	{
//		return y;
//	}
//	void setY(int val)
//	{
//		y = val;
//	}
//	void print()
//	{
//		cout << "X -> " << x << endl << "Y -> " << y << endl;
//	}
//};
//class Point3D :public Point
//{
//	int z;
//public:
//	Point3D(int x, int y, int z) :Point(x, y)
//	{
//		this->z = z;
//	}
//	int getZ()const
//	{
//		return z;
//	}
//	void setZ(int val)
//	{
//		z = val;
//	}
//	void print()
//	{
//		Point::print();
//		cout << "Z -> " << z << endl;
//		/*cout << "X -> " << x << endl << "Y -> " << y << endl << "Z -> " << z << endl;*/
//	}
//};

class Person
{
	char*name = nullptr;
	int age = 0;
public:
	Person() = default;
	Person(const char*s, int val)
	{
		age = val;
		name = _strdup(s);
	}
	Person(const Person&obj)
	{
		age = obj.age;
		name = _strdup(obj.name);
	}
	Person(Person&&obj)
	{
		age = obj.age;
		name = obj.name;
		obj.name = nullptr;
		obj.age = 0;
	}
	~Person()
	{
		delete[]name;
	}
	int getAge()const
	{
		return age;
	}
	void setAge(int val)
	{
		age = val;
	}
	const char*getName()const
	{
		return name;
	}
	void setName(char*name)
	{
		delete[]this->name;
		this->name = _strdup(name);
	}
	void print()
	{
		cout << "+++++++++++++++++++++++++++++" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "+++++++++++++++++++++++++++++" << endl;
	}
	Person & operator=(const Person & obj)
	{
		if (this == &obj)
			return *this;

		delete[]name;
		age = obj.age;
		name = _strdup(obj.name);
		return *this;
	}
	Person & operator=(Person &&obj)
	{
		if (this == &obj)
			return *this;

		delete[]name;
		age = obj.age;
		name = obj.name;
		obj.age = 0;
		obj.name = nullptr;
		return *this;
	}
};
struct Mark
{
	string subject;
	int mark;
};
class Student : public Person
{
	Mark *arr = nullptr;
	int size = 0;
public:
	Student(const char* name, int age) :Person(name, age)
	{
		arr = new Mark[5];
		size = 5;
	}
	Student(const Student &obj) :Person(obj)
	{
		size = obj.size;
		arr = new Mark[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	Student(Student&&obj) :Person(move(obj))
	{
		swap(size, obj.size);
		swap(arr, obj.arr);
	}
	~Student()
	{
		if (size)
			delete[]arr;
	}
	Student&operator=(const Student&obj)
	{
		if (this == &obj)
			return*this;

		Person::operator=(obj);

		if (size)
			delete[]arr;
		size = obj.size;
		arr = new Mark[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
		return *this;
	}
	Student&operator=(Student&&obj)
	{
		if (this == &obj)
			return *this;

		size = obj.size;
		arr = obj.arr;
		obj.arr = nullptr;
		size = 0;

		Person::operator=(move(obj));

		return *this;
	}
	int getSize()const
	{
		return size;
	}
	Mark&operator[](int pos)
	{
		return arr[pos];
	}
};
int main()
{
	Student ivan("Ivan", 21);
	ivan[0].subject = "Math";
	ivan[0].mark = 12;
	ivan[1].subject = "Phis-ra";
	ivan[1].mark = 4;
	ivan[2].subject = "Lit";
	ivan[2].mark = 8;
	ivan[3].subject = "Chemic";
	ivan[3].mark = 7;
	ivan[4].subject = "Prog";
	ivan[4].mark = 10;
	Student petr = ivan;
	cout << petr.getName() << endl;
	for (int i = 0; i < petr.getSize(); i++)
	{
		cout << "S: " << petr[i].subject << endl <<  "M: " << petr[i].mark << endl;
	}

	/*Point a(1, 2);
	a.print();
	Point3D b(12, 23, 34);
	b.print();*/
	system("pause");
}