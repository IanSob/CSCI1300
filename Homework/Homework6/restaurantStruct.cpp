// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 4

#include <iostream>
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

double getOverallRating(Restaurant restaurant);

int main()
{
    Restaurant r;

    r.name = "McDonalds";
    r.food_quality = 0;
    r.cleanliness = 0;
    r.wait_time = 5;

    r.overall = getOverallRating(r);

    if (r.overall == -1)
    {
        cout << "Invalid rating(s) entered." << endl;
    }
    else
    {
        cout << "Restaurant: " << r.name << " Overall: " << r.overall << endl;
    }

    return 0;
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