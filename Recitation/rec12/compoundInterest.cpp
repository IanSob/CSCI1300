#include <iostream>
#include <cassert>
using namespace std;

double exponentiate(double num, int exponent);

int main()
{
    assert(exponentiate(3, 5) == 243);
    assert(exponentiate(5, 0) == 1);
    assert(exponentiate(2, -1) == 1.0 / 2);
    assert(exponentiate(0, 0) == 1);
    assert(exponentiate(0, 3) == 0);
    assert(exponentiate(-2, 2) == 4);
    assert(exponentiate(-5, 3) == -125);
    //cout << "Asserts passed\n";

    char exit = 'A';
    while (exit != 'E')
    {
        double principleAmount = -1;
        while (principleAmount < 0)
        {
            cout << "Enter the principal amount (P):\n";
            cin >> principleAmount;

            if(principleAmount < 0)
            {
                cout << "Enter a positive value!\n";
            }
        }

        double rateOfInterest = -1;
        while (rateOfInterest < 0 || rateOfInterest > 1)
        {
            cout << "Enter the annual rate of interest (r):\n";
            cin >> rateOfInterest;

            if(rateOfInterest < 0 || rateOfInterest > 1)
            {
                cout << "Enter a value between 0 and 1!\n";
            }
        }
        
        int years = -1;
        while (years < 1)
        {
            cout << "Enter the time in years (t):\n";
            cin >> years;

            if(principleAmount < 0)
            {
                cout << "Enter a positive integer greater than 0!\n";
            }
        }

        cout << "The compound interest of " << principleAmount 
        << " with a rate of interest " << rateOfInterest 
        << " over " << years 
        << " years is " << principleAmount * exponentiate(1 + rateOfInterest, years) - principleAmount << endl;

        cout << "Enter 'E' to exit or run again.\n";
        cin >> exit;
    }
    
}

double exponentiate(double num, int exponent)
{
    //If the exponent is positive
    if(exponent > 0)
    {
        return num * exponentiate(num, exponent - 1);
    }
    //If the exponent is negative
    else if(exponent < 0)
    {
        return 1 / (num * exponentiate(num, -exponent - 1));
    }
    
    //If the exponent is 0
    return 1;
}