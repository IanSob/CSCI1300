#include <iostream>
using namespace std;

int main()
{
    double p_amount = 0.0;
    double interest_rate = 0.0;
    double time_in_years = 0.0;

    cout << "Enter principal amount:\n";
    cin  >> p_amount;
    cout << "Enter rate of interest:\n";
    cin >> interest_rate;
    cout << "Enter time (in years):\n";
    cin >> time_in_years;

    double simple_interest = (p_amount * interest_rate * time_in_years)/100;

    cout << "Simple interest: " + to_string(simple_interest) << endl;

    return simple_interest;
    
}