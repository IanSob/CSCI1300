#include <iostream>
using namespace std;

int main()
{
    int hours = 0;

    //Getting user input
    cout << "How many hours have passed? \n";
    cin >> hours;

    //Calculating pool levels
    float indoorPoolLevel = 12 + (0.1 * hours);
    float outdoorPoolLevel = 18 + (0.3 * hours);

    cout << "The indoor pool has " + to_string(indoorPoolLevel) + " inches of water, ";
    cout << "The outdoor pool has  " + to_string(outdoorPoolLevel) + " inches of water.";
   return 0;
}