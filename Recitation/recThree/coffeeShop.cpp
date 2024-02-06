#include <iostream>
using namespace std;

double RefillWater(double currentLevel, double amount)
{
    //Error handling
    if(currentLevel < 0)
    {
        cout << "Error: currentLevel must be > 0!\n"
        << "Returning 0 instead.\n";
        return 0;
    }
    else if(amount < 0)
    {
        cout << "Error: amount must be > 0!\n"
        << "Returning currentLevel instead.\n";
        return currentLevel;
    }

    return currentLevel + amount;
}

double UseWater(double currentLevel, double amount)
{
    if(currentLevel < 0)
    {
        cout << "Error: currentLevel must be > 0!\n"
        << "Returning 0 instead.\n";
        return 0;
    }
    else if(amount < 0)
    {
        cout << "Error: amount must be > 0!\n"
        << "Returning currentLevel instead.\n";
        return currentLevel;
    }
    else if((currentLevel - amount) < 0)
    {
        cout << "Error: currentLevel - amount returns < 0!\n"
        << "Returning currentLevel instead.\n";
        return currentLevel;
    }

    return currentLevel - amount;
}


//Combined main that asks what you wish to do.
int main()
{
    char functionToCall;
    double currentWaterLevel = 0;
    double changeAmount = 0;

    //What function to use
    cout << "Would you like to refill water (R) or use water (U)?\n";
    cin >> functionToCall;

    //Gathering inputs
    cout << "Enter current water level:\n";
    cin >> currentWaterLevel;
    cout << "Enter amount of water to use/fill:\n";
    cin >> changeAmount;

    if(functionToCall == 'R' || functionToCall == 'r')
    {
        currentWaterLevel = RefillWater(currentWaterLevel, changeAmount);
    }
    else if(functionToCall == 'U' || functionToCall == 'u')
    {
        currentWaterLevel = UseWater(currentWaterLevel, changeAmount);
    }
    else
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    //I kept the output regardless because that's what I think you want??
    cout << "The new water level is " << currentWaterLevel << endl;

    return 0;
}