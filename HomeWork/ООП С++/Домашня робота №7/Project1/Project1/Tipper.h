#pragma once
#include"Builder.h"
class Tipper :public Builder
{
public:
	Tipper(const string&, int);
	~Tipper()override;
	void work()override;
};