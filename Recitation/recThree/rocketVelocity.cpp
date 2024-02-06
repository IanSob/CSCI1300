#include <iostream>
#include <map>
using namespace std;

int main()
{
    double initialVelocity = 0;
    char selectedFuelType;

    cout << "Enter initial velocity:\n";
    cin >> initialVelocity;

    cout << "Enter the fuel type:\n";
    cin >> selectedFuelType;

    //Probably a better way to do this but oh well.
    if(selectedFuelType != 'C' && selectedFuelType != 'A' && selectedFuelType != 'B')
    {
        cout << "Error: Selected fuel type does not exist." << endl;
        return 0;
    }

    //Evil code :)
    const map <char, int> fuelTypes = {{'A', (initialVelocity > 40) ? 3 : ((initialVelocity >= 10) ? 6 : 5)}, {'B', (initialVelocity > 40) ? 6 : ((initialVelocity >= 10) ? 12 : 10)}, {'C', (initialVelocity > 40) ? 9 : ((initialVelocity >= 10) ? 24 : 20)}};

    cout << "The final velocity is "
    << initialVelocity + (fuelTypes.find(selectedFuelType)->second * 20)
    << " m/s" << endl;

    return 0;
}