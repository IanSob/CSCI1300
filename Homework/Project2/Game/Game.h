#ifndef GAME_CLASS
#define GAME_CLASS

#include "Entity/Entity.h"
#include <vector>
#include <string>

class Game
{
private:
    //Maximum number of players
    static const int MAX_PLAYERS = 2;
    //The players
    Entity players[MAX_PLAYERS];

    //All the possible entities (players and enemies)
    std::vector<Entity> allEntitys;

    //Vector of all potions loaded from file
    std::vector<Potion> allPotions;

    //Vector of all equipment loaded from file
    std::vector<Equipment> allEquipment;
public:
    //Sets the player at the index
    //Returns true if successfull
    bool setPlayerAt(Entity newPlayer, int index);
    //Gets the player at the index. Return default Entity if not found.
    Entity getPlayerAt(int index);

    //Sets the entity at the index
    //Return true if successfully set
    bool setEntityAt(Entity newEntity, int index);
    //Adds entity to the vector
    void addEntity(Entity newEntity);
    //Removes entity at the index
    bool removeEntityAt(int index);
    //Loads the entities from the filename.
    //Returns true if the entity's vector was set (not all values may be set properly if improper text file!)
    //Load items first to prevent problems
    bool loadEntitysFromFile(std::string fileName);
    //Gets the entities vector
    std::vector<Entity> getEntitys();
    //Finds the index of the first entity with the name
    //Returns -1 if could not find
    int findEntityWithName(std::string entityName);

    //Sets the potion at the index
    //Return true if successfully set
    bool setPotionAt(Potion newPotion, int index);
    //Adds a potion to the vector
    void addPotion(Potion newPotion);
    //Removes potion at the index
    bool removePotionAt(int index);
    //Returns the potions vector
    std::vector<Potion> getPotions();
    //Finds the index of the first potion with the name
    //Returns -1 if could not find
    int findPotionWithName(std::string potionName);

    //Sets the Equipment at the index
    //Return true if successfully set
    bool setEquipmentAt(Equipment newEquip, int index);
    //Adds equipment to the vector
    bool addEquipment(Equipment newEquip, int index);
    //Removes the potion at the index
    bool removeEquipmentAt(int index);
    //Gets the equipment vector
    std::vector<Equipment> getEquipment();
    //Finds the index of the first equipment with the name
    //Returns -1 if could not find
    int findEquipmentWithName(std::string equipName);

    //Loads all the items (potions and equipment) from the file
    //Returns true if the file could be opened
    bool loadItemsFromFile(std::string fileName);

    //Initiate combat between the player and enemy.
    //Returns the winner of the combat or default Entity if player ran away successfully.
    Entity combat(int playerIndex, int enemyIndex);

    //Prompts the user to shop from randomly selected items from the equipment and potions array
    //Number of selection is the number of items selectable for the player
    void shop(int playerID, int numberOfSelection);
};

#endif