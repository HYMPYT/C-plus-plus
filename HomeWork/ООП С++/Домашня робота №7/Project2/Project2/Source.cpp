#include"Automobile.h"
int main()
{
	AutomobileFactory* automobileFactory;
	Car* car;
	Truck* truck;
	Bus* bus;
	string choice;
	cout << "Make your choice(Ford/Mersedes) -> ";
	cin >> choice;
	if (choice == "Ford")
	{
		automobileFactory = new FordAutomobileFactory();
	}
	else
	{
		automobileFactory = new MersedesAutomobileFactory();
	}
	car = automobileFactory->getCar();
	truck = automobileFactory->getTruck();
	bus = automobileFactory->getBus();
	car->show();
	truck->show();
	bus->show();
	if (automobileFactory)
	{
		delete automobileFactory;
	}
	delete car;
	delete truck;
	delete bus;
	system("pause");
}