#pragma once
#include<iostream>
#include<string>
using namespace std;
class Animal
{
	string name;
public:
	Animal(const string & n);
	const string &getName()const;
	void setName(const string &name);
	virtual void move() = 0;
	virtual ~Animal() = 0;
};