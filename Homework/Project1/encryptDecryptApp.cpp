#include <iostream>
#include <string>
using namespace std;

//Function prototypes
char shiftChar(char letter, int shift_value);
char toUppercase(char letter);
int getDoubleKeyShiftValue(string key1, string key2);
bool stringCanConvertToInt(string str);
bool isValidCharacter(char letter);
bool isAatoZz(char letter);
string getLayer1MessageEncryption(string message, int method_choice, string key1, string key2);
string getLayer1MessageDecryption(string message, int method_choice, string key1, string key2);
string getLayer2MessageEncryption(string message, string key_phrase);
string getLayer2MessageDecryption(string message, string key_phrase);
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase);


int main()
{
    //Value declarations

    //This bool is mainly used for easier readability
    bool validInput = false;
    //The message to encrypt/decrypt
    string inputMessage;
    //The phrase to use for layer 2 / chain
    string inputPhrase;
    //The method to use for layer 1 / chain
    string inputMethodChoice;
    //The first key to use for layer 1 / chain
    string inputKey1;
    //The second key to use for layer 1 / chain
    string inputKey2;
    //The current menu choice
    string inputMenuChoice;
    //The encryption type to use
    string inputEncryptionChoice;


    //Application
    while (inputMenuChoice != "7")
    {
        cout << "Please input 1-7 followed by enter to navigate the menu:\n"
        << "1. Set Encryption Key 1\n"
        << "2. Set Encryption Key 2\n"
        << "3. Set Key Phrase\n"
        << "4. Select Encryption Method\n"
        << "5. Encrypt Message\n"
        << "6. Decrypt Message\n"
        << "7. Exit Program" << endl;

        getline(cin, inputMenuChoice);
        int currentChoice = stringCanConvertToInt(inputMenuChoice) ? stoi(inputMenuChoice) : 0;

        switch(currentChoice)
        {
            //First three options are practically identical with different prompts and variables
            //Option 1 (set first key)
            case 1:
            do
            {
                cout << "Enter First key:\n";   
                getline(cin, inputKey1);
                if(inputKey1.length() < 1)
                {
                    cout << "Invalid key" << endl;
                    validInput = false;
                }
                else
                {
                    cout << "Successfully set first encryption key to " << inputKey1 << endl;
                    validInput = true;
                }
            }while(!validInput);
            break;
            //Option 2 (set second key)
            case 2:
            do
            {
                cout << "Enter Second key:\n";   
                getline(cin, inputKey2);
                if(inputKey2.length() < 1)
                {
                    cout << "Invalid key" << endl;
                    validInput = false;
                }
                else
                {
                    cout << "Successfully set second encryption key to " << inputKey2 << endl;
                    validInput = true;
                }
            }while(!validInput);
            break;
            //Option 3 (set keyphrase)
            case 3:
            do
            {
                cout << "Enter keyphrase:\n";
                getline(cin, inputPhrase);
                bool containsSpecialCharacters = false;

                //Check for special characters
                for(int i = 0; i < inputPhrase.length(); i++)
                {
                    if(!isValidCharacter(inputPhrase[i]) && inputPhrase[i] != ' ')
                    {
                        containsSpecialCharacters = true;
                        break;
                    }
                }

                if(inputPhrase.length() < 1 || containsSpecialCharacters)
                {
                    cout << "Invalid keyphrase" << endl;
                    validInput = false;
                }
                else
                {
                    cout << "Successfully set encryption keyphrase to " << inputPhrase << endl;
                    validInput = true;
                }
            } while (!validInput);
            break;
            //Option 4 (set encryption method)
            case 4:
            do
            {
                cout << "Please input 1-3 to decide encryption technique.\n"
                << "1. Layer 1 Message Encryption\n"
                << "2. Layer 2 Message Encryption\n"
                << "3. Chain Encryption\n";
                getline(cin, inputEncryptionChoice);

                //Sets the integer if possible otherwise returns -1
                const int choiceAsInteger = stringCanConvertToInt(inputEncryptionChoice) ? stoi(inputEncryptionChoice) : -1;

                //Integer has to be valid value
                if(choiceAsInteger > 0 && choiceAsInteger < 4)
                {
                    cout << "Successfully set encryption type to " << inputEncryptionChoice << endl;
                    if(choiceAsInteger == 1 || choiceAsInteger == 3)
                    {
                        do
                        {
                            cout << "Please input 1-2 to decide Layer-1 encryption technique.\n"
                            << "1. Shift by 13\n"
                            << "2. Shift by mixed keys\n";

                            getline(cin, inputMethodChoice);

                            if(inputMethodChoice != "2" && inputMethodChoice != "1")
                            {
                                cout << "Invalid encryption choice" << endl;
                            }
                        }while(inputMethodChoice != "2" && inputMethodChoice != "1");
                    }
                    validInput = true;
                }
                else
                {
                    cout << "Invalid encryption choice" << endl;
                    validInput = false;
                }
            } while (!validInput);
            break;
            //Option 5 ()
            case 5:
                if(inputEncryptionChoice.length() > 0 && inputKey1.length() > 0 && inputKey2.length() > 0 && inputPhrase.length() > 0)
                {
                    cout << "Enter your message to encrypt:\n";
                    getline(cin, inputMessage);
                    switch (stoi(inputEncryptionChoice))
                    {
                    //Layer one encryption
                    case 1:
                        cout << getLayer1MessageEncryption(inputMessage, stoi(inputMethodChoice), inputKey1, inputKey2) << endl;
                    break;
                    case 2:
                        cout << getLayer2MessageEncryption(inputMessage, inputPhrase) << endl;
                    break;
                    case 3:
                        cout << getChainEncryption(inputMessage, stoi(inputMethodChoice), inputKey1, inputKey2, inputPhrase) << endl;
                    break;
                    //This case shouldn't even be possible
                    default:
                        cout << "Improper Encryption Choice!!" << endl;
                    break;
                    }
                }
                else
                {
                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                }
            break;
            //Option 6 (decrypt message)
            case 6:
                //Same as 5 just with decryption instead of encryption.
                if(inputEncryptionChoice.length() > 0 && inputKey1.length() > 0 && inputKey2.length() > 0 && inputPhrase.length() > 0)
                {
                    cout << "Enter your message to decrypt:\n";
                    getline(cin, inputMessage);
                    switch (stoi(inputEncryptionChoice))
                    {
                    //Layer one encryption
                    case 1:
                        cout << getLayer1MessageDecryption(inputMessage, stoi(inputMethodChoice), inputKey1, inputKey2) << endl;
                    break;
                    case 2:
                        cout << getLayer2MessageDecryption(inputMessage, inputPhrase) << endl;
                    break;
                    case 3:
                        cout << getChainDecryption(inputMessage, stoi(inputMethodChoice), inputKey1, inputKey2, inputPhrase) << endl;
                    break;
                    //This case shouldn't even be possible
                    default:
                        cout << "Improper Encryption Choice!!" << endl;
                    break;
                    }
                }
                else
                {
                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                }
            break;
            //Option 7 (exit)
            case 7:
                cout << "Goodbye." << endl;
            break;
            //Invalid Input
            default:
                cout << "Invalid input" << endl;
            break;
        }   
    }
    return 0;
}

