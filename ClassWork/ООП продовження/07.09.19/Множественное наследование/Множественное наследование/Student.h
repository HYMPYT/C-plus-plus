#pragma once
#include "Person.h"
class Student:virtual public Person 
{
	int id;
public:
	Student(const string&, int, int);
	int getId()const;
	void setId(int val);
};

