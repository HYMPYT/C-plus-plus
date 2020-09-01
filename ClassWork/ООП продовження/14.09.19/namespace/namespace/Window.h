#pragma once
namespace A
{
	class Window
	{
		int h;
		int w;
	public:
		Window(int, int);
		int getH()const;
		void setH(int);
		int getW()const;
		void setW(int);
	};
}