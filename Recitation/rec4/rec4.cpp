#include <iostream>
#include <string>
#include <cassert>
using namespace std;
/**
* @brief Function to determine the color associated with their birth month
* @param birthMonth of the user
* @return string - color associated with their birth month
*/
string getColor(int birthMonth)
{
    // Check the birth month and return the corresponding color
    if (birthMonth >= 1 && birthMonth <= 3)
    {
    return "green";
    }
    else if (birthMonth >= 4 && birthMonth <= 6)
    {
    return "red";
    }
    else if (birthMonth >= 7 && birthMonth <= 9)
    {
    return "orange";
    }
    else if (birthMonth >= 10 && birthMonth <= 12)
    {
    return "blue";
    }
    else
    {
    return "";
    }
}
/**
* @brief Function to calculate the area of the coaster based on shape(square or
circle)↪→
* @param shape of the coaster that user specified
* @param size of the coaster, which is either the side length (for a square) or the
radius (for a circle)↪→
* @return double - area of the coaster based on the shape
*/
double getArea(string shape, double size)
{
    const double pi = 3.14159;
    if (shape == "square")
    {
    return size * size;
    }
    else if (shape == "circle")
    {
    return pi * size * size;
    }
    else
    {
    return 0.0;
    }
}
/**
* @brief Function to calculate the price of the coaster based on area and color, where
each color has a specific cost associated with it↪→
* @param area of the coaster
* @param color of the coaster
* @return double - price of the coaster based on area and color
*/
double getPrice(double area, string color)
{
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
    assert(getColor(0) == "");
    assert(getColor(13) == "");
    assert(getColor(5) == "red");
    assert(getColor(2) == "green");
    assert(getArea("triangle", 3) == 0);
    assert(getArea("square", -5) == 25);
    assert(getArea("square", 5) == 25);
    assert(getArea("circle", -1) == 3.14159);
    assert(getPrice(1, "red") == 3);
    assert(getPrice(2, "z") == 0);
    assert(getPrice(-1, "green") == -4);
    assert(getPrice(3, "blue") == 3);

    cout << "Asserts passed." << endl;
    return 0;
}