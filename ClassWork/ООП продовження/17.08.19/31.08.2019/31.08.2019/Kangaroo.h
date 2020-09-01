#pragma once
#include"Animal.h"
class Kangaroo :public Animal
{
public:
	Kangaroo(const string &n);
	~Kangaroo()override;
	void move()override;
};