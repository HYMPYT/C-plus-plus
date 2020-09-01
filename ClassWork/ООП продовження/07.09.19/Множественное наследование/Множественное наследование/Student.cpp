#include "Student.h"
Student::Student(const string&n, int age, int id) :Person(n, age)
{
	this->id = id;
}
int Student::getId()const
{
	return id;
}
void Student::setId(int val)
{
	id = val;
}
