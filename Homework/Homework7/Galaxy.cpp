// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 1-3

#include "Galaxy.h"
#include <iomanip>
using namespace std;

Galaxy::Galaxy()
{
    _name = "";
    _current_size = 0;
    
    for (int i = 0; i < _MAX_SIZE; i++)
    {
        _radii[i] = 0;
    }
}

Galaxy::Galaxy(std::string galaxyName)
{
    _name = galaxyName;
    _current_size = 0;

    for (int i = 0; i < _MAX_SIZE; i++)
    {
        _radii[i] = 0;
    }
}

Galaxy::Galaxy(std::string name, int radii[], int arr_size)
{
    _name = name;
    
    if(arr_size <= _MAX_SIZE)
    {
        _current_size = arr_size;
    }
    else
    {
        _current_size = _MAX_SIZE;
    }

    //Fill array
    for (int i = 0; i < _current_size; i++)
    {
        _radii[i] = radii[i];
    }
    //Fill the rest with zeros
    for (int i = _current_size; i < _MAX_SIZE; i++)
    {
        _radii[i] = 0;
    }
}

string Galaxy::getName()
{
    return _name;
}

int Galaxy::getCurrentSize()
{
    return _current_size;
}

void Galaxy::setName(std::string newName)
{
    _name = newName;
}

int Galaxy::getRadius(int index)
{
    if(index >= _current_size || index < 0)
    {
        return -1;
    }
    return _radii[index];
}

bool Galaxy::addRadius(int radius)
{
    if(_current_size >= _MAX_SIZE ||  radius <= 0)
    {
        return false;
    }

    _radii[_current_size] = radius;
    _current_size++;
    return true;
}

double Galaxy::getAverageRadius()
{
    if(_current_size <= 0)
    {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < _current_size; i++)
    {
        total += _radii[i];
    }

    return total / static_cast<double>(_current_size);
}

string findGalaxyWithLargestAverageRadius(Galaxy galaxies[], const int ARR_SIZE)
{
    string largestName = "";
    double largestAvgRadius = 0.0;
    double currentAvgRadius = 0.0;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        currentAvgRadius = galaxies[i].getAverageRadius();
        if(currentAvgRadius >= largestAvgRadius)
        {
            largestName = galaxies[i].getName();
            largestAvgRadius = currentAvgRadius;
        }
    }

    return largestName;
}

int main()
{
const int ARR_SIZE = 3;
int radii_1[3] = {10, 20, 30};
int radii_2[4] = {10, 20, 30, 40};
int radii_3[4] = {20, 40, 10, 10};
Galaxy galaxy_1 = Galaxy("Andromeda", radii_1, 3);
Galaxy galaxy_2 = Galaxy("MilkyWay", radii_2, 4);
Galaxy galaxy_3 = Galaxy("Orion", radii_3, 4);
Galaxy galaxies[ARR_SIZE] = {galaxy_1, galaxy_2, galaxy_3};

cout << findGalaxyWithLargestAverageRadius(galaxies, ARR_SIZE);
}