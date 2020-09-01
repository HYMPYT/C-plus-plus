#pragma once
#include"Person.h"
class Doctor:virtual public Person
{
	string specialization;
public:
	Doctor(const string&, int, const string&);
	const string& getSpecialization()const;
	void setSpecialization(const string&);
};