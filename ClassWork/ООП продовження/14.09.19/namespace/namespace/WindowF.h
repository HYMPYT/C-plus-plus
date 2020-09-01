#pragma once
namespace B
{
	class Window
	{
		float h;
		float w;
	public:
		Window(float, float);
		float getH()const;
		void setH(float);
		float getW()const;
		void setW(float);
	};
}