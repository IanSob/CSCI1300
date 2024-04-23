// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5a
#include <iostream>
using namespace std;

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

int main()
{
    double budgetInput;
    char planSelection;
    bool isInBudget;

    cout << "Enter your budget:\n";
    cin >> budgetInput;

    cout << "Enter the type of pass you would like to check ('B', 'I', 'A', 'P'):\n";
    cin >> planSelection;

    isInBudget = budgetCheck(budgetInput, planSelection);

    if(isInBudget)
    {
        cout << "Yes, this pass is within your budget!" << endl;
    }
    else
    {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
    }

    return 0;
}