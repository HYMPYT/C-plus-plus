#include<iostream>
#include"Window.h"
#include"WindowF.h"
using namespace std;
//namespace my_space
//{
//	class Window
//	{
//		int h;
//		int w;
//	public:
//		Window(int _h, int _w);
//	};
//	/*Window::Window(int _h, int _w)
//	{
//		h = _h;
//		w = _w;
//	}*/
//}
//my_space::Window::Window(int _h, int _w)
//{
//	h = _h;
//	w = _w;
//}

int main()
{
	A::Window a(123, 345);
	B::Window b(2.44, 4.457);
	cout << a.getH() << endl << a.getW() << endl;
	cout << b.getH() << endl << b.getW() << endl;
	system("pause");
}