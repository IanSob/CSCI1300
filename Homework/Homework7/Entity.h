// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 4
#ifndef ENTITY_CLASS
#define ENTITY_CLASS

#include <iostream>

class Entity
{
private:
    std::string _name;

    double _hp;

    int _gold;

    //Entity's current condition
    char _condition;

    bool _is_enemy;

public:
    //Default constructor
    Entity();

    /// @brief Creates the entity with parameters
    /// @param name (string): The name of the entity
    /// @param hp (double): The hp of the entity (cannot be negative)
    /// @param gold (int): The amount of gold the entity has (cannot be negative)
    /// @param condition (char): The current condition of the entity (must be 'H', 'D', or 'P')
    /// @param enemy (bool): Whether the entity is an enemy or not
    Entity(std::string name, double hp, int gold, char condition, bool enemy);

    //Get the name of the entity
    std::string getName();

    //Get entity's HP
    double getHP();

    //Get entity's current condition
    char getCondition();

    //Get the entity's current gold count
    int getGold();

    //Whether the entity is an enemy or not.
    bool getIsEnemy();

    //Set entity's name
    void setName(std::string name);

    //Set the HP of the entity (cannot be negative)
    void setHP(double HP);

    //Set condition of the entity (must be 'H', 'D', or 'P')
    void setCondition(char condition);

    //Sets entity's gold (cannot be negative)
    void setGold(int gold);

    //Sets entity's _is_enemy bool value
    void setIsEnemy(bool is_enemy);

    //Print the current stats of the entity
    void printStats();
};

#endif