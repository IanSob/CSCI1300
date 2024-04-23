#include <iostream>
#include <string>
using namespace std;

//Function prototypes
char shiftChar(char letter, int shift_value);
char toUppercase(char letter);
int getDoubleKeyShiftValue(string key1, string key2);
bool stringCanConvertToInt(string str);
bool isValidCharacter(char letter);
string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2);
string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2);
string getLayer2MessageEncryption(string message, string key_phrase);
string getLayer2MessageDecryption(string message, string key_phrase);
string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase);


int main()
{
    string inputMessage;
    string inputPhrase;
    string inputMethodChoice;
    string inputKey1;
    string inputKey2;

    //Message
    cout << "Enter message to decrypt :\n";
    getline(cin, inputMessage);

    //Method
    cout << "Enter the method choice (1 or 2) :\n";
    getline(cin, inputMethodChoice);

    //First key
    cout << "Enter The first key :\n";
    getline(cin, inputKey1);

    //Second key
    cout << "Enter The second key :\n";
    getline(cin, inputKey2);


    //Phrase
    cout << "Enter the key phrase :\n";
    getline(cin, inputPhrase);

    //Makes the vlaue 0 if it can not convert withut throwing error.
    int methodAsInteger = (stringCanConvertToInt(inputMethodChoice)) ? stoi(inputMethodChoice) : 0; 

    //Output
    cout << "The decrypted message : " 
    << getChainDecryption(inputMessage, methodAsInteger, inputKey1, inputKey2, inputPhrase) << endl;

    return 0;
}

/// @brief Encrypts based on choices 
string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase)
{
    //If message is empty, method choice is wrong, or phrase is empty
    if(message.length() < 1 || (method_choice != 2 && method_choice != 1) || key_phrase.length() < 1)
    {
        return message;
    }
    //If the choice = 2 and the keys are empty
    else if(method_choice == 2 && (key1.length() < 1 || key2.length() < 1))
    {
        return message;
    }

    bool allSpaces = true;
    //If the phrase has invalid character
    for(int i = 0; i < key_phrase.length(); i++)
    {
        if(!isValidCharacter(key_phrase[i]) && key_phrase[i] != ' ')
        {
            return message;
        }
    }

    //First encryption
    message = getLayer2MessageDecryption(message, key_phrase);
    //Second encryption
    message = getLayer1MessageDecryption(message, method_choice, key1, key2);

    return message;
}

/// @brief Encrypts a string(message) based on method and keys. 
string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2)
{
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
            finalEncryption.push_back(shiftChar(message[i], 13));
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
            int shiftAmountForKeys = getDoubleKeyShiftValue(key1, key2);
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

/// @brief Encrypts the message using the key_phrase
string getLayer2MessageEncryption(string message, string key_phrase)
{
    //Make sure the strings aren't empty
    if(message.length() == 0 || key_phrase.length() == 0)
    {
        return message;
    }

    //Remove any spaces from the beginning
    while (key_phrase[0] == ' ')
    {
        //Reconstructs the string without the space
        key_phrase = key_phrase.substr(1);
    }

    //Initializing a key with the first value the same as key_phrase[0]
    string constructedKey;
    constructedKey.push_back(toUppercase(key_phrase[0]));

    //If the first character is invalid
    if(!isValidCharacter(constructedKey[0]))
    {
        return message;
    }
    
    //Runs for every char in key_phrase
    for (int i = 1; i < key_phrase.length(); i++)
    {
        //If there is a space before the current letter(i) and that letter isn't also a space: it is a new word.
        if(key_phrase[i - 1] == ' ' && key_phrase[i] != ' ')
        {
            if(!isValidCharacter(key_phrase[i]))
            {
                return message;
            }
            //Adds first letter of new word to the key
            constructedKey.push_back(toUppercase(key_phrase[i]));
        }
    }

    string encryptedMessage;

    //Runs for every char in message.
    for(int i = 0, j = 0; i < message.length(); i++)//Small note but found out you can declare multiple ints at head of loop!
    {
        const char shiftedLetter = shiftChar(message[i], constructedKey[j] - 65);

        //Only update j (position in key) only if we use it.
        if(isValidCharacter(shiftedLetter))
        {
            j = (j + 1) % constructedKey.length();
        }

        encryptedMessage.push_back(shiftedLetter);
    }

    return encryptedMessage;
}

/// @brief Decrypts the message using the key_phrase
string getLayer2MessageDecryption(string message, string key_phrase)
{
    //Make sure the strings aren't empty
    if(message.length() == 0 || key_phrase.length() == 0)
    {
        return message;
    }

    //Remove any spaces from the beginning
    while (key_phrase[0] == ' ')
    {
        //Reconstructs the string without the space
        key_phrase = key_phrase.substr(1);
    }

    //Initializing a key with the first value the same as key_phrase[0]
    string constructedKey;
    constructedKey.push_back(toUppercase(key_phrase[0]));

    //If the first character is invalid
    if(!isValidCharacter(constructedKey[0]))
    {
        return message;
    }
    
    //Runs for every char in key_phrase
    for (int i = 1; i < key_phrase.length(); i++)
    {
        //If there is a space before the current letter(i) and that letter isn't also a space: it is a new word.
        if(key_phrase[i - 1] == ' ' && key_phrase[i] != ' ')
        {
            if(!isValidCharacter(key_phrase[i]))
            {
                return message;
            }
            //Adds first letter of new word to the key
            constructedKey.push_back(toUppercase(key_phrase[i]));
        }
    }

    string encryptedMessage;

    //Runs for every char in message.
    for(int i = 0, j = 0; i < message.length(); i++)//Small note but found out you can declare multiple ints at head of loop!
    {
        //Negative so we shift back to original
        const char shiftedLetter = shiftChar(message[i], -(constructedKey[j] - 65));

        //Only update j (position in key) only if we use it.
        if(isValidCharacter(shiftedLetter))
        {
            j = (j + 1) % constructedKey.length();
        }

        encryptedMessage.push_back(shiftedLetter);
    }

    return encryptedMessage;
}

/// @brief Takes a letter and converts it to uppercase.
/// @param letter The letter we want to make uppercase.
/// @return The produced uppercase (returns letter if already uppercase or invalid input)
char toUppercase(char letter)
{
    if(letter > 96 && letter < 123)
    {
        //Shifst down 32 on the ASCII (making it uppercase)
        return letter - 32;
    }

    return letter;
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

/// @brief Checks to see if the letter is Aa-Zz
bool isValidCharacter(char letter)
{
    if(((letter > 64 && letter < 91) || (letter > 96 && letter < 123)) || (letter > 47 && letter < 58))
    {
        return true;
    }

    return false;
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