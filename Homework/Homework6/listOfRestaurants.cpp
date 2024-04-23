// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5

#include <iostream>
#include <fstream>
using namespace std;

struct Restaurant
{
    //Name of restaurant
    string name;

    //These two (0-10)
    //Food quality of restaurant
    int food_quality;

    //Cleanliness of restaurant
    int cleanliness;

    //The wait time rating (0-5)
    int wait_time;

    //Overall rating
    double overall;
};

int readRestaurantDetails(string filename, Restaurant restaurants[], const int MAX_RESTAURANTS);
int split(string input_string, char separator, string arr[], const int ARR_SIZE);
double getOverallRating(Restaurant restaurant);
int getBest(Restaurant restaurants[], int arr_size, string metric);

int main()
{
    const int MAX_RESTAURANTS = 30;

    string restaurants_filename = "testingFile.txt";
    Restaurant restaurants[MAX_RESTAURANTS];

    int arr_size = readRestaurantDetails(restaurants_filename, restaurants, MAX_RESTAURANTS);

    // Checking if the file was opened correctly
    if (arr_size == -1)
    {
        cout << "Failed to open file." << endl;
    }
    else if (arr_size == 0)
    {
        cout << "Empty file." << endl;
    }
    else
    {
        int idx = getBest(restaurants, arr_size, "x");

        if (idx == -1)
        {
            cout << "Invalid metric." << endl;
        }
        else
        {
            cout << "Restaurant: " << restaurants[idx].name << " ";
            cout << "Ratings: ";
            cout << restaurants[idx].food_quality << " ";
            cout << restaurants[idx].cleanliness << " ";
            cout << restaurants[idx].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[idx].overall << " ";
            cout << endl;
        }
    }

    return 0;
}

int readRestaurantDetails(string filename, Restaurant restaurants[], const int MAX_RESTAURANTS)
{
    ifstream fileToRead(filename);

    if(!fileToRead.is_open())
    {
        return -1;
    }

    int i = 0;
    //Position of the restaurant array
    int resPos = 0;
    for (; i < MAX_RESTAURANTS; i++)
    {
        string currentLine;
        if(getline(fileToRead, currentLine))
        {
            string splitArray[4];

            if(split(currentLine, '~', splitArray, 4) == 4)
            {
                restaurants[resPos].name = splitArray[0];
                restaurants[resPos].food_quality = stoi(splitArray[1]);
                restaurants[resPos].cleanliness = stoi(splitArray[2]);
                restaurants[resPos].wait_time = stoi(splitArray[3]);
                restaurants[resPos].overall = getOverallRating(restaurants[resPos]);
                resPos++;
            }
        }
        else
        {
            return resPos;
        }
    }
    
    return resPos;
}

double getOverallRating(Restaurant restaurant)
{
    //Bounds checking
    if((restaurant.food_quality < 0 || restaurant.food_quality > 10) || (restaurant.cleanliness < 0 || restaurant.cleanliness > 10) || (restaurant.wait_time < 0 || restaurant.wait_time > 5))
    {
        return -1;
    }

    return 6.3 * restaurant.food_quality + 4.3 * restaurant.cleanliness + 3.4 * (5 - restaurant.wait_time);
}

int getBest(Restaurant restaurants[], int arr_size, string metric)
{
    int bestIndex = 0;

    //Each one is the exact same with different variables to access.
    if(metric == "Food Quality")
    {
        for (int i = 1; i < arr_size; i++)
        {
            if(restaurants[bestIndex].food_quality < restaurants[i].food_quality)
            {
                bestIndex = i;
            }
        }

        return bestIndex;     
    }
    else if(metric == "Cleanliness")
    {
        for (int i = 1; i < arr_size; i++)
        {
            if(restaurants[bestIndex].cleanliness < restaurants[i].cleanliness)
            {
                bestIndex = i;
            }
        }

        return bestIndex; 
    }
    else if(metric == "Wait Time")
    {
        for (int i = 1; i < arr_size; i++)
        {
            if(restaurants[bestIndex].wait_time < restaurants[i].wait_time)
            {
                bestIndex = i;
            }
        }

        return bestIndex; 
    }
    else if(metric == "Overall")
    {
        for (int i = 1; i < arr_size; i++)
        {
            if(restaurants[bestIndex].overall < restaurants[i].overall)
            {
                bestIndex = i;
            }
        }

        return bestIndex; 
    }

    return -1;
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