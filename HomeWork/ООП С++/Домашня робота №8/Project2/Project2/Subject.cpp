#include "Subject.h"

void Practical::Prog()
{
	cout << "Practical programming lesson" << endl;
}
void Practical::Math()
{

	cout << "Practical classes in mathematics" << endl;
}
void Practical::Physics()
{
	cout << "Practical classes in physics" << endl;
}

void Lecture::Prog()
{
	cout << "Lecture on programming" << endl;
}
void Lecture::Math()
{
	cout << "Lecture on mathematics" << endl;
}
void Lecture::Physics()
{
	cout << "Lecture on physics" << endl;
}

TypeOfSubject* Subject::getTypeOfSubject()const
{
	return typeofsubject;
}
void Subject::setTypeOfSubject(TypeOfSubject* tos)
{
	typeofsubject = tos;
}

void PracticalSubject::conductingClasses()
{
	getTypeOfSubject()->Math();
	getTypeOfSubject()->Physics();
	getTypeOfSubject()->Prog();
}
void LectureSubject::conductingClasses()
{
	getTypeOfSubject()->Math();
	getTypeOfSubject()->Physics();
	getTypeOfSubject()->Prog();
}