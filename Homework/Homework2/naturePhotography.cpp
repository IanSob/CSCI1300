#include <iostream>
using namespace std;

int main()
{
    float tommorowTemperature = 0;
    float tommorowWind = 0;

    //Temperatjure input and prompt
    cout << "What is tomorrow's temperature looking like?\n";
    cin >> tommorowTemperature;

    //Wind input and prompt
    cout << "What is tomorrow's wind speed looking like?\n";
    cin >> tommorowWind;

    if(tommorowWind < 0)
    {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    if(tommorowTemperature >= -10 && tommorowTemperature <= 10 && tommorowWind <= 20)
    {
        cout << "The weather conditions are ideal for photography tomorrow.\n";
    }
    else
    {
        cout << "The weather conditions are not ideal for photography tomorrow.";
    }

    return 0;
}