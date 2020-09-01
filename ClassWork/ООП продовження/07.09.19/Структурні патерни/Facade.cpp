#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class SkiRent
{

public:

    int RentBoots(int feetSize, int skierLevel)
    { return 20; }


    int RentSki(int weight, int skierLevel)
    { return 40; }


    int RentPole(int height)
    { return 5; }

};

class SkiResortTicketSystem
{
public:

    int BuyOneDayTicket()
    { return 115; }

    int BuyHalfDayTicket()
    { return 60; }
};


class HotelBookingSystem
{
public:

    int BookRoom(int roomQuality)
    {
        switch (roomQuality)
        {
            case 3:
                return 250;
            case 4:
                return 500;
            case 5:
                return 900;
            default:
                return 0;
        }
    }
};


class SkiResortFacade
{
    SkiRent _skiRent;
    SkiResortTicketSystem _skiResortTicketSystem;
    HotelBookingSystem _hotelBookingSystem;
public:
    int HaveGoodRest(int height, int weight, int feetSize, int skierLevel, int roomQuality)
    {
        int skiPrice = _skiRent.RentSki(weight, skierLevel);
        int skiBootsPrice = _skiRent.RentBoots(feetSize, skierLevel);
        int polePrice = _skiRent.RentPole(height);
        int oneDayTicketPr = _skiResortTicketSystem.BuyOneDayTicket();
        int hotelPrice = _hotelBookingSystem.BookRoom(roomQuality);
        return skiPrice + skiBootsPrice + polePrice + oneDayTicketPr + hotelPrice;
    }
    int HaveRestWithOwnSkis()
    {
        int oneDayTicketPrice = _skiResortTicketSystem.BuyOneDayTicket();
        return oneDayTicketPrice;
    }
};

int main()
{
    SkiResortFacade srf;
    cout<<srf.HaveRestWithOwnSkis()<<endl;
}
