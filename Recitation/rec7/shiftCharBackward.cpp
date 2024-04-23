#include <iostream>
using namespace std;

void shiftCharBackward(char asciiArt[84][141], int rowTop, int rowBottom, int colLeft, int colRight);
char shiftChar(char letter, int shift_value);//Taken from my project

int main()
{
    char asciiArt[84][141] = 
    {
        {'F', 'D', 'F', 'E', 'G'},
        {'F', 'F', 'F', 'G', 'G'},
        {'J', 'H', 'J', 'I', 'K'},
        {'J', 'J', 'J', 'K', 'K'}
    };

    shiftCharBackward(asciiArt, 0, 3, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << asciiArt[i][j] << " ";
        }
        cout << endl;
    }
    
}


//This was my original code. I was assuming the shift was based on only Aa-Zz like the project so Henry changed it a little after class since we could not finish the final thing in class.
void shiftCharBackward(char asciiArt[84][141], int rowTop, int rowBottom, int colLeft, int colRight)
{
    for (int i = rowTop; i <= rowBottom; i++)
    {
        for (int j = colLeft; j <= colRight; j++)
        {
            if((i % 2 == 0) && (j % 2 == 0))
            {
                asciiArt[i][j] = shiftChar(asciiArt[i][j], -5);
            }
            else
            {
                asciiArt[i][j] = shiftChar(asciiArt[i][j], -3);
            }
        }
    }
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