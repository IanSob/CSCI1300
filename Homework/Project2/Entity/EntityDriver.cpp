//Compile command for EntityDriver.cpp when in Project2 directory The -I makes search path / makes my includes work
//g++ -Werror -Wall -Wpedantic -std=c++17 -I. Entity/Entity.cpp Entity/EntityDriver.cpp Equipment/Equipment.cpp Potion/Potion.cpp

#include "Entity/Entity.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    //First part checking Entity Class:
    Entity myEntity;

    //Testing name functions
    myEntity.setName("Test Entity");
    assert(myEntity.getName() == "Test Entity");

    //Testing type functions
    myEntity.setType('I');
    myEntity.setType('T'); //Should not set
    assert(myEntity.getType() == 'I');

    //Testing HP functions
    myEntity.setHP(200);
    myEntity.setHP(-3);
    assert(myEntity.getHP() == 200);

    //Testing stamina functions
    myEntity.setStamina(20);
    myEntity.setStamina(-2);
    assert(myEntity.getStamina() == 20);

    //Testing defense functions
    myEntity.setDefense(3);
    myEntity.setDefense(-2);
    assert(myEntity.getDefense() == 3);

    //Testing condition functions
    myEntity.setCondition('H');
    myEntity.setCondition('T');
    assert(myEntity.getCondition() == 'H');

    //Testing advantage functions
    myEntity.setAdvantage(true);
    assert(myEntity.getAdvantage());

    //Testing elemental weakness functions
    //While N is not a valid weakness, it can still be set the weakness just does not exist
    myEntity.setElementalWeakness('N');
    assert(myEntity.getElementalWeakness() == 'N');
    
    //Testing gold functions
    myEntity.setGold(23);
    myEntity.setGold(-3);
    assert(myEntity.getGold() == 23);

    //Testing ultimate ability
    myEntity.setUltimate("An Ultimate Ability");
    assert(myEntity.getUltimate() == "An Ultimate Ability");

    //Testing potions functions
    Potion potionsArray[3] =
    {
        Potion("First potion", "The first potion",  'U', 23, 10, 60),
        Potion("Second potion", "The second potion", 'S', 0.5, 20, 2),
        Potion("Third potion", "The third potion", 'C', 0.5, 20, 2)
    };
    myEntity.setPotions(potionsArray);
    for (int i = 0; i < 3; i++)
    {
        assert(myEntity.getPotionAt(i).name == potionsArray[i].name);
        assert(myEntity.getPotionAt(i).type == potionsArray[i].type);
        assert(myEntity.getPotionAt(i).effect == potionsArray[i].effect);
        assert(myEntity.getPotionAt(i).price == potionsArray[i].price);
        assert(myEntity.getPotionAt(i).quantity == potionsArray[i].quantity);
    }
    Potion replacement("Replacement", "The replacement", 'U', 30, 5, 3);
    myEntity.setPotionAt(replacement, 1);
    myEntity.setPotionAt(Potion(), -1);
    myEntity.setPotionAt(Potion(), 0);
    assert(myEntity.getPotionAt(1).name == replacement.name);
    assert(myEntity.getPotionAt(1).type == replacement.type);
    assert(myEntity.getPotionAt(1).effect == replacement.effect);
    assert(myEntity.getPotionAt(1).price == replacement.price);
    assert(myEntity.getPotionAt(1).quantity == replacement.quantity);
    myEntity.displayPotions();
    
    //Testing base inventory functions
    Equipment newInventory[5] =
    {
        Equipment("First slot", "The first slot", true, 32, 25, 2),
        Equipment("Second slot", "The second slot", false, 100, 23, 72)
    };
    myEntity.setInventory(newInventory);
    assert(myEntity.getInventoryAt(0).name == "First slot");
    assert(myEntity.getInventoryAt(1).name == "Second slot");
    myEntity.setInventoryAt(Equipment("Third slot", "The third slot", true, 32, 25, 2), 2);
    assert(myEntity.getInventoryAt(2).name == "Third slot");
    myEntity.displayInventory();

    //Test calamity
    assert(myEntity.setCalamity(0.3));
    assert(!myEntity.setCalamity(-1));
    assert(myEntity.getCalamity() == 0.3f);

    //Test slots
    assert(!myEntity.swapSlot(300, 1));
    assert(!myEntity.swapSlot(1, 600));
    assert(!myEntity.changeSlot(-1, Equipment()));
    assert(myEntity.swapSlot(0, 0));
    //Cant swap with no weapon
    assert(!myEntity.swapSlot(0, 1));
    assert(myEntity.swapSlot(1, 1));
    assert(myEntity.getInventoryAt(0).name == "");
    assert(myEntity.getSlot(0).name == "First slot");

    cout << "Asserts on Entity class passed!" << endl;

    return 0;
}