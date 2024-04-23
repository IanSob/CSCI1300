#include "Game.h"
#include <fstream>
#include "Function Library/PRJCT2FunLib.h"

using namespace std;

bool Game::setPlayerAt(Entity newPlayer, int index)
{
    if(index >= 0 && index < MAX_PLAYERS && newPlayer.getType() == 'P')
    {
        players[index] = newPlayer;
        return true;
    }

    return false;
}

Entity Game::getPlayerAt(int index)
{
    if(index >= 0 && index < MAX_PLAYERS)
    {
        return players[index];
    }

    return Entity();
}

bool Game::setEntityAt(Entity newEntity, int index)
{
    if(index >= 0 && index < static_cast<int>(allEntitys.size()))
    {
        allEntitys.at(index) = newEntity;
    }

    return false;
}

void Game::addEntity(Entity newEntity)
{
    allEntitys.push_back(newEntity);
}

bool Game::removeEntityAt(int index)
{
    vector<Entity> newEntitys; 
    if(index >= 0 && index < static_cast<int>(allEntitys.size()))
    {
        for (int i = 0; i < static_cast<int>(allEntitys.size()); i++)
        {
            if(i != index)
            {
                newEntitys.push_back(allEntitys.at(i));
            }
        }
        
        allEntitys = newEntitys;
        return true;
    }

    return false;
}


bool Game::loadEntitysFromFile(string fileName)
{
    ifstream inputFile(fileName);
    //Temporary entity vector that will be used if all the values are useable
    vector<Entity> tempEntitys;

    if(inputFile.is_open())
    {
        string currentLine;
        vector<string> splitLine;

        //Skip the first line
        getline(inputFile, currentLine);

        //For each line
        while(getline(inputFile, currentLine))
        {
            splitLine = project2Library::split(currentLine, '|');
            Entity newEntity;

            if(splitLine.size() != 12)
            {
                break;
            }

            newEntity.setName(splitLine.at(0));//Name
            newEntity.setType(splitLine.at(1)[0]);//Type
            newEntity.setHP(stod(splitLine.at(2)));//HP
            newEntity.setStamina(stod(splitLine.at(3)));//Stamina
            newEntity.setDefense(stod(splitLine.at(4)));//Defense
            newEntity.setCondition(splitLine.at(5)[0]);//Condition
            //Only set to true if the value says true
            newEntity.setAdvantage(splitLine.at(6) == "True" ? true : false);//Advantage
            newEntity.setElementalWeakness(splitLine.at(7)[0]);//Elemental Weakness
            newEntity.setGold(stoi(splitLine.at(8)));//Gold

            //Setting the items
            //Creates a vector with the listed items
            vector<string> splitItems = project2Library::split(splitLine.at(9), ',');
            //Used for setting
            int foundIndex = findPotionWithName(splitItems[0]);
            if(foundIndex != -1)
            {
                Potion newPotion = allPotions.at(foundIndex);
                //Set the quantity to the new values
                newPotion.quantity = stoi(project2Library::split(splitLine.at(10), ',').at(0));
                newEntity.setPotionAt(newPotion, 0);
            }
            //Starting equipment
            foundIndex = findEquipmentWithName(splitItems[1]);
            if(foundIndex != -1)
            {
                newEntity.changeSlot(0, allEquipment.at(foundIndex));
            }
            
            newEntity.setUltimate(splitLine.at(11));

            addEntity(newEntity);
        }
    }

    return false;
}

vector<Entity> Game::getEntitys()
{
    return allEntitys;
}

int Game::findEntityWithName(std::string entityName)
{
    for (int i = 0; i < static_cast<int>(allEntitys.size()); i++)
    {
        if(allEntitys.at(i).getName() == entityName)
        {
            return i;
        }
    }
    
    return -1;
}

bool Game::setPotionAt(Potion newPotion, int index)
{
    if(index >= 0 && index < static_cast<int>(allPotions.size()))
    {
        allPotions[index] = newPotion;
        return true;
    }

    return false;
}

void Game::addPotion(Potion newPotion)
{
    allPotions.push_back(newPotion);
}

bool Game::removePotionAt(int index)
{
    vector<Potion> newPotions; 
    if(index >= 0 && index < static_cast<int>(allPotions.size()))
    {
        for (int i = 0; i < static_cast<int>(allPotions.size()); i++)
        {
            if(i != index)
            {
                newPotions.push_back(allPotions.at(i));
            }
        }
        
        allPotions = newPotions;
        return true;
    }

    return false;
}

vector<Potion> Game::getPotions()
{
    return allPotions;
}

int Game::findPotionWithName(string potionName)
{
    for (int i = 0; i < static_cast<int>(allPotions.size()); i++)
    {
        if(allPotions.at(i).name == potionName)
        {
            return i;
        }
    }
    
    return -1;
}

bool Game::setEquipmentAt(Equipment newEquip, int index)
{
    if(index >= 0 && index < static_cast<int>(allEquipment.size()))
    {
        allEquipment[index] = newEquip;
        return true;
    }

    return false;
}

std::vector<Equipment> Game::getEquipment()
{
    return allEquipment;
}

int Game::findEquipmentWithName(string equipName)
{
    for (int i = 0; i < static_cast<int>(allEquipment.size()); i++)
    {
        if(allEquipment.at(i).name == equipName)
        {
            return i;
        }
    }
    
    return -1;
}

bool Game::loadItemsFromFile(string fileName)
{
    ifstream inputFile(fileName);

    if(inputFile.is_open())
    {
        string currentLine;
        vector<string> splitLine;
        vector<Potion> newPotions;
        vector<Equipment> newEquips;

        //Skip first line
        getline(inputFile, currentLine);

        while (getline(inputFile, currentLine))
        {
            splitLine = project2Library::split(currentLine, '|');

            if(splitLine.size() != 6)
            {
                continue;
            }

            //Attack equipment
            if(splitLine.at(2)[0] == 'W')
            {
                newEquips.push_back
                (
                    Equipment(
                    splitLine.at(0), //Name
                    splitLine.at(1), //Description
                    true, //IsWeapon
                    splitLine.at(4)[0], //Element
                    stod(splitLine.at(3)), //Effectiveness
                    stod(splitLine.at(5)) //Price
                    )
                );
            }
            else if(splitLine.at(2)[0] == 'B') //Shield
            {
                newEquips.push_back
                (
                    Equipment(
                    splitLine.at(0), //Name
                    splitLine.at(1), //Description
                    false, //IsWeapon
                    splitLine.at(4)[0], //Element
                    stod(splitLine.at(3)), //Effectiveness
                    stod(splitLine.at(5)) //Price
                    )
                );
            }
            else
            {
                newPotions.push_back
                (
                    Potion(
                    splitLine.at(0), //Name
                    splitLine.at(1), //Description
                    splitLine.at(2)[0], //Type
                    stod(splitLine.at(3)), //Effect
                    stod(splitLine.at(5)), //Price
                    1 //Quantity
                    )
                );
            }
        }

        allEquipment = newEquips;
        allPotions = newPotions;
        return true;
    }

    return false;
}

//Should start combat between the player and Entity at respective index's
//It should be prompting for moves from player and giving information on stats.
//When the function finishes: It should return the winner of the fight or default Entity for running away / failure
Entity Game::combat(int playerIndex, int enemyIndex)
{
    return Entity();
}

//Should show shop items and allow player to buy for inventory
//Should also allow swapping if inventory is full
//Items in shop are generated from the allPotions and allEquipment vectors with the total items being numberOfSelection
void Game::shop(int playerID, int numberOfSelection)
{

}