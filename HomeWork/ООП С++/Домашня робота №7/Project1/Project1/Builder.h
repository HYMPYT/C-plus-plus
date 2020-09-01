#pragma once
#include"Special.h"
class Builder :public Special
{
public:
	Builder(const string&, int);
	~Builder()override;
	virtual void work() = 0;
};