#include<iostream>
#include <string>
#include "bookingStruct.h"

class Room
{
public:
    //Default constructor
    Room();

    //Initializes room with _room_id set to in string
    Room(std::string roomID);
    
    //Sets the room ID
    void setRoomID(std::string roomID);

    //Get the room ID
    std::string getRoomID();

    //Sets the current number of occupants to newNum
    void setNumCurrentOccupants(int newNum);

    //Get the number of current occupants
    int getNumCurrentOccupants();

    //Adds a booking from file with name fileName. Returns true if all items were populated.
    bool addBooking(std::string fileName);

    //Removes the booking with name bookingName. Returns true if successful.
    bool removeBooking(std::string bookingName);
private:
    //ID of room
    std::string _room_id;

    //Maximum number of occupants
    const int _MAX_OCCUPANTS = 10;

    //Number of current occupants
    int _num_current_occupants;

    //Number of current bookings
    int _num_current_bookings;

    //Array of all the current bookings
    Booking _bookings[10];

    //Split function taken from last rec.
    int split(std::string input_string, char separator, std::string arr[], const int ARR_SIZE);
};