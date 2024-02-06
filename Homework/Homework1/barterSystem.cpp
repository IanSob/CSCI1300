#include <iostream>
using namespace std;

int main()
{
    int apples = 0;
    int turkeys = 0;
    int eggs = 0;
    int kiwis = 0;

    cout << "Enter the number of apples:\n";

    cin >> apples;

    //Kiwis
    kiwis = apples / 3;
    apples -= kiwis * 3;

    //Eggs
    eggs = kiwis / 2;
    kiwis -= eggs * 2;

    //Turkeys
    turkeys = eggs / 20;
    eggs -= turkeys * 20;

    cout << "Maximum number of turkey(s) " << turkeys << ", "
    << "egg(s) " << eggs << ", "
    << "kiwi(s) " << kiwis << ", "
    << "apple(s) " << apples << endl;
    
}