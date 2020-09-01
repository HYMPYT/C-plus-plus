#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;
class Person
{
	string f_name;
	string l_name;
	int age;
public:
	Person(const string&fn, const string&ln, int a)
	{
		f_name = fn;
		l_name = ln;
		age = a;
	}

	const string &getFName()const
	{
		return f_name;
	}
	void setFName(const string&fname)
	{
		f_name = fname;
	}
	const string &getLName()const
	{
		return l_name;
	}
	void setLName(const string&lname)
	{
		l_name = lname;
	}
	int getAge()const
	{
		return age;
	}
	void setAge(int val)
	{
		age = val;
	}
	friend ostream&operator<<(ostream&os, const Person&p)
	{
		os << "First name -> " << p.f_name << endl << "Last name -> " << p.l_name << endl << "Age -> " << p.age << endl;
		os << "++++++++++++++++++++++++++++++++++++++";
		return os;
	}
};
bool check(int a, int b)
{
	return a > b;
}
int main()
{
	vector<shared_ptr<Person>> people;
	people.push_back(shared_ptr<Person>(new Person("Ivan", "Ivanov", 23)));
	people.push_back(shared_ptr<Person>(new Person("Masha", "Mashuna", 25)));
	people.push_back(shared_ptr<Person>(new Person("Sveta", "Ivanova", 12)));
	people.push_back(shared_ptr<Person>(new Person("Petya", "Petrov", 35)));
	people.push_back(shared_ptr<Person>(new Person("Misha", "Volkov", 36)));
	//copy(people.begin(), people.end(), ostream_iterator<shared_ptr<Person>>(cout, '\n'));
	transform(people.begin(), people.end(), ostream_iterator<Person>(cout, "\n"), [](shared_ptr<Person> val)->Person {
		return *val;
	});
	sort(people.begin(), people.end(), [](shared_ptr<Person> a, shared_ptr<Person> b)->bool {
		return a->getAge() < b->getAge();
	});
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	transform(people.begin(), people.end(), ostream_iterator<Person>(cout, "\n"), [](shared_ptr<Person> val)->Person {
		return *val;
	});
	system("pause");
}