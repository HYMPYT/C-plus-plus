#include<iostream>
#include<string>

using namespace std;

class OldElectricitySystem
{
public:
    string MatchThinSocket()
    {
        return "220V";
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
public:
    string MatchWideSocket()override
    {
        return "220V";
    }
};


class Adapter : public INewElectricitySystem
{
    OldElectricitySystem *_adaptee;
public:
    Adapter(OldElectricitySystem *adaptee)
    {
        _adaptee = adaptee;
    }

    string MatchWideSocket()override
    {
        return _adaptee->MatchThinSocket();
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
    NewElectricitySystem *newElectricitySystem = new NewElectricitySystem();
    ElectricityConsumer::ChargeNotebook(newElectricitySystem);
    // 2)
    OldElectricitySystem *oldElectricitySystem = new OldElectricitySystem();
    Adapter *adapter = new Adapter(oldElectricitySystem);
    ElectricityConsumer::ChargeNotebook(adapter);

    delete newElectricitySystem;
    delete oldElectricitySystem;
    delete adapter;
}
