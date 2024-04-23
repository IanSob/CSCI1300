#include "bookingStruct.h"
using namespace std;

//This can be used to test the displayBooking function
// int main()
// {
//     Booking listOfBookings[3] =
//     {
//         Booking("John", 3),
//         Booking("Gabe", 5),
//         Booking("Sally", 1),
//     };

//     displayBooking(listOfBookings, 3);
// }

Booking::Booking()
{
    name = "";
    num_people = 0;
}

Booking::Booking(string inName, int inNum_people)
{
    name = inName;
    num_people = inNum_people;
}

//Displays the items within bookings array.
void displayBooking(Booking bookings[], int num_bookings)
{
    for (int i = 0; i < num_bookings; i++)
    {
        cout << bookings[i].name << " " << bookings[i].num_people << endl;
    }
}