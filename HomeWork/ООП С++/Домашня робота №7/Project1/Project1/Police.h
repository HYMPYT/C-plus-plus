#pragma once
#include"Emergency.h"
class Police :public Emergency
{
public:
	Police(const string&, int);
	~Police()override;
	void signal()override;
};