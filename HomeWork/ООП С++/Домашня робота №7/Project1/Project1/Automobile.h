#pragma once
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Automobile
{
	int number;
public:
	Automobile(int);
	virtual ~Automobile() = default;
	int getNumber()const;
	void setNumber(int);
};