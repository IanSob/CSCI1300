#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool validateInt (string input);

int main()
{
    string isIntString;

    cout << "Enter the integer :\n";
    getline(cin, isIntString);

    if(validateInt(isIntString))
    {
        cout << "The entered string is a valid integer!!" << endl;
    }
    else
    {
        cout << "The entered string is not a valid integer!!" << endl;
    }
}

bool validateInt (string input)
{
    int i = 0;

    if(input.length() == 0)
    {
        return false;
    }

    if(input[0] == '-' && input.length() > 1)
    {
        i = 1;
    }

    for(i; i < input.length(); i++)
    {
        if(input[i] < 48 || input[i] > 57)
        {
            return false;
        }
    }

    return true;
}