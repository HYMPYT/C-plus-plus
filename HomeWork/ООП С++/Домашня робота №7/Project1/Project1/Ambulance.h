#pragma once
#include"Emergency.h"
class Ambulance :public Emergency
{
public:
	Ambulance(const string&, int);
	~Ambulance()override;
	void signal()override;
};