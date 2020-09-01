#include<iostream>
#include<memory>// auto_ptr, unique_ptr, shared_ptr, weak_ptr
using namespace std;
//class Test
//{
//	int data;
//public:
//	Test() = default;
//	Test(int data)
//	{
//		this->data = data;
//	}
//	int getData()const
//	{
//		return data;
//	}
//	void setData(int data)
//	{
//		this->data = data;
//	}
//};
//class TestPtr
//{
//	Test*ptr = nullptr;
//public:
//	TestPtr(Test*pt)
//	{
//		ptr = pt;
//	}
//	TestPtr(const TestPtr&obj) = delete;
//	TestPtr(TestPtr&&obj)noexcept
//	{
//		swap(ptr, obj.ptr);
//	}
//	Test*operator->()
//	{
//		return ptr;
//	}
//	Test operator*()
//	{
//		return *ptr;
//	}
//	~TestPtr()
//	{
//		delete ptr;
//	}
//};
int main()
{
	int a = 5;
	unique_ptr<int>up(&a);


	//shared_ptr<int>sp1(new int(323));
	//shared_ptr<int>sp3;
	//sp3 = shared_ptr<int>(new int(2525));
	//cout << *sp1 << endl;
	//cout << sp1.use_count() << endl;
	//shared_ptr<int>sp2 = sp1;
	//cout << *sp2 << endl;
	//cout << *sp1 << endl;
	//cout << sp1.use_count() << endl;
	//sp1.reset();
	//cout << sp1.use_count() << endl;
	//cout << sp2.use_count() << endl;
	//weak_ptr<int>wp = sp2;
	//cout << wp.lock().use_count() << endl;
	///*shared_ptr<int[]>arr(new int[5]);
	//arr[0] = 12;
	//cout << arr[0] << endl;*/



	/*unique_ptr<int> up1(new int(31));
	cout << *up1 << endl;
	unique_ptr<int> up2 = move(up1);
	cout << *up2 << endl;
	unique_ptr<int[]>arr(new int[5]);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 20;
		cout << arr[i] << " ";
	}*/

	/*auto_ptr <int> ap1(new int(12342));
	cout << *ap1 << endl;
	auto_ptr<int>ap2 = ap1;
	cout << *ap2 << endl;*/

	/*Test* pt = new Test(123);
	cout << pt->getData() << endl;
	TestPtr ptr(new Test(324));
	cout << ptr->getData() << endl;
	TestPtr copy = move(ptr);
	cout << copy->getData() << endl;
	Test other = *copy;
	delete pt;*/
	system("pause");
}