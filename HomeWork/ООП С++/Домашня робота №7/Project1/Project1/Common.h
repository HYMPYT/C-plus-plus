#pragma once
#include"Automobile.h"
class Common :public Automobile
{
	string color;
public:
	Common(const string &c, int);
	const string&getColor()const;
	void setColor(const string&);
	~Common()override;
};