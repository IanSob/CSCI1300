#include <iostream>
using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE);

void printArray(string arr[], const int NUM_ELEMENTS)
{
    for (int i=0; i < NUM_ELEMENTS; i++)
    {
        cout << "arr["<< i << "]:" << arr[i] << endl;
    }   
}

int main()
{
    string input_string = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    const int ARR_SIZE = 5;
    string arr[ARR_SIZE];
    // num_splits is the value returned by split
    int num_splits = split(input_string, separator, arr, ARR_SIZE);
    cout << "Function returned value: " << num_splits << endl;
    if(num_splits != -1)
    {
        printArray(arr, num_splits);   
    }
    else
    {
        printArray(arr, ARR_SIZE);
    }
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