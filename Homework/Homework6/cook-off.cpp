// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readIngredients(string filename, string ingredients[], const int MAX_INGREDIENTS);
int compareIngredients(string original_ingredients[], string friend_ingredients[], int original_ingredients_size, int friend_ingredients_size, string missing_ingredients[]);

int main()
{
    const int MAX_INGREDIENTS = 20;

    string original_ingredients[MAX_INGREDIENTS] = {"Salt",
                                             "Pepper",
                                             "Ginger",
                                             "Honey",
                                             "Rice",
                                             "Chicken",
                                             "Ginger"};

    string friend_ingredients[MAX_INGREDIENTS] = {"Ginger",
                                             "Pepper",
                                             "Chicken",
                                             "Rice"};

    string missing_ingredients[MAX_INGREDIENTS];

    int original_ingredients_size = 6;
    int friend_ingredients_size = 4;

    int missing_ingredients_size = compareIngredients(original_ingredients,
                                                      friend_ingredients,
                                                      original_ingredients_size,
                                                      friend_ingredients_size,
                                                      missing_ingredients);

    cout << "The missing ingredients are:" << endl;
    for (int i = 0; i < missing_ingredients_size; i++) {
      cout << missing_ingredients[i] << endl;
    }

    cout << "The number of missing ingredients is: " << missing_ingredients_size << endl;

    return 0;
}

int readIngredients(string filename, string ingredients[], const int MAX_INGREDIENTS)
{
    ifstream ingredientList(filename);

    //When not opened
    if(!ingredientList.is_open())
    {
        return -1;
    }

    //Variables for loop
    string ingredientsOnLine;
    int numberOfPopulations = 0;

    while (getline(ingredientList, ingredientsOnLine))
    {
        ingredients[numberOfPopulations] = ingredientsOnLine;
        numberOfPopulations++;

        if(numberOfPopulations >= MAX_INGREDIENTS)
        {
            return MAX_INGREDIENTS;
        }
    }

    return numberOfPopulations;  
}

int compareIngredients(string original_ingredients[], string friend_ingredients[], int original_ingredients_size, int friend_ingredients_size, string missing_ingredients[])
{
    int missingIngredientSize = 0;

    for (int i = 0; i < original_ingredients_size; i++)
    {
        bool foundIngredient = false;
        for (int j = 0; j < friend_ingredients_size; j++)
        {
            if(original_ingredients[i] == friend_ingredients[j])
            {
                foundIngredient = true;
                break;
            }
        }

        if(!foundIngredient)
        {
            bool alreadyContainsIngredient = false;

            //Make sure to not add any duplicates (I think this is part of the error handling?)
            for (int t = 0; t < missingIngredientSize; t++)
            {
                if(missing_ingredients[t] == original_ingredients[i])
                {
                    alreadyContainsIngredient = true;
                    break;
                }
            }
            
            if(!alreadyContainsIngredient)
            {
                missing_ingredients[missingIngredientSize] = original_ingredients[i];
                missingIngredientSize++;
            }
        }
    }
    
    return missingIngredientSize;
}