// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 3
#include <iostream>
using namespace std;
double calculateFarmArea(double length, double width){
    if(length < 0 || width < 0)
    {
        return 0;
    }
    return length * width;
}int main(){
    double lengthFT;
    double widthFT;
    double area;
    cout << "Enter the length of the farmland in ft:\n";
    cin >> lengthFT;
    cout << "Enter the width of the farmland in ft:\n";
    cin >> widthFT;
    area = calculateFarmArea(lengthFT, widthFT);
    if(area <= 0)
    {
        cout << "Length or width is invalid. Area cannot be calculated." << endl;
        return 0;
    }cout << "The area is: " << area << " sq ft." << endl;return 0;
}