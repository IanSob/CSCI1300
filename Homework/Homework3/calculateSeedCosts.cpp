// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 4
#include <iostream>
#include <map>
using namespace std;

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

int main()
{
    double inputArea;
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
    return 0;
}