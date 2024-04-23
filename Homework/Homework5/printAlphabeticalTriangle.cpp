#include <iostream>
using namespace std;

void printTriangle(int height);

int main()
{
    printTriangle(-1);
}

void printTriangle(int height)
{
    //Error handling
    if(height < 1)
    {
        cout << "Invalid input." << endl;
        return;
    }

    int timesPrinted = 0;

    for (int i = height; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(timesPrinted % 26 + 97);
            timesPrinted++;
        }
        cout << endl;
    }
    
}