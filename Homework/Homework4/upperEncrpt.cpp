// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 3
#include <iostream>
using namespace std;

char encryptUpper(char letter, int shift_value)
{
    if(letter < 65 || letter > 90)
    {
        return letter;
    }

    char encryptedLetter = letter + shift_value;

    if(encryptedLetter > 126 || encryptedLetter < 33)
    {
        return letter;
    }

    return encryptedLetter;
}

int main()
{
    char letterInput;
    int encryptionValue;

    cout << "Enter an uppercase letter to encrypt:\n";
    cin >> letterInput;
    cout << "Enter the encryption value:\n";
    cin >> encryptionValue;
    cout << "Letter " << letterInput << " was encrypted to " << encryptUpper(letterInput, encryptionValue) << endl;
}