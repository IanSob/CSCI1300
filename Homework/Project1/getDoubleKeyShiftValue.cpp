#include <iostream>
#include <string>
using namespace std;

int getDoubleKeyShiftValue(string key1, string key2);

int main()
{
    string key1Input;
    string key2Input;

    //First key
    cout << "Enter first key :\n";
    getline(cin, key1Input);

    //Second key
    cout << "Enter second key:\n";
    getline(cin, key2Input);

    //Output
    cout << "The shift distance : "
    << getDoubleKeyShiftValue(key1Input, key2Input) << endl;
}

/// @brief Returns shift value based on keys.
int getDoubleKeyShiftValue(string key1, string key2)
{
    //If the strings are empty
    if(key1.length() == 0 || key2.length() == 0)
    {
        return 0;
    }

    int shiftAmount = 0;


    for(int i = 0; i < key1.length(); i++)
    {
        for(int j = 0; j < key2.length(); j++)
        {
            if(key1[i] == key2[j])
            {
                shiftAmount++;
            }
        }
    }

    return shiftAmount % 26;
}