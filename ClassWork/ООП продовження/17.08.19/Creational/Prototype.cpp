#include<iostream>
#include<string>

using namespace std;


/*
 *  Это абстрактный базовый класс Device.
 *  Он определяет функцию Clone, которая составляет
 *  основу паттерна Prototype
 */

class Device
{
private:
	string name;
public:
	Device() : Device("Unknown device")
	{}

	Device(const string &dname)
	{
		SetName(dname);
	}

	string GetName() const
	{
		return name;
	}

	void SetName(const string &dname)
	{
		name = dname;
	}

	virtual Device *Clone() const = 0;

	virtual void Show() const
	{
		cout << "\nName is\n" << GetName() << "\n";
	}
};

class Car : public Device
{
private:
	string manufacturer;
	string description;
	string color;

	int year;

public:
	Car() : Car("No information", "No description", "No color", 0)
	{
		SetName("Car");
	}

	Car(const string &cmanufacturer, const string &cdescription, const string &ccolor, int cyear)
	{
		SetName("Car");
		SetManufacturer(cmanufacturer);
		SetDescription(cdescription);
		SetColor(ccolor);
		SetYear(cyear);
	}

public:
	int GetYear() const
	{
		return year;
	}

	string GetManufacturer() const
	{
		return manufacturer;
	}

	string GetDescription() const
	{
		return description;
	}

	string GetColor() const
	{
		return color;
	}

	void SetYear(int cyear)
	{
		year = cyear;
	}

	void SetManufacturer(const string &cmanufacturer)
	{
		manufacturer = cmanufacturer;
	}

	void SetColor(const string &ccolor)
	{
		color = ccolor;
	}

	void SetDescription(const string &cdescription)
	{
		description = cdescription;
	}

	Device *Clone() const override
	{
		return new Car(*this);
	}

	void Show() const override
	{
		Device::Show();
		cout << "\nDescription of car is\n" << GetDescription() << "\n";
		cout << "\nManufacturer of car is\n" << GetManufacturer() << "\n";
		cout << "\nYear of car is\n" << GetYear() << "\n";
		cout << "\nColor of car is\n" << GetColor() << "\n";
	}

};


int main()
{

	string manufacturer;
	cout << endl << "Input manufacturer of car:" << endl;
	std::getline(std::cin, manufacturer);

	string description;
	cout << "Input description of car:" << endl;
	std::getline(std::cin, description);

	string color;
	cout << "Input color of car:" << endl;
	std::getline(std::cin, color);

	int year;
	cout << "Input year of car:" << endl;
	cin >> year;

	Car c(manufacturer, description, color, year);
	c.Show();

	cout << "Let's clone!\nLet's prototype!" << endl;

	Car *copy = (Car *)c.Clone();
	copy->Show();
	delete copy;

	system("pause");
}
