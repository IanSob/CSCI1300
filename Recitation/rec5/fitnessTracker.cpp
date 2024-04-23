#include <iostream>
#include <string>
using namespace std;


int main()
{
    int cardio = 0;
    int flexability = 0;
    int strength = 0;
    int timeInput;
    string categoryInput;


    while(categoryInput != "exit")
    {
        cout << "Enter a category (Cardio, Strength, Flexability, or 'exit'):\n";
        cin >> categoryInput;
         
        //Even though the loop already checks this, it will still ask for an input before actually exiting.
        if(categoryInput == "exit")
        {
            break;
        }

        if(categoryInput == "Cardio")
        {
            cout << "Enter the exercise time:" << endl;
            cin >> timeInput;

            cardio += timeInput;
        }
        else if(categoryInput == "Strength")
        {
            cout << "Enter the exercise time:" << endl;
            cin >> timeInput;

            strength += timeInput;
        }
        else if(categoryInput == "Flexability")
        {
            cout << "Enter the exercise time:" << endl;
            cin >> timeInput;

            flexability += timeInput;
        }
        else
        {
            cout  << "Invalid category. Please anter a valid category." << endl;
        }
    }

    cout << "Category-wise totals:\n"
    << "Cardio: " << cardio << " mins\n"
    << "Strength: " << strength << " mins\n"
    << "Flexability: " << flexability << " mins\n"
    << "Total exercise time for the day: " << cardio + strength + flexability << " mins."
    << endl;
    
}