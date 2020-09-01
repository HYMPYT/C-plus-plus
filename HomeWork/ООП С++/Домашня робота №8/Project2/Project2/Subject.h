#pragma once

#include<iostream>
#include<string>

using namespace std;

class TypeOfSubject
{
public:
	virtual void Prog() = 0;
	virtual void Math() = 0;
	virtual void Physics() = 0;
	virtual ~TypeOfSubject() = default;
};

class Practical : public TypeOfSubject
{
public:
	void Prog()override;
	void Math()override;
	void Physics()override;
};

class Lecture : public TypeOfSubject
{
public:
	void Prog()override;
	void Math()override;
	void Physics()override;
};

class Subject
{
	TypeOfSubject*typeofsubject;
public:
	virtual void conductingClasses() = 0;
	virtual ~Subject() = default;
	TypeOfSubject*getTypeOfSubject()const;
	void setTypeOfSubject(TypeOfSubject*);
};

class PracticalSubject :public Subject
{
public:
	void conductingClasses()override;
};

class LectureSubject :public Subject
{
public:
	void conductingClasses()override;
};