#ifndef PROJECT2FUNLIB
#define PROJECT2FUNLIB

#include <iostream>
#include <vector>
#include <string>

//Contains a library of functions for project 2
class project2Library
{
private:

public:
    //Splits a string an puts to results into the returned vector of string. Seperator is what seperates to elements
    static std::vector<std::string> split(std::string stringToSplit, char seperator);
};

#endif