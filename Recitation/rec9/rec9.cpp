#include <iostream>
#include <cassert>
#include "room.h"
using namespace std;

int main()
{
    Room myRoom("A Room");

    //Works for what is currently in "bookings.txt".
    assert(myRoom.addBooking("bookings.txt") == true);
    assert(myRoom.removeBooking("Susan") == true);

    //Assert checking set/get ID
    myRoom.setRoomID("Test");
    assert(myRoom.getRoomID() == "Test");

    //Assert checking get/set occupant #
    myRoom.setNumCurrentOccupants(1);
    assert(myRoom.getNumCurrentOccupants() == 1);

    cout << "Asserts passed!" << endl;
}