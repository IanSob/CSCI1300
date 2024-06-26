#include "Map.h"

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

Map::Map()
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        for (int j = 0; j < NUM_TILES; j++)
        {
            mapArr[i][j] = "";
        }
    }
}

// setter for position on map given the value and which player and then the index for their lane
bool Map::setMapAt(string value, int playerID, int index)
{
    if((playerID >= 0 && playerID < NUM_PLAYERS) && (index >= 0 && index < NUM_TILES))
    {
        mapArr[playerID][index] = value;
        return true;
    }
    return false;
}

// getter for position on map given which player and then the index for their lane
string Map::getMapAt(int playerID, int index)
{
    if(playerID >= 0 && playerID < NUM_PLAYERS && index >= 0 && index < NUM_TILES)
    {
        return mapArr[playerID][index];
    }

    return "";
}

//Should initialize map with random tiles.
//Tile %s are defined by the github
//This should run twice for each player so they bothe have the same tile spread %-wise
void Map::initializeMap(){

    // variables to hold random numbers
    int rand_num1, rand_num2;

    for (int i = 0; i < 50; i++){
        /* generate secret number between 1 and 10: */
        rand_num1 = rand() % 10 + 1;
        rand_num2 = rand() % 10 + 1;

        // These conditions roughly set probability for red, green, and blue tiles to roughly 1/3ish
        // STUDENTS: You must alter these to get correct ratios of the tiles that you need
        // Remember, the map is ALWAYS randomized at the start of a new game!!!!
        if (rand_num1 <= 3)
        {
            // Keep in mind, I told the compiler that writing the word RED represents the string "\033[41m"
            mapArr[0][i] = RED;
        }
        else if (rand_num1 <=6){
            // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[42m"
            mapArr[0][i] = GREEN;
        }
        else{
            // Keep in mind, I told the compiler that writing the word GREEN represents the string "\033[44m"
            mapArr[0][i] = BLUE;
        }

        // This part populates the other lane for the second player
        if (rand_num2 <= 3){
            mapArr[1][i] = RED;
        }
        else if (rand_num2 <=6){

            mapArr[1][i] = GREEN;
        }
        else{
            mapArr[1][i] = BLUE;
        }
    }
}