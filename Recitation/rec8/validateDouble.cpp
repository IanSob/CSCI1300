#include <iostream>
#include <string>
using namespace std;

bool validateDouble(string input);

int main()
{
    string doubleInput;

    cout << "Enter the double:\n";
    getline(cin, doubleInput);
    
    cout << "The entered string is"
    << (validateDouble(doubleInput) ? " " : " not ")
    << "a valid double!\n";

    return 0;
}

bool validateDouble(string input)
{
    int i = 0;
    int decimalPoints = 0;
    bool containsNumbers = false;

    if(input.length() == 0)
    {
        return false;
    }
    else if(input[0] == '-')
    {
        i = 1;
    }

    for (i; i < static_cast<int>(input.length()); i++)
    {
        if(input[i] == '.')
        {
            decimalPoints++;
        }
        else if(!isdigit(input[i]))
        {
            return false;
        }
        else
        {
            containsNumbers = true;
        }
    }
    
    if(!containsNumbers || decimalPoints > 1)
    {
        return false;
    }

    return true;
}