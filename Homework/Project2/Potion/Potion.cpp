#include "Potion.h"

using namespace std;

Potion::Potion()
{
    name = "";
    description = "";
    type = 'H';
    effect = 0;
    price = 0;
    quantity = 0;
}

Potion::Potion(string inName, string inDescription, char inType, double inEffect, double inPrice, int inQuantity)
{
    name = inName;
    description = inDescription;
    type = inType;
    effect = inEffect;
    price = inPrice;
    quantity = inQuantity;
}