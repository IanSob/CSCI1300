#include <iostream>
using namespace std;

int main()
{
    float cardBalance = 30;
    //Minimum balance the card can be.
    float minBalance = 20;
    //User input
    float withdrawAmount = 0;

    //Prompt user
    cout << "Enter the amount to be withdrawn from your card.\n";

    //Grab  input
    cin >> withdrawAmount;

    if(withdrawAmount < 0)
    {
        cout << "Invalid input. Withdrawn amount must be a non-negative value." << endl;
        return 0;
    }

    if((cardBalance - withdrawAmount) >= minBalance)
    {
        cardBalance -= withdrawAmount;
        cout << "Transaction Successful! Your balance is $"
        << cardBalance << "." << endl;
    }
    else
    {
        cout << "Transaction Failed!" << endl;
    }

    return 0;
}