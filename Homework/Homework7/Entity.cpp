// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 4

#include "Entity.h"
#include <iomanip>
using namespace std;

Entity::Entity()
{
    _name = "";
    _gold = 0;
    _hp = 0;
    _condition = 'H';
   _is_enemy = false; 
}

Entity::Entity(string name, double hp, int gold, char condition, bool enemy)
{
    _name = name;

    //Only set hp if it is non negative
    if(hp >= 0)
    {
        _hp = hp;
    }
    else
    {
        _hp = 0;
    }
    if(gold >= 0)
    {
        _gold = gold;
    }
    else
    {
        _gold = 0;
    }

    //Can only be H, P, or D
    if(condition == 'H' || condition == 'P' || condition == 'D')
    {
        _condition = condition;
    }
    else
    {
        _condition = 'H';
    }
    
    _is_enemy = enemy;
}

string Entity::getName()
{
    return _name;
}

double Entity::getHP()
{
    return _hp;
}

char Entity::getCondition()
{
    return _condition;
}

int Entity::getGold()
{
    return _gold;
}

bool Entity::getIsEnemy()
{
    return _is_enemy;
}

void Entity::setName(string name)
{
    _name = name;
}

void Entity::setHP(double HP)
{
    if(HP >= 0)
    {
        _hp = HP;
    }
}

void Entity::setCondition(char condition)
{
    if(condition == 'H' || condition == 'D' || condition == 'P')
    {
        _condition = condition;
    }
}

void Entity::setGold(int gold)
{
    if(gold >= 0)
    {
        _gold = gold;
    }
}

void Entity::setIsEnemy(bool is_enemy)
{
    _is_enemy = is_enemy;
}

void Entity::printStats()
{
    cout << _name << "'s stats:\n"
    << "HP: " << fixed << setprecision(2) << _hp << "\n"
    << "Condition: " << _condition << "\n"
    << "Gold: " << _gold << "\n"
    << "Is Enemy: " << (_is_enemy ? "Yes" : "No") << endl;
}