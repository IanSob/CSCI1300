#include <iostream>
#include "room.h"

class Hostel
{
    private:
    //Variables
    int _MAX_ROOMS = 20;
    double _cost_per_night;
    Room _rooms[20];

    public:
    //Default constructor
    Hostel();

    //Initializes with _cost_per_night set as the double
    Hostel(double startCostPerNight);

    //Set the _cost_per_night
    void setCostPerNight(double newCostPerNight);
    //Return _cost_per_night
    double getCostPerNight();

    //Sets the room at the index
    void setRoom(int index, Room newRoom);
    //Get room at index
    Room getRoom(int index);

    //Finds the Room index of the room that can accommodate the booking or -1 if none can be found
    int findRoom(Booking bookingToAccommodate);

    //True if all hostel rooms are full
    bool isAtCapacity();

    //Returns the calculated nightly revenue
    double calculateNightlyRevenue();
};