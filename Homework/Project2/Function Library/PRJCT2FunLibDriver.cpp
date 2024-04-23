//Program compiles with 
//g++ -Werror -Wall -Wpedantic -std=c++17 PRJCT2FunLibDriver.cpp PRJCT2FunLib.cpp
//when in directory "Function Library"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "PRJCT2FunLib.h"

using namespace std;

int main()
{
    string stringToSplit = {"This, is the, string, to split"};

    vector<string> myVect = project2Library::split(stringToSplit, ',');
    assert(myVect.size() == 4);
    assert(myVect.at(0) == "This");
    assert(myVect.at(1) == " is the");
    assert(myVect.at(2) == " string");
    assert(myVect.at(3) == " to split");

    cout << "Asserts passed!\n";
}