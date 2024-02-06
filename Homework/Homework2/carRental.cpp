#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

//Looked at structures in the book.
struct Car
{
    float basePrice;
    float pricePerDay;

    //Constructor
    Car(float setBasePrice, float setPricePerDay)
    {
        basePrice = setBasePrice;
        pricePerDay = setPricePerDay;
    }
};

int main()
{
    //Defining the map of cars
    const map <char, Car> carTypes = 
    {
        {'A', Car(75, 10)}, 
        {'B', Car(100, 20)},
        {'C', Car(150, 30)},
        {'D', Car(200, 40)}
    };

    int daysToRent = 0;
    char selectedCar = 'X';
    float slctdCarBasePrice = 0;
    float slctdCarPricePerDay = 0;

    //Prompt and get car
    cout << "Which car type ( A, B, C, or D ) would you like to rent?\n";
    cin >> selectedCar;

    //Prompt and get days to rent
    cout << "How many days would you like to rent this car?\n";
    cin >> daysToRent;

    slctdCarBasePrice = carTypes.find(selectedCar)->second.basePrice;
    slctdCarPricePerDay = carTypes.find(selectedCar)->second.pricePerDay;

    //Invalid inputs
    if(daysToRent < 1 || carTypes.find(selectedCar) == carTypes.end())
    {
        cout << "Please enter valid input." << endl;
    }
    else
    {
        
        cout << fixed << setprecision(2) << "Your bill total is $"
        << 1.21 * (slctdCarBasePrice + daysToRent * slctdCarPricePerDay) << endl;
    }

    return 0;
}