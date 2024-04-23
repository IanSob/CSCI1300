#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    int menuChoice = 0;
    Game currentGame;
    string playerNames[2];
    string enemyNames[2];
    while (menuChoice != 6)
    {
        cout << "Select from the following options:\n"
        << "1. Select Players and Enemies\n"
        << "2. Display Players' stats\n"
        << "3. Display Enemies' stats\n"
        << "4. Edit a Player's Stats\n"
        << "5. Edit an Enemy's Stats\n"
        << "6. Exit" << endl;

        //Gathering input and some validation
        string selectionAsString;
        getline(cin, selectionAsString);
        bool validSelection = true;
        for (int i = 0; i < static_cast<int>(selectionAsString.length()); i++)
        {
            if(!isdigit(selectionAsString[i]))
            {
                validSelection = false;
                break;
            }
        }
        if(validSelection)
        {
            menuChoice = stoi(selectionAsString);
        }

        switch (menuChoice)
        {
        case 1:
        {
            bool invalidSelection = true;
            Entity choosablePlayers[5];
            Entity choosableEnemies[5];
            //If both files can be loaded
            if(loadCharacters("players_full.txt", choosablePlayers, 5, false) && loadCharacters("enemies_full.txt", choosableEnemies, 4, true))
            {
                //Players
                for (int j = 0; j < 2; j++)
                {
                    //Prompt user
                    cout << "Player " << j + 1 << "\nHere is a list of players you can select from:\n";
                    for (int i = 0; i < 5; i++)
                    {
                        if(choosablePlayers[i].getName() != "")
                        {
                            choosablePlayers[i].printStats();
                            cout << "----------------------------------------------\n";
                        }
                    }

                    while (invalidSelection)
                    { 
                        string selectedName;
                        cout << "The selected character is:\n";
                        getline(cin, selectedName);

                        for (int i = 0; i < 5; i++)
                        {
                            if(choosablePlayers[i].getName() == selectedName && selectedName != "")
                            {
                                invalidSelection = false;
                                currentGame.setPlayer(j, choosablePlayers[i]);
                                playerNames[j] = choosablePlayers[i].getName();
                                //Set empty Entity to remove choices
                                choosablePlayers[i] = Entity();
                            }
                        }

                        if(invalidSelection)
                        {
                            cout << "Invalid selection. Select from the list!\n";
                        }
                    }
                    invalidSelection = true;
                }

                //Enemies
                for (int j = 0; j < 2; j++)
                {
                    //Prompt user
                    cout << "Enemy " << j + 1 << "\nHere is a list of enemies you can select from:\n";
                    for (int i = 0; i < 5; i++)
                    {
                        if(choosableEnemies[i].getName() != "")
                        {
                            choosableEnemies[i].printStats();
                            cout << "----------------------------------------------\n";
                        }
                    }

                    while (invalidSelection)
                    {
                        string selectedName;
                        cout << "The selected character is:\n";
                        getline(cin, selectedName);

                        for (int i = 0; i < 5; i++)
                        {
                            if(choosableEnemies[i].getName() == selectedName && selectedName != "")
                            {
                                invalidSelection = false;
                                currentGame.setEnemy(j, choosableEnemies[i]);
                                enemyNames[j] = choosableEnemies[i].getName();
                                //Set empty Entity to remove choices
                                choosableEnemies[i] = Entity();
                            }
                        }

                        if(invalidSelection)
                        {
                            cout << "Invalid selection. Select from the list!\n";
                        }
                    }
                    invalidSelection = true;
                }
            }
            else
            {
                cout << "Invalid  text file being read.\n";
            }

            menuChoice = 0;
        }
        break;

        case 2:
        {
            currentGame.getPlayer(playerNames[0]).printStats();
            cout << "----------------------------------------------\n";
            currentGame.getPlayer(playerNames[1]).printStats();
            cout << "----------------------------------------------\n";
        }
        break;

        case 3:
        {
            currentGame.getEnemy(enemyNames[0]).printStats();
            cout << "----------------------------------------------\n";
            currentGame.getEnemy(enemyNames[1]).printStats();
            cout << "----------------------------------------------\n";
        }
        break;

        case 4:
        {
            cout << "Which player's stats do you want to edit?\n";
            currentGame.getPlayer(playerNames[0]).printStats();
            cout << "----------------------------------------------\n";
            currentGame.getPlayer(playerNames[1]).printStats();
            cout << "----------------------------------------------\n";

            string selectedCharater;
            bool invalidSelection = true;
            while (invalidSelection)
            {
                cout << "The selected character is:\n";
                getline(cin, selectedCharater);

                if(currentGame.findPlayer(selectedCharater) != -1)
                {
                    invalidSelection = false;
                }
                else
                {
                    cout << "Invalid selection. Select from the list!\n";
                }
            }

            int choice = 0;
            invalidSelection = true;

            while (invalidSelection)
            {
                cout << "Editing player "<< selectedCharater << "'s stats:\n"
                << "1. Edit hp\n"
                << "2. Edit condition\n"
                << "3. Edit gold" << endl;
                string currentSelection;
                getline(cin, currentSelection);

                if(currentSelection.length() == 1 && isdigit(currentSelection[0]))
                {
                    choice = stoi(currentSelection);
                }
                
                invalidSelection = (choice != 1 && choice != 2 && choice != 3);

                if(invalidSelection)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }
            }

            switch (choice)
            {
            case 1:
            {
                string inputString;
                invalidSelection = true;
                while (invalidSelection)
                {
                    cout << "Enter the new value:\n";
                    getline(cin, inputString);
                    bool containsDecimal = false;
                    invalidSelection = false;

                    if(inputString[0] == '-')
                    {
                        cout << "Enter a non-negative value!\n";
                        invalidSelection = true;
                        continue;
                    }

                    for (int i = 0; i < static_cast<int>(inputString.length()); i++)
                    {
                        if(inputString[i] != '.' && !isdigit(inputString[i]))
                        {
                            invalidSelection = true;
                            break;
                        }
                        else if(inputString[i] == '.')
                        {
                            if(containsDecimal)
                            {
                                invalidSelection = true;
                                break;
                            }
                            else
                            {
                                containsDecimal = true;
                            }
                        }
                    }
                    
                    if(invalidSelection)
                    {
                        cout << "Invalid input!\n";
                    }
                    else
                    {
                        Entity newPlayer = currentGame.getPlayer(selectedCharater);
                        newPlayer.setHP(stod(inputString));
                        currentGame.setPlayer(currentGame.findPlayer(selectedCharater), newPlayer);
                    }
                }  
            }   
            break;
            
            case 2:
            {
                invalidSelection = true;
                while (invalidSelection)
                {
                    string inputString;
                    cout << "Enter the new value:\n";
                    getline(cin, inputString);
                    
                    if(inputString.length() == 1 && (inputString[0] == 'H' || inputString[0] == 'D' || inputString[0] == 'P'))
                    {
                        invalidSelection = false;
                        Entity newPlayer = currentGame.getPlayer(selectedCharater);
                        newPlayer.setCondition(inputString[0]);
                        currentGame.setPlayer(currentGame.findPlayer(selectedCharater), newPlayer);
                    }
                    else
                    {
                        cout << "Enter a value among 'H', 'D' or 'P'!\n";
                    }
                }
            }
            break;

            case 3:
            {
                string inputString;
                invalidSelection = true;
                while (invalidSelection)
                {
                    cout << "Enter the new value:\n";
                    getline(cin, inputString);
                    invalidSelection = false;

                    if(inputString[0] == '-')
                    {
                        cout << "Enter a non-negative value!\n";
                        invalidSelection = true;
                        continue;
                    }

                    for (int i = 0; i < static_cast<int>(inputString.length()); i++)
                    {
                        if(!isdigit(inputString[i]))
                        {
                            invalidSelection = true;
                            break;
                        }
                    }
                    
                    if(invalidSelection)
                    {
                        cout << "Invalid input!\n";
                    }
                    else
                    {
                        Entity newPlayer = currentGame.getPlayer(selectedCharater);
                        newPlayer.setGold(stoi(inputString));
                        currentGame.setPlayer(currentGame.findPlayer(selectedCharater), newPlayer);
                    }
                }  
            } 
            break;
            }            
        }
        break;

        case 5:
        {
            cout << "Which enemy's stats do you want to edit?\n";
            currentGame.getEnemy(enemyNames[0]).printStats();
            cout << "----------------------------------------------\n";
            currentGame.getEnemy(enemyNames[1]).printStats();
            cout << "----------------------------------------------\n";

            string selectedCharater;
            bool invalidSelection = true;
            while (invalidSelection)
            {
                cout << "The selected character is:\n";
                getline(cin, selectedCharater);

                if(currentGame.findEnemy(selectedCharater) != -1)
                {
                    invalidSelection = false;
                }
                else
                {
                    cout << "Invalid selection. Select from the list!\n";
                }
            }

            int choice = 0;
            invalidSelection = true;

            while (invalidSelection)
            {
                cout << "Editing enemy "<< selectedCharater << "'s stats:\n"
                << "1. Edit hp\n"
                << "2. Edit condition\n"
                << "3. Edit gold" << endl;
                string currentSelection;
                getline(cin, currentSelection);

                if(currentSelection.length() == 1 && isdigit(currentSelection[0]))
                {
                    choice = stoi(currentSelection);
                }
                
                invalidSelection = (choice != 1 && choice != 2 && choice != 3);

                if(invalidSelection)
                {
                    cout << "Invalid selection. Select from the list!" << endl;
                }
            }

            switch (choice)
            {
                case 1:
                {
                    string inputString;
                    invalidSelection = true;
                    while (invalidSelection)
                    {
                        cout << "Enter the new value:\n";
                        getline(cin, inputString);
                        bool containsDecimal = false;
                        invalidSelection = false;

                        if(inputString[0] == '-')
                        {
                            cout << "Enter a non-negative value!\n";
                            invalidSelection = true;
                            continue;
                        }

                        for (int i = 0; i < static_cast<int>(inputString.length()); i++)
                        {
                            if(inputString[i] != '.' && !isdigit(inputString[i]))
                            {
                                invalidSelection = true;
                                break;
                            }
                            else if(inputString[i] == '.')
                            {
                                if(containsDecimal)
                                {
                                    invalidSelection = true;
                                    break;
                                }
                                else
                                {
                                    containsDecimal = true;
                                }
                            }
                        }
                        
                        if(invalidSelection)
                        {
                            cout << "Invalid input!\n";
                        }
                        else
                        {
                            Entity newEnemy = currentGame.getEnemy(selectedCharater);
                            newEnemy.setHP(stod(inputString));
                            currentGame.setEnemy(currentGame.findEnemy(selectedCharater), newEnemy);
                        }
                    }  
                }   
                break;
                
                case 2:
                {
                    invalidSelection = true;
                    while (invalidSelection)
                    {
                        string inputString;
                        cout << "Enter the new value:\n";
                        getline(cin, inputString);
                        
                        if(inputString.length() == 1 && (inputString[0] == 'H' || inputString[0] == 'D' || inputString[0] == 'P'))
                        {
                            invalidSelection = false;
                            Entity newEnemy = currentGame.getEnemy(selectedCharater);
                            newEnemy.setCondition(inputString[0]);
                            currentGame.setEnemy(currentGame.findEnemy(selectedCharater), newEnemy);
                        }
                        else
                        {
                            cout << "Enter a value among 'H', 'D' or 'P'!\n";
                        }
                    }
                }
                break;

                case 3:
                {
                    string inputString;
                    invalidSelection = true;
                    while (invalidSelection)
                    {
                        cout << "Enter the new value:\n";
                        getline(cin, inputString);
                        invalidSelection = false;

                        if(inputString[0] == '-')
                        {
                            cout << "Enter a non-negative value!\n";
                            invalidSelection = true;
                            continue;
                        }

                        for (int i = 0; i < static_cast<int>(inputString.length()); i++)
                        {
                            if(!isdigit(inputString[i]))
                            {
                                invalidSelection = true;
                                break;
                            }
                        }
                        
                        if(invalidSelection)
                        {
                            cout << "Invalid input!\n";
                        }
                        else
                        {
                            Entity newEnemy = currentGame.getEnemy(selectedCharater);
                            newEnemy.setGold(stoi(inputString));
                            currentGame.setEnemy(currentGame.findEnemy(selectedCharater), newEnemy);
                        }
                    }  
                }
                break;
            }            
        }
        break;

        case 6:
            cout << "Bye!!" << endl;
        break;
        
        default:
            cout << "Invalid input. Please enter a valid choice (1-6)\n";
        break;
        }
    }
}