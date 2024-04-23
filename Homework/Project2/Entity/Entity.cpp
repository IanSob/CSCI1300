#include "Entity.h"

using namespace std;

Entity::Entity()
{
    name = "";
    type = 'I';
    HP = 0;
    stamina = 0;
    defense = 0;
    condition = 'H';
    advantage = false;
    //Default no weakness (any char outside of weakness types)
    elementalWeakness = 'N';
    gold = 0;
    ultimateAbility = "";
    calamity = 0;
}

void Entity::setName(string inName)
{
    name = inName;
}

string Entity::getName()
{
    return name;
}

bool Entity::setType(char inType)
{
    if(inType == 'P' || inType == 'I' || inType == 'E')
    {
        type = inType;
        return true;
    }

    return false;
}

char Entity::getType()
{
    return type;
}

bool Entity::setHP(double inHP)
{
    if(inHP >= 0)
    {
        HP = inHP;
        return true;
    }

    return false;
}

double Entity::getHP()
{
    return HP;
}

bool Entity::setStamina(double inStamina)
{
    if(inStamina >= 0)
    {
        stamina = inStamina;
        return true;
    }

    return false;
}

double Entity::getStamina()
{
    return stamina;
}

bool Entity::setDefense(double inDefense)
{
    if(inDefense >= 0)
    {
        defense = inDefense;
    }

    return false;
}

double Entity::getDefense()
{
    return defense;
}

bool Entity::setCondition(char inCondition)
{
    if(inCondition == 'H' || inCondition == 'P' || inCondition == 'D')
    {
        condition = inCondition;
        return true;
    }

    return false;
}

char Entity::getCondition()
{
    return condition;
}

void Entity::setAdvantage(bool inAdvantage)
{
    advantage = inAdvantage;
}

bool Entity::getAdvantage()
{
    return advantage;
}

void Entity::setElementalWeakness(char inWeakness)
{
    elementalWeakness = inWeakness;
}

char Entity::getElementalWeakness()
{
    return elementalWeakness;
}

bool Entity::setGold(double inGold)
{
    if(inGold >= 0)
    {
        gold = inGold;
        return true;
    }

    return false;
}

double Entity::getGold()
{
    return gold;
}

void Entity::setUltimate(string inUltimate)
{
    ultimateAbility = inUltimate;
}

string Entity::getUltimate()
{
    return ultimateAbility;
}

void Entity::setPotions(Potion inPotions[MAX_POTIONS])
{
    for (int i = 0; i < MAX_POTIONS; i++)
    {
        potions[i] = inPotions[i];
    }   
}

void Entity::displayPotions()
{
    cout << "------------------------------------------\n";
    for (int i = 0; i < MAX_POTIONS; i++)
    {
        cout << "Potion Slot " << i + 1 << ":\n";
        if(potions[i].name == "")
        {
            cout << "EMPTY SLOT";
        }
        else
        {
            cout << "Name: " << potions[i].name
            << "\nDescription: " << potions[i].description
            << "\nEffectiveness: " << potions[i].effect
            << "\nPrice: " << potions[i].price
            << "\nType: " << potions[i].type
            << "\nQuantity: " << potions[i].quantity;
        }
        cout << "\n------------------------------------------" << endl;
    }
    
}

bool Entity::setPotionAt(Potion inPotion, int index)
{
    if(index < MAX_POTIONS && index >= 0)
    {
        potions[index] = inPotion;
    }

    return false;
}

Potion Entity::getPotionAt(int index)
{
    if(index >= 0 && index < MAX_POTIONS)
    {
        return potions[index];
    }

    return Potion();
}

void Entity::setInventory(Equipment inInventory[MAX_INVENTORY])
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        inventory[i] = inInventory[i];
    }
}

void Entity::displayInventory()
{
    cout << "------------------------------------------\n";
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        cout << "Inventory Slot " << i + 1 << ":\n";
        if(inventory[i].name == "")
        {
            cout << "EMPTY SLOT";
        }
        else
        {
            cout << "Name: " << inventory[i].name
            << "\nDescription: " << inventory[i].description
            << "\nType: " << (inventory[i].isWeapon ? "Weapon" : "Shield")
            << "\nEffect: " << inventory[i].effect
            << "\nPrice: " << inventory[i].price
            << "\nElement: " << inventory[i].element;
        }
        cout << "\n------------------------------------------" << endl;
    }
}

bool Entity::setInventoryAt(Equipment inEquipment, int index)
{
    if(index >= 0 && index < MAX_INVENTORY)
    {
        inventory[index] = inEquipment;
        return true;
    }

    return false;
}

Equipment Entity::getInventoryAt(int index)
{
    if(index >= 0 && index < MAX_INVENTORY)
    {
        return inventory[index];
    }
    
    return Equipment();
}

bool Entity::setCalamity(float inCalamity)
{
    if(inCalamity >= 0)
    {
        calamity = inCalamity;
        return true;
    }

    return false;
}

float Entity::getCalamity()
{
    return calamity;
}

bool Entity::swapSlot(int slotIndex, int inventoryIndex)
{
    Equipment tempEquip;
    //Making sure indexs are in range
    if(slotIndex >= 0 && slotIndex < MAX_EQUIPMENT && inventoryIndex >= 0 && inventoryIndex < MAX_INVENTORY)
    {
        //True if another weapon is also equipped
        bool anotherWep = false;
        //Setting anotherWep
        for (int i = 0; i < MAX_EQUIPMENT; i++)
        {
            if(i != slotIndex && equipped[i].isWeapon)
            {
                anotherWep = true;
                break;
            }
        }
        
        //Make sure we can swap
        if(equipped[slotIndex].isWeapon == false || inventory[inventoryIndex].isWeapon || anotherWep)
        {
            //Swapping
            tempEquip = equipped[slotIndex];
            equipped[slotIndex] = inventory[inventoryIndex];
            inventory[inventoryIndex] = tempEquip;
            return true;
        }
    }

    return false;
}

bool Entity::changeSlot(int slotIndex, Equipment newEquipped)
{
    //Code very similar to swapSlot
    if(slotIndex >= 0 && slotIndex < MAX_EQUIPMENT)
    {
        //True if another weapon is also equipped
        bool anotherWep = false;
        //Setting anotherWep
        for (int i = 0; i < MAX_EQUIPMENT; i++)
        {
            if(i != slotIndex && equipped[i].isWeapon)
            {
                anotherWep = true;
                break;
            }
        }
        
        //Make sure we can change the equip
        if(equipped[slotIndex].isWeapon == false || newEquipped.isWeapon || anotherWep)
        {
            //Changing the slot
            equipped[slotIndex] = newEquipped;
            return true;
        }
    }

    return false;
}

Equipment Entity::getSlot(int slotIndex)
{
    if(slotIndex >= 0 && slotIndex < MAX_EQUIPMENT)
    {
        return equipped[slotIndex];
    }

    return Equipment();
}