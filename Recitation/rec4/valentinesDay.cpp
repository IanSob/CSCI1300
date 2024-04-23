#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double calculateVolumeOfSphericalCandy(double radius);
double calculateVolumeOfHeartCandy(double radius);

int main()
{
    assert(calculateVolumeOfHeartCandy(-1) == 0);
    assert(calculateVolumeOfHeartCandy(3) == 27.0 * (M_PI + 4.0 * sqrt(3)));
    assert(calculateVolumeOfSphericalCandy(0) == 0);
    assert(calculateVolumeOfSphericalCandy(5) == (500.0/3.0) * M_PI);

    cout << "All asserts verified!" << endl;
    return 0;
}


/**
* @brief Function to determine the volume of a heart-shaped candy using a radius
* @param radius of the semicircles of heart-shaped candy
* @return double - volume of heart-shaped candy
*/
double calculateVolumeOfHeartCandy(double radius)
{
    if(radius <= 0)
    {
        return 0;
    }

    return (M_PI + 4.0 * sqrt(3.0)) * pow(radius, 3.0);
}

/**
* @brief Function to determine the volume of a spherical candy using its radius
* @param radius of the spherical candy
* @return double - volume of spherical candy
*/
double calculateVolumeOfSphericalCandy(double radius)
{
    if(radius <= 0)
    {
        return 0;
    }

    return (4.0/3.0) * pow(radius, 3.0) * M_PI;
}