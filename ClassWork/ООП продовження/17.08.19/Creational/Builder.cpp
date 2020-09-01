//++++++++++++++++++++++++++Builder
#include<iostream>
#include<string>

using namespace std;

class Laptop
{
	string MonitorResolution;
	string Processor;
	string Memory;
	string HDD;
	string Battery;
public:
	void Show()
	{
		cout << "Resolution: " << MonitorResolution << endl;
		cout << "CPU: " << Processor << endl;
		cout << "RAM: " << Memory << endl;
		cout << "HDD: " << HDD << endl;
		cout << "Battery: " << Battery << endl;
	}


	const string &getMonitorResolution() const
	{
		return MonitorResolution;
	}

	void setMonitorResolution(const string &MonitorResolution)
	{
		Laptop::MonitorResolution = MonitorResolution;
	}

	const string &getProcessor() const
	{
		return Processor;
	}

	void setProcessor(const string &Processor)
	{
		Laptop::Processor = Processor;
	}

	const string &getMemory() const
	{
		return Memory;
	}

	void setMemory(const string &Memory)
	{
		Laptop::Memory = Memory;
	}

	const string &getHDD() const
	{
		return HDD;
	}

	void setHDD(const string &HDD)
	{
		Laptop::HDD = HDD;
	}

	const string &getBattery() const
	{
		return Battery;
	}

	void setBattery(const string &Battery)
	{
		Laptop::Battery = Battery;
	}
};

class LaptopBuilder
{
protected:
	Laptop *laptop;
public:
	virtual ~LaptopBuilder() = default;
	void CreateNewLaptop()
	{
		laptop = new Laptop();
	}

	Laptop *GetMyLaptop()
	{
		return laptop;
	}

	// Кроки, необхідні щоб створити ноутбук
	virtual void SetMonitorResolution() = 0;

	virtual void SetProcessor() = 0;

	virtual void SetMemory() = 0;

	virtual void SetHDD() = 0;

	virtual void SetBattery() = 0;

};

class GamingLaptopBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution() override
	{
		laptop->setMonitorResolution("2880 amount 1800");
	}

	void SetProcessor() override
	{
		laptop->setProcessor("Intel Core i7, 2.8 GHz");
	}

	void SetMemory() override
	{
		laptop->setMemory("16 Gb");
	}

	void SetHDD() override
	{
		laptop->setHDD("2 Tb");
	}

	void SetBattery() override
	{
		laptop->setBattery("6 lbs");
	}
};

class TripLaptopBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution() override
	{
		laptop->setMonitorResolution("1900X1200");
	}

	void SetProcessor() override
	{
		laptop->setProcessor("Core 2 Duo, 2.5 GHz");
	}

	void SetMemory() override
	{
		laptop->setMemory("6 Gb");
	}

	void SetHDD() override
	{
		laptop->setHDD("500 Gb");
	}

	void SetBattery() override
	{
		laptop->setBattery("2 lbs");
	}
};


class BuyLaptop
{
	LaptopBuilder *_laptopBuilder;
public:
	void SetLaptopBuilder(LaptopBuilder *lBuilder)
	{
		_laptopBuilder = lBuilder;
	}

	// Змушує будівельника повернути цілий ноутбук
	Laptop *GetLaptop()
	{
		return _laptopBuilder->GetMyLaptop();
	}

	// Змушує будівельника додавати деталі
	void ConstructLaptop()
	{
		_laptopBuilder->CreateNewLaptop();
		_laptopBuilder->SetMonitorResolution();
		_laptopBuilder->SetProcessor();
		_laptopBuilder->SetMemory();
		_laptopBuilder->SetHDD();
		_laptopBuilder->SetBattery();
	}
};

int main()
{
	TripLaptopBuilder *tripBuilder = new TripLaptopBuilder();
	GamingLaptopBuilder *gamingBuilder = new GamingLaptopBuilder();
	BuyLaptop *shopForYou = new BuyLaptop();//Директор
	shopForYou->SetLaptopBuilder(gamingBuilder);
	shopForYou->ConstructLaptop();
	Laptop *laptop = shopForYou->GetLaptop();
	laptop->Show();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	delete laptop;
	shopForYou->SetLaptopBuilder(tripBuilder);
	shopForYou->ConstructLaptop();
	laptop = shopForYou->GetLaptop();
	laptop->Show();
	delete tripBuilder;
	delete gamingBuilder;
	delete shopForYou;
	system("pause");
}
