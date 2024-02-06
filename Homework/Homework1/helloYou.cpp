#include <iostream>
using namespace std;


int main(){    
    //Name variable.
    string inputName = "No Name Input";

    //Ask for name
    cout << "Please enter your name below:" << endl;

    //Grab name
    cin >> inputName;

    cout << "Hello, " + inputName + "\nHow are you ?\n";

    return 0;
}