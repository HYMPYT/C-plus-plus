#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//================================
class Automobile
{
protected:
	string name;
public:
	Automobile(string n)
	{
		name = n;
	}
	~Automobile()
	{
		cout << "~Automobile()" << endl;
	}
};
//================================
class Car :public Automobile
{
public:
	Car(string name) :Automobile(name) {}
	virtual void show() = 0;
	virtual ~Car() = default;
};
//================================
class Truck :public Automobile
{
public:
	Truck(string name) :Automobile(name) {}
	virtual void show() = 0;
	virtual ~Truck() = default;
};
//================================
class Bus :public Automobile
{
public:
	Bus() :Automobile("Bus") {}
	void show()
	{
		cout << name << endl;
	}
	~Bus()
	{
		cout << "~Bus()" << endl;
	}
};
//================================
class CarMersedes :public Car
{
public:
	CarMersedes() :Car("Car brand Mercedes") {}
	void show()override
	{
		cout << name << endl;
	}
	~CarMersedes()override
	{
		cout << "~CarMarsedes()" << endl;
	}
};
//================================
class CarFord : public Car
{
public:
	CarFord() :Car("Car brand Ford") {}
	void show()override
	{
		cout << name << endl;
	}
	~CarFord()override
	{
		cout << "~CarFord()" << endl;
	}
};
//================================
class TruckMersedes :public Truck
{
public:
	TruckMersedes() :Truck("Truck brand Mersedes") {}
	void show()override
	{
		cout << name << endl;
	}
	~TruckMersedes()override
	{
		cout << "~TruckMersedes()" << endl;
	}
};
//================================
class TruckFord :public Truck
{
public:
	TruckFord() :Truck("Truck brand Ford") {}
	void show()override
	{
		cout << name << endl;
	}
	~TruckFord()override
	{
		cout << "~TruckFord()" << endl;
	}
};
//================================
class AutomobileFactory
{
public:
	virtual Car* getCar() = 0;
	virtual Truck* getTruck() = 0;
	virtual Bus* getBus() = 0;
	virtual ~AutomobileFactory() = default;
};
//================================
class MersedesAutomobileFactory :public AutomobileFactory
{
public:
	Car* getCar()
	{
		return new CarMersedes();
	}
	Truck* getTruck()
	{
		return new TruckMersedes();
	}
	Bus* getBus()
	{
		return new Bus();
	}
};
//================================
class FordAutomobileFactory : public AutomobileFactory
{
public:
	Car* getCar()
	{
		return new CarFord();
	}
	Truck* getTruck()
	{
		return new TruckFord();
	}
	Bus* getBus()
	{
		return new Bus();
	}
};