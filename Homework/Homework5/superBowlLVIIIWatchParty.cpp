#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double distance2D(double x1, double y1, double x2, double y2);
void findClosestCity(double distance[][3], int closest_cities[],  const int DISTANCE_ROWS,  const int DISTANCE_COLS);
void calculateDistanceMatrix(double distance[][3], double individual_locations[][2], double city_locations[][2], const int I_ROWS,  const int I_COLS,  const int C_ROWS,  const int C_COLS);

int main()
{
    const int DISTANCE_ROWS = 4;
    const int DISTANCE_COLS = 3;
    double distance[DISTANCE_ROWS][DISTANCE_COLS] = {{1.41, 5.10, 7.62}, {1.41, 3.16, 5.83}, {3.61, 2.24, 4.12}, {7.21, 2.83, 0.00}};
    int closest_cities[DISTANCE_ROWS];
    findClosestCity(distance, closest_cities, DISTANCE_ROWS, DISTANCE_COLS);

    // We are printing the contents of the closest_cities array here.
    for (int i = 0; i < DISTANCE_ROWS; i++)
    {
        cout << closest_cities[i] << endl;
    }
    return 0;
}

void findClosestCity(double distance[][3], int closest_cities[],  const int DISTANCE_ROWS,  const int DISTANCE_COLS)
{
    //For every person
    for (int i = 0; i < DISTANCE_ROWS; i++)
    {
        int closestCity = 0;
        //Current smallest distance for the person
        double smallestDistance = distance[i][0];

        for (int j = 0; j < DISTANCE_COLS; j++)
        {
            if(distance[i][j] < smallestDistance)
            {
                smallestDistance = distance[i][j];
                closestCity = j;
            }
        }
        
        //Convert from 0 -> #ofcitys - 1 to 1 -> #ofcitys
        closest_cities[i] = closestCity + 1;
    }
}

void calculateDistanceMatrix(double distance[][3], double individual_locations[][2], double city_locations[][2], const int I_ROWS,  const int I_COLS,  const int C_ROWS,  const int C_COLS)
{
    //For every person's location
    for (int i = 0; i < I_ROWS; i++)
    {
        //For every city's location
        for (int j = 0; j < C_ROWS; j++)
        {
            distance[i][j] = distance2D(individual_locations[i][0], individual_locations[i][1], city_locations[j][0], city_locations[j][1]);
        }  
    } 
}

//Finds the distance between (x1,y1) and (x2,y2)
double distance2D(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
}