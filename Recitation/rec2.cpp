#include <iostream>
using namespace std;

int main()
{
    float litersDrank;

    cout << "How much water did you drink today? (in liters)\n";

    cin >> litersDrank;

    if(litersDrank <= 1.5)
    {
        cout << "You're very, very dehydrated! Get that water in! You have "
        << 3 - litersDrank 
        <<" liters left to drink.\n";
    }
    else if(litersDrank < 3)
    {
        cout << "You're doing great, but you're still halfway to your goal!"
        << " Get that water in! You have "
        << 3 - litersDrank 
        << " liters left to drink.\n";
    }
    else
    {
        cout << "You've hit your goal for the day! Great job getting hydratrated!" << endl;
    }
}