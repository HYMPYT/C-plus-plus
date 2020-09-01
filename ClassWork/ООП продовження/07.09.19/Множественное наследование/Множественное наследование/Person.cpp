#include "Person.h"
Person::Person() = default;
Person::Person(const string&n, int a)
{
	name = n;
	age = a;
}
const string& Person::getName()const
{
	return name;
}
void Person::setName(const string&n)
{
	name = n;
}
int Person::getAge()const
{
	return age;
}
void Person::setAge(int val)
{
	age = val;
}
