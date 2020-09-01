#pragma once
#include"Animal.h"
class Fish :public Animal
{
public:
	Fish(const string&n);
	~Fish()override;
	void move()override;
};