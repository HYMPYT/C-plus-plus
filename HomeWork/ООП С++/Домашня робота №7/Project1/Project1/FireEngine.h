#pragma once
#include"Emergency.h"
class FireEngine :public Emergency
{
public:
	FireEngine(const string&, int val);
	~FireEngine()override;
	void signal()override;
};