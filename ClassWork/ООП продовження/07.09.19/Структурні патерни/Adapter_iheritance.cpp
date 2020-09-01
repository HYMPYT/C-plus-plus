#include<iostream>
#include<string>

using namespace std;

class OldElectricitySystem
{
    string _voltage;
public:
    OldElectricitySystem(string voltage)
    {
        _voltage = voltage;
    }

    string MatchThinSocket()
    {
        return _voltage;
    }
};

class INewElectricitySystem
{
public:
    virtual string MatchWideSocket() = 0;
    virtual ~INewElectricitySystem()= default;
};

class NewElectricitySystem : public INewElectricitySystem
{

    string _voltage;
public:
    NewElectricitySystem(string voltage)
    {
        _voltage = voltage;
    }

    string MatchWideSocket()override
    {
        return _voltage;
    }
};


class Adapter : public INewElectricitySystem, public OldElectricitySystem
{

public:

    Adapter(const string &voltage) : OldElectricitySystem(voltage)
    {}

    string MatchWideSocket()override
    {
        return MatchThinSocket();
    }
};

class ElectricityConsumer
{
public:
    static void ChargeNotebook(INewElectricitySystem *electricitySystem)
    {
        cout << electricitySystem->MatchWideSocket() << endl;
    }
};

int main()
{
    // 1)
    NewElectricitySystem *newElectricitySystem = new NewElectricitySystem("220V");
    ElectricityConsumer::ChargeNotebook(newElectricitySystem);
    // 2)
    Adapter *adapter = new Adapter("220V");
    ElectricityConsumer::ChargeNotebook(adapter);
    delete newElectricitySystem;
    delete adapter;
}
