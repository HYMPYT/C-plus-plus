#pragma once
#include"Builder.h"
class ConcreteMixer :public Builder
{
public:
	ConcreteMixer(const string&, int);
	~ConcreteMixer()override;
	void work()override;
};