#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class Beverage
{
public:
    virtual void info() = 0;

    virtual ~Beverage() = default;

};

class Coffee : public Beverage
{
public:
    void info() override
    {
        cout << "coffee" << endl;
    }
};

class Decorator:public Beverage
{
protected:
    Beverage *component= nullptr;
public:
    Decorator(Beverage *component)
    {
        this->component = component;
    }
    void info() override
    {
        if(component)
            component->info();
    }
    ~Decorator()override
    {
        delete component;
    }

};
class WithSugar:public Decorator
{
public:
    WithSugar( Beverage* c):Decorator(c)
    {

    }
    void info()override
    {
        Decorator::info();
        cout<<"with sugar"<<endl;
    }
};
class WithMilk:public Decorator
{
public:
    WithMilk( Beverage* c):Decorator(c)
    {

    }
    void info()override
    {
        Decorator::info();
        cout<<"with milk"<<endl;
    }

};
int main()
{
    Beverage* cmp = new Coffee();
    // cmp->info();
    WithMilk* a = new WithMilk(new WithSugar(new WithSugar(new WithMilk(cmp))));
    
	WithMilk*c = new WithMilk(cmp);
    WithSugar *a = new WithSugar(c);
    WithSugar *b = new WithSugar(a);
    b->info();
    a->info();
	system("pause");
}