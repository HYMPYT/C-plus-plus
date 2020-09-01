#include <iostream>
#include <string>
#include <list>
#include <map>
#include <ctime>

using namespace std;

class Unit
{
protected:
    string Name;
    int Health;
    string Picture;
public:
    const string &getName() const
    {
        return Name;
    }

    void setName(const string &Name)
    {
        Unit::Name = Name;
    }

    int getHealth() const
    {
        return Health;
    }

    void setHealth(int Health)
    {
        Unit::Health = Health;
    }

    const string &getPicture() const
    {
        return Picture;
    }

    void setPicture(const string &Picture)
    {
        Unit::Picture = Picture;
    }

    virtual void Show()=0;

    virtual ~Unit() = 0;
};

Unit::~Unit()
{}

class UnitImagesFactory
{
public:
    static map<int, string> Images;

    static string CrateDragonImage()
    {

        return "Dragon.jpg";
    }

    static string CrateGoblinImage()
    {
        return "Goblin.jpg";
    }

};

class Goblin : public Unit
{
public:
    Goblin()
    {
        Name = "Goblin";
        Health = 8;
        Picture = UnitImagesFactory::CrateGoblinImage();
    }

    void Show()
    {
        cout << "++++++++++++++++++++++++" << endl;
        cout << Name << endl;
        cout << Health << endl;
        cout << Picture << endl;
        cout<<"++++++++++++++++++++++++"<<endl;
    }
};

class Dragon : public Unit
{
public:
    Dragon()
    {
        Name = "Dragon";
        Health = 50;
        Picture = UnitImagesFactory::CrateDragonImage();
    }
    void Show()
    {
        cout << "**********************" << endl;
        cout << Name << endl;
        cout << Health << endl;
        cout << Picture << endl;
        cout<<"**********************"<<endl;
    }
};

class Parser
{
public:

    list<Unit *> ParseHTML()
    {
        list<Unit *> units;
        for (int i = 0; i < 150; i++) units.push_back(new Dragon());
        for (int i = 0; i < 500; i++) units.push_back(new Goblin());
        cout << "Dragons and Goblins are parsed from HTML page." << endl;
        return units;
    }
};

int main()
{
    Parser obj;
    list<Unit *> units = obj.ParseHTML();
    for (auto i : units)
    {
        i->Show();
    }

    for (auto i=units.begin(); i!=units.end();++i)
    {
        delete *i;
    }
	system("pause");
}
