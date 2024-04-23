// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2, int distance_type)
{
    if(distance_type == 1)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    }
    else if(distance_type == 2)
    {
        return sqrt(pow(x2 - x1, 2.0) + pow(y1 - y2, 2.0));
    }
    
    return -1;
}

int main()
{
    int inputDistanceType;
    double inputX1;
    double inputX2;
    double inputY1;
    double inputY2;

    cout << "Enter distance type:\n";
    cin >> inputDistanceType;
    
    cout << "Enter x1:\n";
    cin >> inputX1;

    cout << "Enter y1:\n";
    cin >> inputY1;

    cout << "Enter x2:\n";
    cin >> inputX2;

    cout << "Enter y2:\n";
    cin >> inputY2;

    const double distanceOutput = calculateDistance(inputX1, inputY1, inputX2, inputY2, inputDistanceType);

    if(distanceOutput == -1)
    {
        cout << "Invalid distance type!" << endl;
        return 0;
    }

    cout << "The distance between the points is: " << fixed << setprecision(3) << distanceOutput << endl;
    return 0;
}