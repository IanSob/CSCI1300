#include <iostream>
using namespace std;

int patternSearch(string sequence, string fragment);
bool isValidDNASequence(string sequenceToCheck);

int main()
{
    string inputDNASequence;
    string inputFragment;

    cout << "Enter the DNA Sequence:\n";
    cin >> inputDNASequence;
    cout << "Enter the DNA fragment to be searched:\n";
    cin >> inputFragment;

    int numberOfOccurrences = patternSearch(inputDNASequence, inputFragment);

    if(numberOfOccurrences >= 0)
    {
        cout << "Number of occurrences: " << numberOfOccurrences << endl;
    }
    else
    {
        cout << "This is not a valid DNA sequence." << endl;
    }
    return 0;
}

int patternSearch(string sequence, string fragment)
{
    //If the sequences are invalid
    if(!isValidDNASequence(sequence) || !isValidDNASequence(fragment))
    {
        return -1;
    }

    int occurrences = 0;

    for (int i = 0, j = 0; i < static_cast<int>(sequence.length()); i++)
    {
        if(sequence[i] == fragment[j])
        {
            j++;

            //Resetting j if a full fragment was found in the sequence and adding to occurances
            if(j == static_cast<int>(fragment.length()))
            {
                occurrences++;
                j = 0;
            }
        }
        else
        {
            j = 0;
        }
    }
    
    return occurrences;
}

bool isValidDNASequence(string sequenceToCheck)
{
    for (int i = 0; i < static_cast<int>(sequenceToCheck.length()); i++)
    {
        if(sequenceToCheck[i] != 'A' && sequenceToCheck[i] != 'C' && sequenceToCheck[i] != 'G' && sequenceToCheck[i] != 'T')
        {
            return false;
        }
    }
    
    return true;
}