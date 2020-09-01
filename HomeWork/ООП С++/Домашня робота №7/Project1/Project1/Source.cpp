#include"Ambulance.h"
#include"ConcreteMixer.h"
#include"FireEngine.h"
#include"Minivan.h"
#include"Pickup.h"
#include"Police.h"
#include"Sedan.h"
#include"Tipper.h"
#include"TruckCrane.h"
int main()
{
	srand(time(NULL));
	Automobile *parking[10];
	for (int i = 0; i < 10; i++)
	{
		switch (rand() % 9)
		{
		case 0:
			parking[i] = new Ambulance("Special", 103);
			break;
		case 1:
			parking[i] = new ConcreteMixer("Builder", 45);
			break;
		case 2:
			parking[i] = new FireEngine("FireEngine", 101);
			break;
		case 3:
			parking[i] = new Minivan("Green", 2345);
			break;
		case 4:
			parking[i] = new Pickup("White", 4921);
			break;
		case 5:
			parking[i] = new Police("Special", 102);
			break;
		case 6:
			parking[i] = new Sedan("Black", 9202);
			break;
		case 7:
			parking[i] = new Tipper("Builder", 56);
			break;
		case 8:
			parking[i] = new TruckCrane("Builder", 28);
			break;
		}
	}
	for (Automobile* item : parking)
	{
		cout << "++++++++++++++++++" << endl;
		item->~Automobile();
	}
	for (auto item : parking)
	{
		delete item;
	}
	system("pause");
}