#pragma once
#include"Animal.h"
class Bird :public Animal
{
public:
	Bird(const string&n);
	~Bird()override;
	void move()override final;
};