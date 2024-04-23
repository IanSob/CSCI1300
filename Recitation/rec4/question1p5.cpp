#include <iostream>
#include <string>
#include <cassert>

using namespace std;

double getPrice(double area, string color)
{
    assert(area >= 0); 
    double cost = 0.0;

    if (color == "green")
    {
        cost = 4; 
    }
    else if (color == "red")
    {
        cost = 3;
    }
    else if (color == "orange")
    {
        cost = 2;
    }
    else if (color == "blue")
    {
        cost = 1;
    } 

    return area * cost;
}


int main()
{
    string color, shape;
    int area_choice;
    double radius;
    double area = 0;

    cout << "Enter the area of the frame: (1) 5x5 (2) 4x6 (3) 8x10" << endl;
    cin >> area_choice;

    assert(area_choice == 1 || area_choice == 2 || area_choice == 3);

    if(area_choice == 1)
    {
        area = 5 * 5;
    }
    else if (area_choice == 2)
    {
        area = 4 * 6; 
    }
    else if (area_choice == 3)
    {
        area = 8 * 10; 
    }

    cout << "Enter the color of the frame: (green, red, orange, blue): ";
    cin >> color;

    assert(color == "green" || color == "red" || color == "orange" || color == "blue");

    double price = getPrice(area, color);
    
    cout << "You will receive a "
    << color 
    << " color frame with a price of $" 
    << price
    << ". Thank you for your business." << endl;

    return 0;
}
