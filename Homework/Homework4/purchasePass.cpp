// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5b
#include <iostream>
using namespace std;

bool budgetCheck(double budget, char pass_type);
double purchasePass(double budget, char pass_type);


int main()
{
    double budgetInput;
    double balanceAfterPurchase;
    char planSelection;

    cout << "Enter your budget:\n";
    cin >> budgetInput;

    cout << "Enter the type of pass you would like to check ('B', 'I', 'A', 'P'):\n";
    cin >> planSelection;

    balanceAfterPurchase = purchasePass(budgetInput, planSelection);

    if(budgetInput != balanceAfterPurchase)
    {
        cout << "Pass purchased successfully. Updated budget: $" << balanceAfterPurchase << endl;
    }
    else
    {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
    }

    return 0;
}

double purchasePass(double budget, char pass_type)
{
    if(!budgetCheck(budget, pass_type))
    {
        return budget;
    }

    switch(pass_type)
    {
        case 'B':
            return budget - 250.15;
        break;

        case 'I':
            return budget - 479.85;
        break;

        case 'A':
            return budget - 684.29;
        break;

        case 'P':
            return budget - 950.33;
        break;
    }

    return budget;
}

bool budgetCheck(double budget, char pass_type)
{
    if(budget < 0)
    {
        return false;
    }

    switch(pass_type)
    {
        //Basic
        case 'B':
            if(budget >= 250.15)
            {
                return true;
            }
        break;

        //Intermediate
        case 'I':
            if(budget >= 479.85)
            {
                return true;
            }
        break;

        //Advanced
        case 'A':
            if(budget >= 684.29)
            {
                return true;
            }
        break;

        //Premium
        case 'P':
            if(budget >= 950.33)
            {
                return true;
            }
        break;
    }

    return false;
}