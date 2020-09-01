#include"Common.h"
Common::Common(const string &c, int val) :Automobile(val)
{
	color = c;
}
const string&Common::getColor()const
{
	return color;
}
void Common::setColor(const string&c)
{
	color = c;
}
Common::~Common()
{
	cout << "~Common()" << endl;
}