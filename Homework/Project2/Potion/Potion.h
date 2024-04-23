#ifndef POTION_STRUCT
#define POTION_STRUCT
#include <iostream>
#include <string>

struct Potion
{
    //Potions name
    std::string name;

    //Description of the potion
    std::string description;

    //The type of potion ('H': Healing, 'C': Cleansing, 'S': Stamina, 'U': Ultimate, 'D': Damage potion (increase damage))
    //Undefined type has random effect
    char type;

    //Effectivness of potion
    double effect;

    //Price of one potion
    double price;

    //Number of potions
    int quantity;

    //Default constructor (blank name, healing potion, 0 effect, 0 price, 0 quantity)
    Potion();

    /// @brief Constructs object using in parameters
    /// @param inName (string): The name of the potion.
    /// @param inType (char): The type of potion.
    /// @param inEffect (double): The effectiveness of the potion.
    /// @param inPrice (double): The price of one potion.
    /// @param inQuantity (int): The number of potions.
    Potion(std::string inName, std::string inDescription, char inType, double inEffect, double inPrice, int inQuantity);
};

#endif