#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void chemicalElements(string elements[], const int ELEMENTS_SIZE);
void squareRoots(double numbers[], const int NUMBERS_SIZE);
void fillNumbers(int divisible_numbers[], const int DIVISIBLE_NUMBERS_SIZE);
void fillLetters(char letters[], const int LETTERS_SIZE);

int main()
{
    char theArrayTesting[104];

    fillLetters(theArrayTesting, 104);

    for (int i = 0; i < 104; i++)
    {
        cout << theArrayTesting[i] << "\n";
    }
    
}


//Kinda unsure what the intended behavior is but this will loop through the elements for the size of the array.
void chemicalElements(string elements[], const int ELEMENTS_SIZE)
{
    const string temporaryElementArray[10] =
    {
        "Hydrogen",
        "Helium",
        "Lithium",
        "Beryllium",
        "Boron",
        "Carbon",
        "Nitrogen",
        "Oxygen",
        "Fluorine",
        "Neon"
    };

    //Write the repeating list of elements.
    for (int i = 0; i < ELEMENTS_SIZE; i++)
    {
        elements[i] = temporaryElementArray[i % 10];
    }
}

//Same as chemicalElements function just different types and items for the array.
void squareRoots(double numbers[], const int NUMBERS_SIZE)
{
    const double sqrt1to20[10] =
    {
        1.0,
        sqrt(2.0),
        sqrt(3.0),
        2.0,
        sqrt(5.0),
        sqrt(6.0),
        sqrt(7.0),
        sqrt(8.0),
        3.0,
        sqrt(10.0)
    };

    for (int i = 0; i < NUMBERS_SIZE; i++)
    {
        numbers[i] = sqrt1to20[i % 10];
    }  
}

//Again practically the same as the other two. I'm just defining the correct array because there are so few values and it isn't dynamic.
void fillNumbers(int divisible_numbers[], const int DIVISIBLE_NUMBERS_SIZE)
{
    //Again, I'm doing it this way because there is no reason to be running logic on a non dynamic function that only stores these exact 7 values.
    const int divsBy7From50To100[7] =
    {
        56,
        63,
        70,
        77,
        84,
        91,
        98
    };

    for (int i = 0; i < DIVISIBLE_NUMBERS_SIZE; i++)
    {
        divisible_numbers[i] = divsBy7From50To100[i % 7];
    }
}

//Different from the other ones because defining the values is less practical now.
void fillLetters(char letters[], const int LETTERS_SIZE)
{
    for (int i = 0; i < LETTERS_SIZE; i++)
    {
        //The actual value to find for the current position wrapped around
        int wrappedValue = i % 52;
        
        //If it is divisible by two it is a capital letter
        if(wrappedValue % 2 == 0)
        {
            //Make the wrapped value 0-25 then add to it to find the proper ASCII value
            letters[i] = (25 - wrappedValue / 2) + 65;
        }
        else
        {
            letters[i] = (25 - (wrappedValue - 1) / 2) + 97;
        }
    }  
}
