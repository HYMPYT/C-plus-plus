//++++++++++++++++++++++++++FactoryMethod
#include <iostream>
#include <vector>
#include<ctime>
#include<string>

using namespace std;

// Иерархия классов игровых персонажей
class Unit
{
public:
	virtual void info() = 0;

	virtual ~Unit() = default;

};

class Wizard : public Unit
{
public:
	void info() override
	{
		cout << "Wizard" << endl;
	}
};


class Warrior : public Unit
{
public:
	void info() override
	{
		cout << "Warrior" << endl;
	}
};

class Healer : public Unit
{
public:
	void info() override
	{
		cout << "Healer" << endl;
	}
};


// Фабрики объектов
class Factory
{
public:
	virtual Unit *createUnit() = 0;

	virtual ~Factory() = default;
};

class WizardFactory : public Factory
{
public:
	Unit *createUnit() override
	{
		return new Wizard;
	}
};

class WarriorFactory : public Factory
{
public:
	Unit *createUnit() override
	{
		return new Warrior;
	}
};

class HealerFactory : public Factory
{
public:
	Unit *createUnit() override
	{
		return new Healer;
	}
};


// Создание объектов при помощи фабрик объектов
int main()
{
	srand(time(0));
	Factory *wizard_factory = new WizardFactory;
	Factory *warrior_factory = new WarriorFactory;
	Factory *healer_factory = new HealerFactory;
	vector<Unit *> v;
	Factory *pt = nullptr;
	for (int i = 0; i < 6; i++)
	{
		string choice;
		cout << "Make your choice(Warrior/Wizard/Healer) -> ";
		cin >> choice;
		if (choice == "Wizard")
			pt = wizard_factory;
		else if (choice == "Warrior")
			pt = warrior_factory;
		else if (choice == "Healer")
			pt = healer_factory;
		v.push_back(pt->createUnit());
	}
	for (int i = 0; i < v.size(); i++)
		v[i]->info();

	for (int i = 0; i < v.size(); i++)
		delete v[i];
	delete wizard_factory;
	delete warrior_factory;
	delete healer_factory;
	system("pause");
}