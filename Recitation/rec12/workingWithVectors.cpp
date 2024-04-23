#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>
using namespace std;

vector<float> gatherFloats(int numberOfFloats);
vector<float> removeMembersLessThan(vector<float> vectorToRemove, float maxValue);
float findFirstLastAvg(vector<float> vectorToAvg);
bool stringCanConvert(string strToCheck);

int main()
{
    //Assume user inputs: {30.2, 20, 5.5, 3.4, 80, 109, 7, 25, -1, 11.05}
    vector<float> testingVect = gatherFloats(10);
    float average = findFirstLastAvg(testingVect);
    vector<float> returnVect = {30.2, 80, 109, 25};
    assert(average == 20.625);
    assert(returnVect == removeMembersLessThan(testingVect, average));

    //Assume user inputs: {-1, 3.2, 80, 6, 7.5, 8.3, 90, 78.35, 0, 100.1}
    testingVect = gatherFloats(10);
    average = findFirstLastAvg(testingVect);
    returnVect = {80.f, 90.f, 78.35f, 100.1f};
    //I hate floats
    assert(average == (100.1f - 1.f) / 2.f);
    assert(returnVect == removeMembersLessThan(testingVect, average));

    cout << "Asserts passed!\n";
}

//Returns a float with all members in vectorToRemove less than maxValue removed
vector<float> removeMembersLessThan(vector<float> vectorToRemove, float maxValue)
{
    vector<float> returnVect;
    for (int i = 0; i < static_cast<int>(vectorToRemove.size()); i++)
    {
        if(vectorToRemove.at(i) >= maxValue)
        {
            returnVect.push_back(vectorToRemove.at(i));
        }
    }
    
    return returnVect;
}

//Uses user input to make an array of floats
vector<float> gatherFloats(int numberOfFloats)
{
    vector<float> vectorFloats;
    for (int i = 1; i <= numberOfFloats; i++)
    {
        //Prompt user
        cout << "Please enter a value for float number " << i << ":\n";

        //Get user input
        string userInput;
        getline(cin, userInput);

        //If an invalid value has ben entered
        if(!stringCanConvert(userInput))
        {
            cout << "Please enter a valid number!!\n";
            i--;
            continue;
        } 
        
        vectorFloats.push_back(stof(userInput));
    }

    return vectorFloats;
}

//Returns the average of the first and last floats in the vector
//Returns 0 if vector is too small
float findFirstLastAvg(vector<float> vectorToAvg)
{
    if(vectorToAvg.size() > 1)
    {
        return (vectorToAvg.at(0) + vectorToAvg.at(vectorToAvg.size() - 1)) / 2.f;
    }

    return 0;
}

//True if the string can be converted to a float using stof()
bool stringCanConvert(string strToCheck)
{
    bool containsPeriod = false;
    bool containsNumber = false;
    int i = 0;

    //Skip the first negative
    if(strToCheck[i] == '-')
    {
        i++;
    }

    for (; i < static_cast<int>(strToCheck.length()); i++)
    {
        if(strToCheck[i] == '.')
        {
            if(containsPeriod)
            {
                return false;
            }
            containsPeriod = true;
        }
        else if(!isdigit(strToCheck[i]))
        {
            return false;
        }
        else
        {
            containsNumber = true;
        }
    }

    if(containsNumber)
    {
        return true;
    }

    return false;
}