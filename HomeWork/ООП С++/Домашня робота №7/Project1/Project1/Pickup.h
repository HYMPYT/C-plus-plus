#pragma once
#include"Common.h"
class Pickup : public Common
{
public:
	Pickup(const string&, int);
	~Pickup()override;
};