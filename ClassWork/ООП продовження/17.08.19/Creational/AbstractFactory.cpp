//++++++++++++++++++++++++++Abstract Factory
#include<iostream>
#include<string>

using namespace std;

class AnimalToy
{
protected:
	string name;
public:
	AnimalToy(string n)
	{
		name = n;
	}
};

class Cat : public AnimalToy
{
protected:
	Cat(string name) : AnimalToy(name) { }

public:
	virtual void Show() = 0;
	virtual ~Cat() = default;
};


class Bear : public AnimalToy
{
protected:
	Bear(string name) : AnimalToy(name) { }
public:
	virtual void Show() = 0;
	virtual ~Bear() = default;
};

class WoodenCat : public Cat
{
public:
	WoodenCat() : Cat("Wooden Cat") { }

	void Show()override
	{
		cout << name << endl;
	}
};

class TeddyCat : public Cat
{
public:
	TeddyCat() : Cat("Teddy Cat") { }
	void Show()override
	{
		cout << name << endl;
	}
};

class WoodenBear : public Bear
{
public:
	WoodenBear() : Bear("Wooden Bear") { }
	void Show()override
	{
		cout << name << endl;
	}
};

class TeddyBear : public Bear
{
public:
	TeddyBear() : Bear("Teddy Bear") { }
	void Show()override
	{
		cout << name << endl;
	}
};

//absdtract factory
class IToyFactory
{
public:
	virtual Bear* GetBear() = 0;
	virtual ~IToyFactory() = default;
	virtual Cat* GetCat() = 0;
};

// конкретна фабрика (concrete factory)
class TeddyToysFactory : public IToyFactory
{
public:
	Bear* GetBear()
	{
		return new TeddyBear();
	}

	Cat* GetCat()
	{
		return new TeddyCat();
	}
};

// і ще одна конкретна фабрика
class WoodenToysFactory : public IToyFactory
{
public:
	Bear *GetBear()
	{
		return new WoodenBear();
	}

	Cat* GetCat()
	{
		return new WoodenCat();
	}
};

int main()
{
	IToyFactory *toyFactory;
	Bear *bear;
	Cat *cat;

	string choice = "teddy";
	if (choice == "wood")
	{
		toyFactory = new WoodenToysFactory();
	}
	else
	{
		toyFactory = new TeddyToysFactory();
	}
	bear = toyFactory->GetBear();
	cat = toyFactory->GetCat();
	bear->Show();
	cat->Show();
	if (toyFactory)
	{
		delete toyFactory;
	}
	delete bear;
	delete cat;
	system("pause");
}
