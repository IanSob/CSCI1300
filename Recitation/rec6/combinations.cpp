#include <iostream>
#include <string>
using namespace std;

string removeSpaces(string strToUse);

int main()
{
    //Inputs but as strings
    string inputFirstArrayAsStr;
    string inputSecondArrayAsStr;
    //Bool to check if the strings are valid
    bool validArrays = false;
    //These are technically completely unneccessary if we just used a string, but I'm trying to stay accurate to the assignment
    char firstArray[4];
    char secondArray[3];

    while(!validArrays)
    {
        //First array input
        cout << "Please enter 4 characters for the first array:\n";
        getline(cin, inputFirstArrayAsStr);

        //Second array input
        cout << "Please enter 3 characters for the second array:\n";
        getline(cin, inputSecondArrayAsStr);

        //Removing the spaces from the strings
        inputFirstArrayAsStr = removeSpaces(inputFirstArrayAsStr);
        inputSecondArrayAsStr = removeSpaces(inputSecondArrayAsStr);

        //If there are too many or little values after removing spaces
        if (inputFirstArrayAsStr.length() != 4 || inputSecondArrayAsStr.length() != 3)
        {
            cout << "Invalid Input." << endl;
            validArrays = false;
        }
        else
        {
            validArrays = true;

            //Making the strings into arrays
            for (int i = 0; i < 4; i++)
            {
                firstArray[i] = inputFirstArrayAsStr[i];
            }
            for (int i = 0; i < 3; i++)
            {
                secondArray[i] = inputSecondArrayAsStr[i];
            } 
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << firstArray[i] << secondArray[j] << " ";
        }
        cout << endl;
    }
    
}

/// @brief Removes spaces from a string
/// @param strToUse The string to remove spaces from
/// @return The string without spaces
string removeSpaces(string strToUse)
{
    string stringWithoutSpaces;
    for (int i = 0; i < strToUse.length(); i++)
    {
        if (strToUse[i] != ' ')
        {
            stringWithoutSpaces.push_back(strToUse[i]);
        }
    }
    return stringWithoutSpaces;
}