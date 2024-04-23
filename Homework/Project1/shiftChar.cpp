#include <iostream>
#include <string>
using namespace std;

char shiftChar(char letter, int shift_value);

int main()
{
    char charToEncrypt;
    int shiftInput;

    //Letter inpit
    cout << "Enter a letter to shift:\n";
    cin >> charToEncrypt;

    //Shift input
    cout << "Enter an integer to shift the letter by:\n";
    cin >> shiftInput;

    //Result
    cout << "The letter " << charToEncrypt << " was encrypted to " << shiftChar(charToEncrypt, shiftInput) << "\n"; 
}

/*
*@brief Shifts the char by specified amount.
*@param letter The original letter to shift.
*@param shift_value The value to shift the letter by.
*@return char The shifted letter.
*/
char shiftChar(char letter, int shift_value)
{
    bool isCapital = (letter > 64 && letter < 91);

    //Uses ascii to check if the letter isnt  Aa-Zz.
    if(!(isCapital || (letter > 96 && letter < 123)))
    {
        return letter;
    }
    
    //Constrains the value between -25 and 25.
    shift_value = shift_value % 26;
    shift_value = letter + shift_value;

    if(isCapital)
    {
        //We only have to do this once since the shift_value is already between -25 and 25
        //If our value is above specified range: -26 to return to A
        if(shift_value > 90)
        {
            shift_value -= 26;
        }
        //If the value is below specified range: +26 to return to Z
        else if(shift_value < 65)
        {
            shift_value += 26;
        }

        return shift_value;
    }
    else
    {
        //Same as other one just different values.
        if(shift_value > 122)
        {
            shift_value -= 26;
        }
        else if(shift_value < 97)
        {
            shift_value += 26;
        }

        return shift_value;
    }

    return shift_value;
}