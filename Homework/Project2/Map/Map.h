#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>

using namespace std;

class Map
{
private:
    //Number of players
    static const int NUM_PLAYERS = 2;

    //The number of tiles for each player
    static const int NUM_TILES = 50;
    
    //The map represented as string
    string mapArr[NUM_PLAYERS][NUM_TILES];
public:
    // Constructor
    Map();

    //Sets the value of the map at the index
    bool setMapAt(string value, int playerID, int index);

    //Gets the map at the playerID row and index collum
    //Empty string if invalid inputs
    string getMapAt(int playerID, int index);

    //Initializes the map with random values
    void initializeMap();
};

#endif