#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class IDocumentComponent
{
public:
    virtual string GatherData()=0;

    virtual void AddComponent(IDocumentComponent* documentComponent)=0;
};

class CustomerDocumentComponent : public IDocumentComponent
{
    int CustomerIdToGatherData;
public:
    CustomerDocumentComponent(int customerIdToGatherData)
    {
        CustomerIdToGatherData = customerIdToGatherData;
    }

    string GatherData() override
    {
        string customerData("<Customer>\n");
        switch (CustomerIdToGatherData)
        {
            case 41:
                customerData += "Khylko Andrii\n";
                break;
            default:
                customerData += "Someone else\n";
                break;
        }

        return customerData += "</Customer>\n";
    }

    void AddComponent(IDocumentComponent* documentComponent) override
    {
        cout << "Cannot add to leaf..." << endl;
    }
};

class HeaderDocumentComponent : public IDocumentComponent
{
    string data;
public:
    HeaderDocumentComponent()
    {
        char buf[50];
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        sprintf(buf,"%i:%i:%i\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
        data = buf;
    }

    string GatherData() override
    {
        string headerData("<Header>\n");
        headerData+=data;
        headerData += "</Header>\n";
        return headerData;
    }

    void AddComponent(IDocumentComponent* documentComponent) override
    {
        cout << "Cannot add to leaf..." << endl;
    }
};
class DocumentComponent : public IDocumentComponent
{

    string Name;

    list<IDocumentComponent*> DocumentComponents;


public:
    DocumentComponent(string name)
    {
        Name = name;
    }

    string GatherData() override
    {
        string sb;
        sb += "<";
        sb += Name;
        sb += ">\n";
        for (auto documentComponent : DocumentComponents)
        {
            sb += documentComponent->GatherData();
            sb+="\n";
        }
        sb += "</";
        sb += Name;
        sb += ">\n";;
        return sb;
    }

    void AddComponent(IDocumentComponent *documentComponent) override
    {
        DocumentComponents.push_back(documentComponent);
    }
};

int main()
{
    DocumentComponent *document = new DocumentComponent("ComposableDocument");
    HeaderDocumentComponent *headerDocumentSection = new HeaderDocumentComponent();
    DocumentComponent *body = new DocumentComponent("Body");
    document->AddComponent(headerDocumentSection);
    document->AddComponent(body);
    IDocumentComponent *customerDocumentSection=new CustomerDocumentComponent(41);
    DocumentComponent *orders = new DocumentComponent("Orders");
    //var order0 = new OrderDocumentComponent(0);
    //var order1 = new OrderDocumentComponent(1);
   // orders.AddComponent(order0);
    //orders.AddComponent(order1);
    body->AddComponent(customerDocumentSection);
    body->AddComponent(orders);
    cout<<document->GatherData()<<endl;
	system("pause");
}