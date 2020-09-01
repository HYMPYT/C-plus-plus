#include "operations.h"
double sum(double a, double b)
{
	return a + b;
}
double rizn(double a, double b)
{
	return a - b;
}
double mult(double a, double b)
{
	return a * b;
}
double div(double a, double b)
{
	if (b != 0)
		return a / b;
	else
		return -1;
}