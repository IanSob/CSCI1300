#include <fstream>
#include "room.h"
using namespace std;

Room::Room()
{
    _room_id = "";
    _num_current_occupants = 0;
    _num_current_bookings = 0;
}

Room::Room(string roomID)
{
    _room_id = roomID;
    _num_current_occupants = 0;
    _num_current_bookings = 0;
}

void Room::setRoomID(std::string roomID)
{
    _room_id = roomID;
}

string Room::getRoomID()
{
    return _room_id;
}

void Room::setNumCurrentOccupants(int newNum)
{
    _num_current_occupants = newNum;
}

int Room::getNumCurrentOccupants()
{
    return _num_current_occupants;
}

bool Room::addBooking(std::string fileName)
{
//Some of these checks aren't required but I still included them.
    if(_num_current_occupants >= _MAX_OCCUPANTS)
    {
        cout << "Sorry Room " << _room_id << " is already at capacity!!" << endl;
        return false;
    }

    ifstream fileToBeRead(fileName);

    //If we can open the file
    if(fileToBeRead.is_open())
    {
        string currentLine;
        //Current line as a number
        int numberedLine = 1;

        //For every line in the file
        while (getline(fileToBeRead, currentLine))
        {
            string splitStrings[2];

            //Just skips over empty lines.
            if(currentLine.length() == 0)
            {
                continue;
            }

            //If the split line is 2 values (the name and number of poeple)
            if(split(currentLine, ',', splitStrings, 2) == 2)
            {
                //If the second value is not an int
                for (int i = 0; i < static_cast<int>(splitStrings[1].length()); i++)
                {
                    if(!isdigit(splitStrings[1][i]))
                    {
                        cout << "Line " 
                        << numberedLine 
                        << " contains a non-integer value for second input: '" 
                        << splitStrings[1][i] << "'." << endl;
                        return false;
                    }
                }

                if(splitStrings[1].length() == 0)
                {
                    cout << "Line "
                    << numberedLine
                    << " does not have a second input!"
                    << endl;
                    return false;
                }
                
                const int partySize = stoi(splitStrings[1]);

                if(_num_current_occupants + partySize > _MAX_OCCUPANTS)
                {
                    cout << "Cannot accommodate the booking for '"
                    << currentLine
                    << "' in the room "
                    << _room_id
                    << "!! You must book in smaller parties!\n";

                    cout << "The room can accommodate only "
                    << _MAX_OCCUPANTS - _num_current_occupants
                    << " more!" << endl;
                }

                _bookings[_num_current_bookings] = Booking(splitStrings[0], partySize);
                _num_current_bookings++;
                _num_current_occupants += partySize;
            }
            else
            {
                cout << "Too many or too few inputs on line " << numberedLine << "." << endl;
                return false;
            }

            numberedLine++;
        }       
    }
    else
    {
        cout << "The file cannot be opened!" << endl;
        return false;
    }
    
    cout << "Successfully added all bookings." << endl;
    return true;
}

bool Room::removeBooking(std::string bookingName)
{
    int positionToRemove = -1;

    if(_num_current_occupants <= 0)
    {
        cout << "There are no occupants to remove in "
        << _room_id << endl;
        return false;
    }

    //Finds the first occurrence of the booking to remove (any negative if couldn't be found)
    for (int i = 0; i < _num_current_bookings; i++)
    {
        if(_bookings[i].name == bookingName)
        {
            positionToRemove = i;
            break;
        }
    }

    //When we cannot find the booking
    if(positionToRemove < 0)
    {
        cout << "Booking "
        << bookingName
        << " not found in room "
        << _room_id << endl;
        return false;
    }
    
    //For later results
    Booking removedBooking = _bookings[positionToRemove];

    //Copying the values of the array after a certain point to re-insert
    Booking bookingsAfterI[_num_current_bookings - (positionToRemove + 1)];
    for (int i = positionToRemove + 1, j = 0; i < _num_current_bookings; i++)
    {
        bookingsAfterI[j] = _bookings[i];
        j++;
    }
    
    //Reassigns the variables
    for (int i = positionToRemove, j = 0; i < _num_current_bookings - 1; i++)
    {
        _bookings[i] = bookingsAfterI[j];
        j++;
    }

    //Updating the number of bookings
    _num_current_bookings--;
    //Update occupants
    _num_current_occupants -= removedBooking.num_people;

    //Resetting the booking at the end
    _bookings[_num_current_bookings].name = "";
    _bookings[_num_current_bookings].num_people = 0;

    //Prints the results
    cout << "Removed booking: "
    << removedBooking.name
    << " from room "
    << _room_id
    << "\nUpdated Room stats for room: "
    << _room_id
    << "\nNumber of Current Booking(s): "
    << _num_current_bookings
    << "\nNumber of Current Occupants: "
    << _num_current_occupants
    << endl;

    return true;
}

int Room::split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int numberOfSplits = 0;

    if(input_string.length() == 0)
    {
        return 0;
    }

    for (int i = 0; i < static_cast<int>(input_string.length()); i++)
    {
        //If we are on a separator
        if(input_string[i] == separator)
        {
            numberOfSplits++;
            //If the number of splits is becoming too high, we return -1 and no longer write to the array.
            if(numberOfSplits >= ARR_SIZE)
            {
                return -1;
            }
        }
        else
        {
            arr[numberOfSplits].push_back(input_string[i]);
        }
    }
    
    return numberOfSplits + 1;
}