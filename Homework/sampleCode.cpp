#include <iostream>
#include <vector>
using namespace std;

void setVectAt(int newValue, int index, vector<int> inVect)
{
    inVect.at(index) = newValue;
    cout << "Vector at: " << index << " set to: " << inVect.at(index) << endl;
}

int main()
{
    vector<int> myInts = {1, 2, 3, 4};
    setVectAt(2, 3, myInts);

    for (int i = 0; i < static_cast<int>(myInts.size()); i++)
    {
        cout << "Position: " << i << " value is: " << myInts.at(i) << endl;
    }
    
}