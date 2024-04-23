// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5-6
#include "Game.h"
#include <fstream>
using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE);
bool isValidNumber(string strToCheck);
double clamp(double value, double min, double max);

Game::Game()
{
    _players[0] = Entity();
    _players[1] = Entity();
    _enemies[0] = Entity();
    _enemies[1] = Entity();

    _num_players = 0;
    _num_enemies = 0;
}

Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
{
    //Constrain the values
    _num_enemies = clamp(num_enemies, 0, 2);
    _num_players = clamp(num_players, 0, 2);

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }

    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i] = enemies[i];
    }  
}

int Game::getNumPlayers()
{
    return _num_players;
}

int Game::getNumEnemies()
{
    return _num_enemies;
}

void Game::setPlayersList(Entity players[], int playersToConsider)
{
    _num_players = clamp(playersToConsider, 0, 2);

    for (int i = 0; i < _num_players; i++)
    {
        _players[i] = players[i];
    }
}

void Game::setEnemiesList(Entity enemies[], int enemiesToConsider)
{
    _num_enemies = clamp(enemiesToConsider, 0, 2);

    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i] = enemies[i];
    }
}

bool Game::setPlayer(int index, Entity newPlayer)
{
    if(index < 2 && index >= 0)
    {
        _players[index] = newPlayer;
        _num_players++;
        return true;
    }

    return false;
}

Entity Game::getPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if(_players[i].getName() == name)
        {
            return _players[i];
        }
    }
    
    return Entity();
}

bool Game::setEnemy(int index, Entity newEnemy)
{
    if(index < 2 && index >= 0)
    {
        _enemies[index] = newEnemy;
        _num_enemies++;
        return true;
    }

    return false;
}

Entity Game::getEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if(_enemies[i].getName() == name)
        {
            return _enemies[i];
        }
    }
    
    return Entity();
}

int Game::findPlayer(string name)
{
    for (int i = 0; i < _num_players; i++)
    {
        if(_players[i].getName() == name)
        {
            return i;
        }
    }
    
    return -1;
}

int Game::findEnemy(string name)
{
    for (int i = 0; i < _num_enemies; i++)
    {
        if(_enemies[i].getName() == name)
        {
            return i;
        }
    }
    
    return -1;
}

void Game::printAllStats()
{
    for (int i = 0; i < _num_players; i++)
    {
        _players[i].printStats();
        cout << "----------------------------------------------\n";
    }

    for (int i = 0; i < _num_enemies; i++)
    {
        _enemies[i].printStats();
        cout << "----------------------------------------------\n";
    }
}

bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy)
{
    ifstream characterFile(filename);

    if(!characterFile.is_open())
    {
        return false;
    }

    string currentLine;
    int i = 0;
    //Skip the first line
    getline(characterFile, currentLine);
    while (getline(characterFile, currentLine) && i < CHARACTERS_SIZE)
    {
        string splitStrings[4];
        split(currentLine, '|', splitStrings, 4);

        string name = splitStrings[0];
        double hp = isValidNumber(splitStrings[1]) ? stod(splitStrings[1]) : 0;
        int gold = isValidNumber(splitStrings[2]) ? stoi(splitStrings[2]) : 0;
        char condition = 'H';
        
        if(splitStrings[3] == "H" || splitStrings[3] == "P" || splitStrings[3] == "D")
        {
            condition = splitStrings[3][0];
        }

        characters[i] = Entity(name, hp, gold, condition, is_enemy);
        
        i++;
    }
    characterFile.close();
    return true;
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int numberOfSplits = 0;

    if(input_string.length() == 0)
    {
        return 0;
    }

    for (int i = 0; i < static_cast<int>(input_string.length()); i++)
    {
        //If we are on a separator
        if(input_string[i] == separator)
        {
            numberOfSplits++;
            //If the number of splits is becoming too high, we return -1 and no longer write to the array.
            if(numberOfSplits >= ARR_SIZE)
            {
                return -1;
            }
        }
        else
        {
            arr[numberOfSplits].push_back(input_string[i]);
        }
    }
    
    return numberOfSplits + 1;
}

//Checks if the string is a valid number (digits with up to one decimal)
bool isValidNumber(string strToCheck)
{
    bool containsDecimal = false;
    for (int i = 0; i < static_cast<int>(strToCheck.length()); i++)
    {
        if(strToCheck[i] == '.' && containsDecimal)
        {
            return false;
        }
        else if(strToCheck[i] == '.')
        {
            containsDecimal = true;
        }
        else if(!isdigit(strToCheck[i]))
        {
            return false;
        }
    }

    if(strToCheck.length() == 0)
    {
        return false;
    }

    return true;
}

double clamp(double value, double min, double max)
{
    if(value > max)
    {
        return max;
    }

    if(value < min)
    {
        return min;
    }

    return value;
}