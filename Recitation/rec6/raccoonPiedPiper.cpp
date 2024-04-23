#include <iostream>
#include <cassert>
#include <algorithm> //For clamp function
using namespace std;

/*
Note: I coded this function to not go into the negative and not add negative values.
If it did go in the negative the park service would be giving you money which shouldn't be possible.
Since the code does not return negative, the most the piper would have to pay is $945 after 10 years if he keeps going.
*/
int raccoonPiedPiper(int years);

int main()
{
    //The asserts (commented because they generate useless output)
    // assert(raccoonPiedPiper(-1) == -1);
    // assert(raccoonPiedPiper(0) == 0);
    // assert(raccoonPiedPiper(1) == 50);
    // assert(raccoonPiedPiper(2) == 139);

    int inputYears;

    //Getting years
    cout << "Please enter the number of years:\n";
    cin >> inputYears;

    //Output
    cout << "The costs are as follows:\n";
    int finalCost = raccoonPiedPiper(inputYears);
    cout << "The total cost is: " << finalCost << " dollars" <<  endl;
}

int raccoonPiedPiper(int years)
{
    //Make sure years is positive or 0
    if (years < 0)
    {
        return -1;
    }

    //Will default to 0 if the code does not run ()
    int totalCost = 0;

    //Runs for each year starting at 1 (0 years wont run this code)
    for (int i = 1; i <= years; i++)
    {
        //The current number of raccoons the piper has for our year (i)
        const int numberOfRaccoons = i - 1;
        //Starting cost for the piper
        const int startingCost = clamp((-5 * numberOfRaccoons) + 50, 0, 50);

        //For each raccoon of current year and when no raccoons
        for (int j = 0; j <= numberOfRaccoons; j++)
        {
            totalCost += clamp(startingCost - j, 0, 50);
            cout << clamp(startingCost - j, 0, 50) << " ";
        }
        cout << endl;
    }

    return totalCost;
}