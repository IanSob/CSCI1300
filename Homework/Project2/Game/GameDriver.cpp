//This file is meant to test the Game.h and Game.cpp files, not to run the game
//Compiles with (when in Project2 directory):
//g++ -Werror -Wall -Wpedantic -std=c++17 -I. Game/GameDriver.cpp Game/Game.cpp Potion/Potion.cpp "Function Library/PRJCT2FunLib.cpp" Equipment/Equipment.cpp Entity/Entity.cpp
#include <iostream>
#include <cassert>
#include "Game.h"
using namespace std;

int main()
{
    Game gameToTest;
    
    //Testing the set/getPlayers
    Entity player1;
    Entity player2;
    player1.setName("Player 1");
    player1.setType('P');
    assert(gameToTest.setPlayerAt(player1, 0));
    assert(!gameToTest.setPlayerAt(player2, 0));
    assert(gameToTest.getPlayerAt(0).getName() == player1.getName());
    player2.setName("Player 2");
    player2.setType('P');
    assert(gameToTest.setPlayerAt(player2, 1));
    assert(gameToTest.getPlayerAt(1).getName() == player2.getName());
    assert(!gameToTest.setPlayerAt(player2, 20));
    cout << "Asserts passed.\n";

    //Testing loading in items
    gameToTest.loadItemsFromFile("items.txt");
    gameToTest.loadEntitysFromFile("entity.txt");
    vector<Potion> testPotions = gameToTest.getPotions();
    vector<Equipment> testEquip = gameToTest.getEquipment();
    vector<Entity> testEntitys = gameToTest.getEntitys();
    //Should contain same information as all potions in items.txt
    // cout << "Potions:\n";
    // for (int i = 0; i < static_cast<int>(testPotions.size()); i++)
    // {
    //     cout << "| Name: " << testPotions.at(i).name
    //     << " | Description: " << testPotions.at(i).description
    //     << " | Effect: " << testPotions.at(i).effect
    //     << " | Price: " << testPotions.at(i).price
    //     << " | Quantity: " << testPotions.at(i).quantity
    //     << " | Type: " << testPotions.at(i).type << endl;
    // }
    //Should contain same information for all non-potions in items.txt
    // cout << "Equipment:\n";
    // for (int i = 0; i < static_cast<int>(testEquip.size()); i++)
    // {
    //     cout << "| Name: " << testEquip.at(i).name
    //     << " | Description: " << testEquip.at(i).description
    //     << " | Effect: " << testEquip.at(i).effect
    //     << " | Element: " << testEquip.at(i).element
    //     << " | isWeapon: " << testEquip.at(i).isWeapon
    //     << " | Price: " << testEquip.at(i).price << endl;
    // }
    //Should contain same information in entity.txt
    // cout << "Entitys:\n";
    // for (int i = 0; i < static_cast<int>(testEntitys.size()); i++)
    // {
    //     cout << "| Name: " << testEntitys.at(i).getName()
    //     << " | Type: " << testEntitys.at(i).getType()
    //     << " | HP: " << testEntitys.at(i).getHP()
    //     << " | Stamina: " << testEntitys.at(i).getStamina()
    //     << " | Defense: " << testEntitys.at(i).getDefense()
    //     << " | Condition: " << testEntitys.at(i).getCondition()
    //     << " | Advantage: " << testEntitys.at(i).getAdvantage()
    //     << " | Weakness: " << testEntitys.at(i).getElementalWeakness()
    //     << " | Gold: " << testEntitys.at(i).getGold()
    //     << " | Potion: " << testEntitys.at(i).getPotionAt(0).name
    //     << " | Weapon: " << testEntitys.at(i).getSlot(0).name
    //     << " | Num Potions: " << testEntitys.at(i).getPotionAt(0).quantity
    //     << " | Ultimate: " << testEntitys.at(i).getUltimate() << endl;
    // }
    
}