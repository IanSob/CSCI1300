#include <iostream>
#include <map>
using namespace std;


int main()
{
    //Map of costs based on input. Learned about maps and accessing them here: https://www.javatpoint.com/post/cpp-map-find-function
    const map <char, float> planCosts = {{'A', 684.29f}, {'I', 479.85f}, {'P', 950.33f}, {'B', 250.15f}};

    //User input
    float userBudget = 0;
    char planSelection = 'X';

    //Budget
    cout << "What is your budget?\n";
    cin >> userBudget;

    //Plan
    cout << "Which of these passes would you like to take (B, I, A or P)?\n";
    cin >> planSelection;

    //Make sure the value is a part of the map
    if(planCosts.find(planSelection) == planCosts.end() || userBudget < 0)
    {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    //Checking if plan in budget
    if(userBudget >= planCosts.find(planSelection)->second)
    {
        cout << "Yes, this pass is within your budget!\n";
    }
    else
    {
        cout << "Sorry, this pass is outside your budget.";
    }

    return 0;
}