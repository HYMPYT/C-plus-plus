#pragma once
#include"Doctor.h"
#include"Student.h"
class StudentMed:public Doctor, public Student
{
public:
	StudentMed(const string&, int, int, const string&);
	StudentMed(int, const string&);
};