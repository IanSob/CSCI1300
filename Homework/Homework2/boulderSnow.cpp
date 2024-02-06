#include <iostream>

using namespace std;

int main()
{
    // declare all the variables
    int snowfall_amount;

    // prompt the user & get their input
    cout << "What is the amount of snowfall?" << endl;
    cin >> snowfall_amount;

    // input validation: snowfall amount must be positive
    if(snowfall_amount < 0)
    {
        cout << "Invalid snowfall amount." << endl;
        return 0;
    }

    // decide if you need to wear snow boots based on the snowfall amount
    if(snowfall_amount > 5)
    {
        cout << "You need your snow boots." << endl;
    }
    else
    {
        cout << "You don't need snow boots." << endl;
    }

    return 0;
}