#include <iostream>
#include <string>

struct Booking
{
    std::string name;
    int num_people;

    Booking();

    //Constructor to make making the array easier
    Booking(std::string inName, int inNum_people);
};

void displayBooking(Booking bookings[], int num_bookings);