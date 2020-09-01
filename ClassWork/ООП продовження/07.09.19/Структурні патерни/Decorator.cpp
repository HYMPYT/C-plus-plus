
#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class Car
{
protected:
    string BrandName;
public:

    virtual void Go()
    {
        cout << "I'm " << BrandName << " and I'm on my way...";
    }
};

class Mercedes : public Car
{
public:

    Mercedes()
    {
        BrandName = "Mercedes";
    }
};


class DecoratorCar : public Car
{
protected:
    Car *DecoratedCar;
public:

    DecoratorCar(Car *decoratedCar)
    {
        DecoratedCar = decoratedCar;
    }

    ~DecoratorCar()
    {
        delete DecoratedCar;
    }

    void Go() override
    {
        DecoratedCar->Go();
    }
};

class AmbulanceCar : public DecoratorCar
{
public:

    AmbulanceCar(Car *decoratedCar) : DecoratorCar(decoratedCar)
    {}

    void Go() override
    {
        DecoratorCar::Go();
        cout << "... beep-beep-beeeeeep ..." << endl;
    }
};

int main()
{
    AmbulanceCar *doctorsDream = new AmbulanceCar(new Mercedes());
    doctorsDream->Go();
    delete doctorsDream;
}*/
