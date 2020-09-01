#include<iostream>
using namespace std;

class Singleton
{
	int data;
	static Singleton*ptr;
	Singleton(int val)
	{
		data = val;
	}
public:
	Singleton(const Singleton&) = delete;
	int getData()const
	{
		return data;
	}
	void setData(int val)
	{
		data = val;
	}
	static Singleton*getInstance()
	{
		if (ptr == nullptr)
			ptr = new Singleton(0);
		return ptr;
	}
};
Singleton*Singleton::ptr = nullptr;
int main()
{

	system("pause");
}