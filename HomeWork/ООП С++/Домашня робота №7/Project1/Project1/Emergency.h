#pragma once
#include"Special.h"
class Emergency :public Special
{
public:
	Emergency(const string&, int);
	~Emergency()override;
	virtual void signal() = 0;
};