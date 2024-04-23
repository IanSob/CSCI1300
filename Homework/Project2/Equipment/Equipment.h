#ifndef EQUIPMENT_STRUCT
#define EQUIPMENT_STRUCT

#include <string>

struct Equipment
{
    //Equipment name
    std::string name;

    std::string description;

    bool isWeapon;

    //The elemental property of the equipment ('W': Water, 'A': Air, 'F': Fire, 'E': Earth)
    //If the element is undefined: no special properties are applied
    char element;

    //How effective the equipment is (damage if isWeapon = true or defense if false)
    double effect;

    //Price of the equipment
    double price;

    //Default constructor. (name = empty name, element = 'W', damage = 0, defense = 0, price = 0)
    Equipment();

    /// @brief Constructs object based on parameters
    /// @param inName (string): The name of the Equipment.
    /// @param inDescription (string): Description of Element.
    /// @param inIsWeapon (bool): If the equipment is a weapon.
    /// @param inElement (char): Elemental value of the Equipment.
    /// @param inEffect (double): The effectiveness of the Equipment.
    /// @param inPrice (double): Price of the Equipment.
    Equipment(std::string inName, std::string inDescription, bool inIsWeapon, char inElement, double inEffect, double inPrice);
};

#endif