/// @brief Encrypts based on choices 
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase)
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
    message = getLayer1MessageEncryption(message, method_choice, key1, key2);
    //Second encryption
    message = getLayer2MessageEncryption(message, key_phrase);

    return message;
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
    if(!isAatoZz(constructedKey[0]))
    {
        return message;
    }
    
    //Runs for every char in key_phrase
    for (int i = 1; i < key_phrase.length(); i++)
    {
        //If there is a space before the current letter(i) and that letter isn't also a space: it is a new word.
        if(key_phrase[i - 1] == ' ' && key_phrase[i] != ' ')
        {
            if(!isAatoZz(key_phrase[i]))
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
        if(isAatoZz(shiftedLetter) )
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
    if(!isAatoZz(constructedKey[0]))
    {
        return message;
    }
    
    //Runs for every char in key_phrase
    for (int i = 1; i < key_phrase.length(); i++)
    {
        //If there is a space before the current letter(i) and that letter isn't also a space: it is a new word.
        if(key_phrase[i - 1] == ' ' && key_phrase[i] != ' ')
        {
            if(!isAatoZz(key_phrase[i]))
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
        if(isAatoZz(shiftedLetter))
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

/// @brief Checks to see if the letter is Aa-Zz or 0-9
bool isValidCharacter(char letter)
{
    if(isupper(letter) || islower(letter) || isdigit(letter))
    {
        return true;
    }

    return false;
}

/// @brief Checks if the letter is Aa-Zz
bool isAatoZz(char letter)
{
    return (isupper(letter) || islower(letter));
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