#pragma once
#include"Builder.h"
class TruckCrane :public Builder
{
public:
	TruckCrane(const string&, int);
	~TruckCrane()override;
	void work()override;
};