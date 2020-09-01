#include"operations.h"
double calc(double a, double b, double(*s)(double, double))
{
	return s(a, b);
}