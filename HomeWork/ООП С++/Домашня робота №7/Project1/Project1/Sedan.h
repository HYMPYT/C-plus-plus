#pragma once
#include"Common.h"
class Sedan :public Common
{
public:
	Sedan(const string&, int);
	~Sedan()override;
};