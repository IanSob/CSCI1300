#ifndef ENTITY_CLASS
#define ENTITY_CLASS

#include <iostream>
#include <string>
#include "Potion/Potion.h"
#include "Equipment/Equipment.h"

class Entity
{
private:
    //Maximum number of potions the Entity can hold
    const static int MAX_POTIONS = 3;

    //Maximum number of holdable equipment
    const static int MAX_EQUIPMENT = 2;

    //Maximum inventory size
    const static int MAX_INVENTORY = 5;

    //Name of the Entity
    std::string name;

    //The type of Entity ('P': Player, 'I': Island enemy, 'E': Epic enemy)
    //Defaults to Island enemy
    char type;

    //Hit points for the Entity
    double HP;

    //Stamina for the Entity
    double stamina;

    //Defense points for the Enemy
    double defense;

    //Condition for the Entity ('H': Healthy, 'P': Poisoned, or 'D' Disease)
    //Defaults to healthy
    char condition;

    //Whether the Entity has move advantage over other Entities.
    bool advantage;

    //The element the Entity is weak to ('W': Water, 'A': Air, 'E': Earth, 'F': Fire)
    //If an undefined weakness, the Entity will not have a weakness
    char elementalWeakness;

    //Amount of gold the Entity has.
    //Defaults to zero for invlaid input
    double gold;

    //Entity's ultimate ability
    std::string ultimateAbility;

    //The potions held by the Entity. Can have 3 stacks, no limit on stack size.
    Potion potions[MAX_POTIONS];

    //Equipment held by entity
    //Note: All equipment has attack and defense stats
    Equipment equipped[MAX_EQUIPMENT];

    //Inventory of Entity / not being held
    Equipment inventory[MAX_INVENTORY];

    //Likelyhood of Entity encountering a calamity
    float calamity;
public:
    //Default constructor (Everything defaulted)
    Entity();

    //Set the Entity's name to the "inName" variable.
    void setName(std::string inName);
    //Returns the name of the Entity.
    std::string getName();

    //Sets the Entity's type
    //False if invalid input: no changes take place.
    bool setType(char inType);
    //Returns Entity's type
    char getType();

    //Sets the HP of the Entity. Returns true if value was set (inHP is non-negative).
    bool setHP(double inHP);
    //Returns the HP of the Entity.
    double getHP();

    //Set the stamina of the Entity. Returns true if value was set (inSamina is non-negative).
    bool setStamina(double inStamina);
    //Gets the Entity's stamina
    double getStamina();

    //Set the defense of the Entity. Returns true if value was set (inDefense is non-negative).
    bool setDefense(double inDefense);
    //Gets the Entity's defense
    double getDefense();

    //Sets the condition of the Entity
    //If invalid input, return false and no changes take place
    bool setCondition(char inCondition);
    //Get the current condition of the Entity
    char getCondition();

    //Sets whether the Entity has advantage
    void setAdvantage(bool inAdvantage);
    //Return whether the Entity has an advantage.
    bool getAdvantage();

    //Sets the weakness for the Entity.
    void setElementalWeakness(char inWeakness);
    //Returns the elemental weakness
    char getElementalWeakness();

    //Sets the Entity's gold count.
    //Returns true if set (no invalid input)
    bool setGold(double inGold);
    //Gets the current gold of the Entity
    double getGold();

    //Sets the ultimate ability
    void setUltimate(std::string inUltimate);
    //Returns ultimate ability
    std::string getUltimate();

    //Sets the potions held from inPotions array
    void setPotions(Potion inPotions[MAX_POTIONS]);
    //Displays all the potions in the potions array
    void displayPotions();
    //Sets the potion at the index. Returns true if successfully set (index is in bounds)
    bool setPotionAt(Potion inPotion, int index);
    //Returns the potion at the index
    //If index is out of bounds: a default potion is returned
    Potion getPotionAt(int index);

    //Sets the new inventory to inInventory array.
    void setInventory(Equipment inInventory[MAX_INVENTORY]);
    //Prints the entire inventory: including empty slots
    void displayInventory();
    //Sets the inventory at the index
    //False if index out of bounds
    bool setInventoryAt(Equipment inEquipment, int index);
    //Get the equipment at the inventory's index
    Equipment getInventoryAt(int index);

    //Sets the calamity of the entity. Returns true if successfully set (inCalamity is non-negative)
    bool setCalamity(float inCalamity);
    //Gets the calamity value for the entity
    float getCalamity();

    //Swaps slot at slotIndex with the inventory item at the index
    //False if could not swap (player must hold one weapon)
    bool swapSlot(int slotIndex, int inventoryIndex);
    //Changes slot at slotIndex equipment with the newEquipped
    //False if could not swap (player must hold one weapon)
    bool changeSlot(int slotIndex, Equipment newEquipped);
    //Returns the currently equipped at slotIndex
    //Emty equipment if failed
    Equipment getSlot(int slotIndex);
};

#endif