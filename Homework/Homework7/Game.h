// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 5-6
#ifndef GAME_CLASS
#define GAME_CLASS

#include <iostream>
#include "Entity.h"

class Game
{
private:
    //Player objects
    Entity _players[2];

    //Enemy objects
    Entity _enemies[2];

    //Current number of players
    int _num_players;

    //Current number of enemies
    int _num_enemies;

public:
    //Default constructor
    Game();

    /// @brief Constructs a game with the parameters
    /// @param players (Entity[]): The array of players (only the first two)
    /// @param enemies (Entity[]): The array of enemies (only first two)
    /// @param num_players (int): The current number of players
    /// @param num_enemies (int): The current number of enemies
    Game(Entity players[], Entity enemies[], int num_players, int num_enemies);

    //Gets the current number of players
    int getNumPlayers();

    //Gets the current number of enemies
    int getNumEnemies();

    //Set the array of players (only first two)
    //playersToConsider is the number of objects from the array to use
    void setPlayersList(Entity players[], int playersToConsider);

    //Set the array of enemies (only first two)
    //enemiesToConsider is the number of objects from the array to use
    void setEnemiesList(Entity enemies[], int enemiesToConsider);

    //Sets the player at the given index
    bool setPlayer(int index, Entity newPlayer);

    //Returns player with the name 'name' (empty Entity returned if cannot be found)
    Entity getPlayer(std::string name);

    //Sets the enemy at the given index
    bool setEnemy(int index, Entity newEnemy);

    //Returns enemy with the name 'name' (empty Entity returned if cannot be found)
    Entity getEnemy(std::string name);

    //Returns the index of the player with the name 'name'
    int findPlayer(std::string name);

    //Returns the index of the enemy with the name 'name'
    int findEnemy(std::string name);

    //Print all the stats of the players and enemies
    void printAllStats();
};

bool loadCharacters(std::string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy);

#endif