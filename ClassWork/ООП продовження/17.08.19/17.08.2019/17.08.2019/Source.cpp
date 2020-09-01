#include<iostream>
#include<vector>
using namespace std;
//class Outer
//{
//public:
//	class Inner
//	{
//		static int id;
//		int data;
//	public:
//		Inner(int);
//		int getData() const;
//		void setData(int data);
//	};
//private:
//	Inner obj;
//public:
//	Outer(int);
//	int getObj()const;
//	void setObj(int);
//};
//
//int Outer::Inner::id = 0;
//
//Outer::Outer(int val) :obj(val){}
//
//int Outer::getObj()const
//{
//	return obj.getData();
//}
//
//void Outer::setObj(int val)
//{
//	this->obj.setData(val);
//}
//
//int Outer::Inner::getData()const
//{
//	return data;
//}
//
//void Outer::Inner::setData(int data)
//{
//	this->data = data;
//}
//
//Outer::Inner::Inner(int d)
//{
//	data = d;
//}


class Person
{
	int id;
	int age;
public:
	Person(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	int getAge()const
	{
		return age;
	}
	void setAge(int val)
	{
		age = val;
	}
	int getId()const
	{
		return id;
	}
	void setId(int val)
	{
		id = val;
	}
};

class Group
{
	vector<Person*> arr;
public:
	Group() = default;
	void addPerson(Person*pt)
	{
		arr.push_back(pt);
	}
	void delPerson(int pos)
	{
		arr.erase(arr.begin() + pos);
	}
	Person*&operator[](int pos)
	{
		return arr[pos];
	}
};

int main()
{
	Person * a = new Person(1, 23);
	Person * b = new Person(2, 23);
	Person * c = new Person(3, 23);
	Person * d = new Person(4, 23);
	Group group;
	group.addPerson(a);
	group.addPerson(b);
	group.addPerson(c);
	group.addPerson(d);
	for (int i = 0; i < 4; i++)
	{
		cout << group[i]->getId() << " ";
	}
	cout << endl;
	delete a;
	delete b;
	delete c;
	delete d;

	/*Outer::Inner a(12);
	a.setData(345);
	cout << a.getData() << endl;
	Outer b(234);
	b.setObj(345);
	cout << b.getObj() << endl;*/
	system("pause");
}