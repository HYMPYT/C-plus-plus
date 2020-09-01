#pragma once
#include"Bird.h"
class Penguin : public Bird
{
public:
	Penguin(const string&n);
	~Penguin()override;
	//void move();
};