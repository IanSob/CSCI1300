// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 3

#include <iostream>
#include <fstream>
using namespace std;

int countIfConditions(string line);
int countLoopConditions(string line);

int main()
{
    ifstream myStream("testingFile.txt");
    string line;

    int totalifs = 0;
    int totalLoops = 0;

    while (getline(myStream, line))
    {
        totalifs += countIfConditions(line);
        totalLoops += countLoopConditions(line);
    }
    
    cout << "Total ifs: " << totalifs << "\n" << "Total Loops: " << totalLoops << endl;

    return 0;
}

int countLoopConditions(string line)
{
    int numberOfLoops = 0;
    int numberOfWords = 0;
    bool inSlashes = false;

    for (int i = 0; i < static_cast<int>(line.length()); i++)
    {
        //Adds one less since it will be incremented at the end anyways
        if ((i + 4) < static_cast<int>(line.length()) && line.substr(i, 5) == "while" && !inSlashes)
        {
            numberOfLoops++;
            i += 4;
        }
        else if((i + 2) < static_cast<int>(line.length()) && line.substr(i, 3) == "for" && !inSlashes)
        {
            numberOfLoops++;
            i += 2;
        }
        
        if(line.substr(i, 2) == "//")
        {
            inSlashes = true;
        }

        //Checks the number of words
        if(line[i] == ' ' && line[(i - 1 < 0 ? 0 : i - 1)] != ' ')
        {
            numberOfWords++;
        }
    }
    
    if(numberOfWords > 40)
    {
        return 0;
    }

    return numberOfLoops;
}

//Count instances of conditionals on line
int countIfConditions(string line)
{
    int numberOfConditionals = 0;
    int numberOfWords = 0;
    bool inQuotes = false;
    bool inSlashes = false;

    for (int i = 0; i < static_cast<int>(line.length()); i++)
    {
        //Adds one less since it will be incremented at the end anyways
        if ((i + 1) < static_cast<int>(line.length()) && line.substr(i, 2) == "if " && !inQuotes && !inSlashes && !isalpha(line[i + 2]))
        {
            numberOfConditionals++;
            i++;
        }
        else if((i + 6) < static_cast<int>(line.length()) && line.substr(i, 7) == "else if" && !inQuotes && !inSlashes)
        {
            numberOfConditionals++;
            numberOfWords++;
            i += 6;
        }    
        else if((i + 3) < static_cast<int>(line.length()) && line.substr(i, 4) == "else" && !inQuotes && !inSlashes)
        {
            numberOfConditionals++;
            i += 3;
        }
        
        if(line.substr(i, 2) == "//")
        {
            inSlashes = true;
        }

        if(line[i] == '"')
        {
            inQuotes = !inQuotes;
        }

        //Checks the number of words
        if(line[i] == ' ' && line[(i - 1 < 0 ? 0 : i - 1)] != ' ')
        {
            numberOfWords++;
        }
    }
    
    if(numberOfWords > 40)
    {
        return 0;
    }

    return numberOfConditionals;
}