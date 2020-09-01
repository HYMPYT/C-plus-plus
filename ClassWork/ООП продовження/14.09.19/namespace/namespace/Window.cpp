#include "Window.h"
A::Window::Window(int _h, int _w)
{
	h = _h;
	w = _w;
}
int A::Window::getH()const
{
	return h;
}
void A::Window::setH(int val)
{
	h = val;
}
int A::Window::getW()const
{
	return w;
}
void A::Window::setW(int val)
{
	w = val;
}