#include <iostream>
using namespace std;

/*
I'm assuming you intended this question to be solved with the given 
template so I copied an pasted that then added to the specified places.
*/
int main()
{
    //Declaring variables
    double fahrenheit;
    double celsius;

    //Prompt
    cout << "Please input temperature (farenheit)" << endl;
    cin >> fahrenheit;

    //Temperature calculation
    celsius = (fahrenheit - 32) * (5.0 / 9.0);

    cout << "The temperature is " << celsius << " degree Celsius." << endl;
    return 0;
}