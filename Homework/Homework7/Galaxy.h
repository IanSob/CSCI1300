// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 1-3

#include <iostream>

class Galaxy
{
private:
    //Name of galaxy
    std::string _name;

    //Max size of _radii array
    const static int _MAX_SIZE = 10;

    //Radius of planets in galaxy
    int _radii[_MAX_SIZE];

    //Current size of the _radii array
    int _current_size;

public:
    //Default constructor (everything 0 or empty)
    Galaxy();

    //Galaxy constructor with the name set as the galaxyName parameter
    Galaxy(std::string galaxyName);

    ///@brief Creates the galaxy with parameters
    ///@param string name: The name of the galaxy
    ///@param int[] radii: The radius of different planets
    ///@param int arr_size: The size of the array
    Galaxy(std::string name, int radii[], int arr_size);

    //The name of the galaxy
    std::string getName();

    //The current size of the galaxy
    int getCurrentSize();

    //Sets the galaxy name to newName
    void setName(std::string newName);

    //Gets the radius at the index or -1 for error
    int getRadius(int index);

    //Tries to add new radius to the planets. False if failed.
    bool addRadius(int index);

    //Gets average radius of the planets
    double getAverageRadius();
};

//Finds the name of the galaxy from the array with the largest average radius
std::string findGalaxyWithLargestAverageRadius(Galaxy galaxies[], const int ARR_SIZE);