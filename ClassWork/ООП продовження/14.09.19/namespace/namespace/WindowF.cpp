#include "WindowF.h"
B::Window::Window(float _h, float _w)
{
	h = _h;
	w = _w;
}
float B::Window::getH()const
{
	return h;
}
void B::Window::setH(float val)
{
	h = val;
}
float B::Window::getW()const
{
	return w;
}
void B::Window::setW(float val)
{
	w = val;
}