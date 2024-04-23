// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 4
#include <iostream>
using namespace std;

int manageFeeder(int feeder, int days_since_last_fill)
{
    if(days_since_last_fill < 0)
    {
        return -1;
    }

    int daysTillRefill;
    switch(feeder)
    {
        case 1:
            daysTillRefill = (33 - (days_since_last_fill * 2))/2;
        break;
        case 2:
            daysTillRefill = (27 - (days_since_last_fill * 4))/4;
        break;
        case 3:
            daysTillRefill = (16 - (days_since_last_fill * 3))/3;
        break;
    }

    if(daysTillRefill < 0)
    {
        return 0;
    }

    return daysTillRefill;
}

void printDaysTillRefill(int daysTillRefill, int feederType)
{
    if(daysTillRefill == 0)
    {
        cout << "Feeder " << feederType << " is currently empty and should be filled immediately." << endl;
        return;
    }
    else if(daysTillRefill < 0)
    {
        cout << "Invalid input for days_since_last_fill!" << endl;
        return;
    }

    cout << "Feeder " << feederType << " will need to be filled in " << daysTillRefill << " days." << endl;
    return;
}

int main()
{
    int feederInput;
    int daysSinceFillInput;

    cout << "1. Check Feeder 1\n"
    << "2. Check Feeder 2\n"
    << "3. Check Feeder 3\n"
    << "4. Check All Feeders\n"
    << "Enter your choice:\n";

    cin >> feederInput;

    if(feederInput == 4)
    {
        cout << "How many days ago were all the feeders filled?\n";
        cin >> daysSinceFillInput;
        printDaysTillRefill(manageFeeder(1, daysSinceFillInput), 1);
        printDaysTillRefill(manageFeeder(2, daysSinceFillInput), 2);
        printDaysTillRefill(manageFeeder(3, daysSinceFillInput), 3);
    }
    else if(feederInput < 1 || feederInput > 4)
    {
        cout << "Invalid menu choice!" << endl;
    }
    else
    {
        cout << "How many days ago was feeder " << feederInput << " filled?\n";
        cin >> daysSinceFillInput;
        printDaysTillRefill(manageFeeder(feederInput, daysSinceFillInput), feederInput);
    }


    return 0;
}