#include "Doctor.h"
Doctor::Doctor(const string&n, int age, const string& sp):Person(n, age)
{
	specialization = sp;
}
const string& Doctor::getSpecialization()const
{
	return specialization;
}
void Doctor::setSpecialization(const string& val)
{
	specialization = val;
}