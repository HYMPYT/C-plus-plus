#pragma once
#include"Automobile.h"
class Special :public Automobile
{
	string organization;
public:
	Special(const string&, int);
	const string& getOrganization()const;
	void setOrganization(const string&);
	~Special()override;
};