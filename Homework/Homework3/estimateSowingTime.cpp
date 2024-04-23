// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5
#include <iostream>
#include <map>
using namespace std;

double calculateSowingTime(double area, char machine_type)
{
    if(area <= 0 || (machine_type != 'W' && machine_type != 'X' && machine_type != 'Y' && machine_type != 'Z'))
    {
        return 0;
    }

    //The double is time taken (in minutes) per square foot.
    const map <char, double> machineValues =
    {
        {'W', 12.0/5.0},
        {'X', 10.0/3.0},
        {'Y', 5.0/2.0},
        {'Z', 15.0/7.0}
    };

    return area * machineValues.find(machine_type)->second;
}

int main()
{
    double inputArea;
    char inputMachineType;

    cout << "Enter area of the farmland in sq ft:\n";
    cin >> inputArea;
    cout << "Enter the type of sowing machine to be used:\n";
    cin >> inputMachineType;

    const double timeToFinish = calculateSowingTime(inputArea, inputMachineType);

    if(timeToFinish == 0)
    {
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
    }
    else
    {
        cout << "The time taken is: "
        << timeToFinish
        << " minutes." << endl;
    }

    return 0;
}