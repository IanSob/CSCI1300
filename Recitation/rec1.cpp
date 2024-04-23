#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float seconds = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;

    //Getting user input.
    cout << "Please enter seconds:\n";
    cin >> seconds;

    //Find days
    days = floor(seconds / 86400.0);
    //Remove days (in seconds)
    seconds -= days * 86400.0;

    //Find Hours
    hours = floor(seconds / 3600.0);
    //Remove hours
    seconds -= hours * 3600.0;

    //Find minutes
    minutes = floor(seconds / 60.0);
    //Remove minutes (finding seconds)
    seconds -= minutes * 60.0;

    //Days
    cout << "The time is " + to_string(days) + " days, ";
    //Hours
    cout << to_string(hours) + " hours, ";
    //Minutes
    cout << to_string(minutes) + " minutes, and ";
    //Seconds
    cout << to_string(seconds) + " seconds.";
}