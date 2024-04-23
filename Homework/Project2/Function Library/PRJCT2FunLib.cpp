#include "PRJCT2FunLib.h"

using namespace std;

std::vector<std::string> project2Library::split(std::string stringToSplit, char seperator)
{
    //The current split
    string currentSplit = "";

    //The vector of split strings we will return
    std::vector<std::string> splitStrings;

    for (int i = 0; i < static_cast<int>(stringToSplit.length()); i++)
    {
        if(stringToSplit[i] == seperator)
        {
            splitStrings.push_back(currentSplit);
            currentSplit = "";
        }
        else
        {
            currentSplit.push_back(stringToSplit[i]);
        }
    }
    
    splitStrings.push_back(currentSplit);

    return splitStrings;
}