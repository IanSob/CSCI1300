#include "hostel.h"
#include <iomanip>
#include <cassert>
using namespace std;

Hostel::Hostel()
{
    _cost_per_night = 0;
}

Hostel::Hostel(double startCostPerNight)
{
    _cost_per_night = startCostPerNight;
}

void Hostel::setCostPerNight(double newCostPerNight)
{
    _cost_per_night = newCostPerNight;
}

double Hostel::getCostPerNight()
{
    return _cost_per_night;
}

void Hostel::setRoom(int index, Room newRoom)
{   
    //Make sure index is in range
    if(index < _MAX_ROOMS)
    {
        _rooms[index] = newRoom;
    }
}

Room Hostel::getRoom(int index)
{
    return _rooms[index];
}

int Hostel::findRoom(Booking bookingToAccommodate)
{
    if(bookingToAccommodate.num_people <= 0)
    {
        return -1;
    }

    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        if(bookingToAccommodate.num_people + _rooms[i].getNumCurrentOccupants() <= 10)
        {
            return i;
        }
    }
    
    return -1;
}

double Hostel::calculateNightlyRevenue()
{
    double totalRevenue = 0;

    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        for (int j = 0; j < _rooms[i].getNumCurrentOccupants(); j++)
        {
            totalRevenue += _cost_per_night;
        }      
    }
    
    return totalRevenue;
}

bool Hostel::isAtCapacity()
{
    for (int i = 0; i < _MAX_ROOMS; i++)
    {
        if(_rooms[i].getNumCurrentOccupants() < 10)
        {
            return false;
        }
    }
    
    return true;
}