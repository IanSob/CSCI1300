#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool validateDouble(string input);
int split(string input_string, char separator, string arr[], const int ARR_SIZE);
struct coordinate
{
    double x;
    double y;
    double z;
};

int main()
{
    ifstream coordinatesFile("coordinates1.txt");
    string currentLine;
    coordinate coordinateAverages;
    int numberOfPoints = 0;

    //If we can not open the file
    if(!coordinatesFile.is_open())
    {
        cout << "Couldn't open file!!" << endl;
        coordinatesFile.close();
        return 0;
    }

    while (getline(coordinatesFile, currentLine))
    {
        numberOfPoints++;
        string splitArray[3];
        const int splitReturn = split(currentLine, ',', splitArray, 3);

        //Too many items on one line
        if(splitReturn == -1)
        {
            cout << "Too many items on line " << numberOfPoints << "!" << endl;
            coordinatesFile.close();
            return 0;
        }
        //Not enough items on line
        else if(splitReturn < 3)
        {
            cout << "Not enough items on line " << numberOfPoints << "!" << endl;
            coordinatesFile.close();
            return 0;
        }

        //If one can not convert to double
        if(!validateDouble(splitArray[0]) || !validateDouble(splitArray[1]) || !validateDouble(splitArray[2]))
        {
            cout << "Invalid value detected on line " << numberOfPoints << "!" << endl;
            coordinatesFile.close();
            return 0;
        }

        coordinateAverages.x += stod(splitArray[0]);
        coordinateAverages.y += stod(splitArray[1]);
        coordinateAverages.z += stod(splitArray[2]);
    }
    
    //Make sure we actually have an average
    if(numberOfPoints > 0)
    {
        //Setting the averages
        coordinateAverages.x /= numberOfPoints;
        coordinateAverages.y /= numberOfPoints;
        coordinateAverages.z /= numberOfPoints;

        //Printing the averages
        cout << "The center of mass is at: " 
        << coordinateAverages.x << ", " << coordinateAverages.y << ", " << coordinateAverages.z 
        << "!" << endl;
    }
    else
    {
        cout << "The number of lines is too small!" << endl;
    }

    coordinatesFile.close();
    return 0;
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