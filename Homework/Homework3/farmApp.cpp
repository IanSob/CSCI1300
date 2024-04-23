// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 6
#include <iostream>
#include <map>
using namespace std;

//Functions
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

double calculateSeedCost(double area, char seed_grade)
{
    if(area <= 0 || (seed_grade != 'A' && seed_grade != 'B' && seed_grade != 'C'))
    {
        return 0;
    }

    const  map <char, double> seedGrades = 
    {
        {'A', 7.5},
        {'B', 12.5},
        {'C', 27.5}
    };

    return area * seedGrades.find(seed_grade)->second;
}

double calculateFarmArea(double length, double width){
    if(length < 0 || width < 0)
    {
        return 0;
    }
    return length * width;
}



//Main program
int main()
{
    //Variable definitions
    double inputArea;
    int userChoice;


    //User Choice
    cout << "1. Calculate Farm Area \n"
    << "2. Calculate Seeds Cost\n"
    << "3. Estimate Sowing Time\n"
    << "4. Exit\n";
    cin >> userChoice;
    
    switch (userChoice)
    {
        //Calculate farm area
        case 1:
        {
            double lengthFT;
            double widthFT;

            cout << "Enter the length of the farmland in ft:\n";
            cin >> lengthFT;

            cout << "Enter the width of the farmland in ft:\n";
            cin >> widthFT;

            inputArea = calculateFarmArea(lengthFT, widthFT);

            if(inputArea <= 0)
            {
                cout << "Length or width is invalid. Area cannot be calculated." << endl;
                return 0;
            }
            
            cout << "The area is: " << inputArea << " sq ft." << endl;
        }
        break;

        //Calculate seeds cost
        case 2:
        {
            char inputGrade;

            cout << "Enter area of the farmland in sq ft:\n";
            cin >> inputArea;
            cout << "Enter the grade of seed to be used:\n";
            cin >> inputGrade;
            
            double cost = calculateSeedCost(inputArea, inputGrade);

            if(cost == 0)
            {
                cout << "Area or seed grade is invalid. Cost cannot be calculated." << endl;
                return 0;
            }

            cout << "The cost is: $" << cost << endl;
        }
        break;

        //Estimate sowing time
        case 3:
        {
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
        }
        break;

        //Exit
        case 4:
            cout << "You have chosen to exit. Thank you!" << endl;
        break;

        default:
            cout << "Invalid input: exiting." << endl;
        break;
    }

    return 0;
}