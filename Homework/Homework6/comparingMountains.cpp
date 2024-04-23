// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 6 (Extra Credit)

#include <iostream>
#include <fstream>
using namespace std;

struct Mountain
{
    string name;
    string continent;
    int trail_length;
    int elevation;
    int difficulty;
};

int readMountainDetails(string filename, Mountain mountains[], const int MAX_MOUNTAINS);
int split(string input_string, char separator, string arr[], const int ARR_SIZE);
int getMountains(Mountain mountains[], Mountain selected_mountains[], int choice, string value, int mountain_size);

int main()
{
    const int MAX_MOUNTAINS = 30;

    string mountains_filename = "testingFile.txt";

    Mountain mountains[MAX_MOUNTAINS];
    Mountain selected_mountains[MAX_MOUNTAINS];

    int mountain_size = readMountainDetails(mountains_filename, mountains, MAX_MOUNTAINS);

    // Checking if the file was opened correctly
    if (mountain_size == -1)
    {
        cout << "Failed to open file." << endl;
        return 0;
    }

    string str_choice;
    cout << "Select option:" << endl;
    cout << "1. Obtain mountains with a certain difficulty rating." << endl;
    cout << "2. Obtain mountains taller than a certain elevation." << endl;
    cout << "3. Obtain mountains with a trail longer than a certain trail length." << endl;
    cout << "4. Obtain mountains in a certain continent." << endl;
    getline(cin, str_choice);

    int choice = stoi(str_choice);

    string value;
    cout << "Enter a value based on the choice:" << endl;
    getline(cin, value);

    int selected_size = getMountains(mountains, selected_mountains, choice, value, mountain_size);

    if (selected_size == -1)
    {
        cout << "Invalid choice." << endl;
    }
    else
    {
        for (int i = 0; i < selected_size; i++)
        {
            cout << "Name: " << selected_mountains[i].name << ", ";
            cout << "Continent: " << selected_mountains[i].continent  << ", ";
            cout << "Trail length: " << selected_mountains[i].trail_length << ", ";
            cout << "Elevation: " << selected_mountains[i].elevation  << ", ";
            cout << "Difficulty: " << selected_mountains[i].difficulty;
            cout << endl;
        }
    }

    return 0;
}

int getMountains(Mountain mountains[], Mountain selected_mountains[], int choice, string value, int mountain_size)
{
    int amountOfMountains = 0;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < mountain_size; i++)
        {
            if(mountains[i].difficulty == stoi(value))
            {
                selected_mountains[amountOfMountains] = mountains[i];
                amountOfMountains++;
                cout << "Hi\n";
            }
        }
        
        return amountOfMountains;
    break;

    case 2:
        for (int i = 0; i < mountain_size; i++)
        {
            if(mountains[i].elevation > stoi(value))
            {
                selected_mountains[amountOfMountains] = mountains[i];
                amountOfMountains++;
            }
        }

        return amountOfMountains;
    break;

    case 3:
        for (int i = 0; i < mountain_size; i++)
        {
            if(mountains[i].trail_length > stoi(value))
            {
                selected_mountains[amountOfMountains] = mountains[i];
                amountOfMountains++;
            }
        }
        
        return amountOfMountains;
    break;

    case 4:
        for (int i = 0; i < mountain_size; i++)
        {
            if(mountains[i].continent == value)
            {
                selected_mountains[amountOfMountains] = mountains[i];
                amountOfMountains++;
            }
        }

        return amountOfMountains;
    break;
    }

    return -1;
}

int readMountainDetails(string filename, Mountain mountains[], const int MAX_MOUNTAINS)
{
    ifstream inputStream(filename);
    int currentMountainsPop = 0;

    if(!inputStream.is_open())
    {
        return -1;
    }

    string currentLine;
    while (getline(inputStream, currentLine))
    {
        string splitData[5];

        if(split(currentLine, ',', splitData, 5) == 5 && currentMountainsPop <= MAX_MOUNTAINS)
        {
            mountains[currentMountainsPop].name = splitData[0];
            mountains[currentMountainsPop].continent = splitData[1];
            mountains[currentMountainsPop].trail_length = stoi(splitData[2]);
            mountains[currentMountainsPop].elevation = stoi(splitData[3]);
            mountains[currentMountainsPop].difficulty = stoi(splitData[4]);
            currentMountainsPop++;
        }
    }
    
    return currentMountainsPop;
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int numberOfSplits = 0;

    if(input_string.length() == 0)
    {
        return 0;
    }

    for (int i = 0; i < static_cast<int>(input_string.length()); i++)
    {
        //If we are on a separator
        if(input_string[i] == separator)
        {
            numberOfSplits++;
            //If the number of splits is becoming too high, we return -1 and no longer write to the array.
            if(numberOfSplits >= ARR_SIZE)
            {
                return -1;
            }
        }
        else
        {
            arr[numberOfSplits].push_back(input_string[i]);
        }
    }
    
    return numberOfSplits + 1;
}