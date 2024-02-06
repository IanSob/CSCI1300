#include<iostream>
using namespace std;
int main()
{
    double score = 0;
    char grade='F';

    cout << "Enter the score you earned for CSCI 1300: ";
    cin >> score;


    if (score < 60)
    {
        cout << "Grade: F" << endl;
    }
    else if (score < 63)
    {
        cout << "Grade: D-" << endl;
    }
    else if (score < 67)
    {
        cout << "Grade: D" << endl;
    }
    else if (score < 70)
    {
        cout << "Grade: D+" << endl;
    }
    else if (score < 73)
    {
        cout << "Grade: C-" << endl;
    }
    else if (score < 77)
    {
        cout << "Grade: C" << endl;
    }
    else if (score < 80)
    {
        cout << "Grade: C+" << endl;
    }
    else if (score < 83)
    {
        cout << "Grade: B-" << endl;
    }
    else if (score < 87)
    {
        cout << "Grade: B" << endl;
    }
    else if (score < 90)
    {
        cout << "Grade: B+" << endl;
    }
    else if (score < 93)
    {
        cout << "Grade: A-" << endl;
    }
    else if (score >= 93)
    {
        cout << "Grade: A" << endl;
    }
    return 0;
}
