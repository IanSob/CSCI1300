#include <iostream>
#include <string>
using namespace std;

//Function prototypes
char shiftChar(char letter, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);
bool stringCanConvertToInt(string str);
string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2);


//Basically the exact same code as getLayer1MessageEncryption just using decryption code instead.
int main()
{
    //Variable definitions
    string key1Input;
    string key2Input;
    string messageToEncrypt;
    string methodChoice;
    int methodChoiceInt;


    //Message
    cout << "Enter the message to decrypt :\n";
    getline(cin, messageToEncrypt);

    //Methos
    cout << "Enter the method choice (1 or 2) :\n";
    getline(cin, methodChoice);

    methodChoiceInt = stringCanConvertToInt(methodChoice) ? stoi(methodChoice) : 0;

    //First key
    cout << "Enter The first key :\n";
    getline(cin, key1Input);

    //Second key
    cout << "Enter The second key:\n";
    getline(cin, key2Input);

    //Output
    cout << "The decrypted message : "
    << getLayer1MessageDecryption(messageToEncrypt, methodChoiceInt, key1Input, key2Input) << endl;
}

/// @brief Decrypts messages made by getLayer1MessageEncryption function.
string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2)
{
    //All the code is the exact same except the shift values are reversed.
    if(message.length() == 0)
    {
        return message;
    }

    string finalEncryption;

    //Which choice
    //Shift by 13
    if(method_choice == 1)
    {
        //Encrypts every character seperately
        for(int i = 0; i < message.length(); i++)
        {
            //Makes encrypted message (shifted 13)
            finalEncryption.push_back(shiftChar(message[i], -13));
        }
        return finalEncryption;
    }
    //Shift by key
    else if(method_choice == 2)
    {
        //If the keys are empty
        if(key1.length() == 0 || key2.length() == 0)
        {
            return message;
        }
        else
        {
            int shiftAmountForKeys = -getDoubleKeyShiftValue(key1, key2);
            for(int i = 0; i < message.length(); i++)
            {
                finalEncryption.push_back(shiftChar(message[i], shiftAmountForKeys));
            }
            return finalEncryption;
        }
    }

    //Invalid choice
    return message;
}

///@brief Shifts the char by specified amount.
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

/// @brief Checks if the string can be converted to an integer.
bool stringCanConvertToInt(string str)
{
    int i = 0;

    if(str[0] == '-' && str.length() > 1)
    {
        i = 1;
    }
    else if(str.length() == 0)
    {
        return false;
    }

    for(i; i < str.length(); i++)
    {
        //If the string is invalid
        if(str[i] < 47 || str[i] > 57)
        {
            return false;
        }
    }

    return true;
}