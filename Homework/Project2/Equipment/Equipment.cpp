#include "Equipment.h"

using namespace std;

Equipment::Equipment()
{
    name = "";
    isWeapon = false;
    description = "";
    element = 'W';
    effect = 0;
    price = 0;
}

Equipment::Equipment(string inName, string inDescription, bool inIsWeapon, char inElement, double inEffect, double inPrice)
{
    name = inName;
    isWeapon = inIsWeapon;
    description = inDescription;
    element = inElement;
    effect = inEffect;
    price = inPrice;
}