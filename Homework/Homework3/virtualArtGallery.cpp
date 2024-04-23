// CSCI 1300 Spring 2024
// Author: Ian Sobiech
// TA: Mohammed Adib Oumer
// Question 2

#include <iostream>
#include <string>
using namespace std;



int main()
{
    int style;
    int artist;
    int artwork;

    cout << "Select the Style: (1) Impressionism (2) Surrealism\n";
    cin >> style;

    if(style == 1)
    {
        cout << "Select the Artist: (1) Claude Monet (2) Edgar Degas (3) Pierre-Auguste Renoir\n";
        cin >> artist;

        if(artist == 1)
        {
            cout << "Select the Artwork: (1) Water Lilies (2) Impression, Sunrise\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: Water Lilies";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: Impression, Sunrise";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else if(artist == 2)
        {
            cout << "Select the Artwork: (1) The Dance Class (2) L'Absinthe\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: The Dance Class";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: L'Absinthe";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else if(artist == 3)
        {
            cout << "Select the Artwork: (1) Luncheon of the Boating Party (2) Bal du moulin de la Galette\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: Luncheon of the Boating Party";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: Bal du moulin de la Galette";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    else if(style == 2)
    {
        cout << "Select the Artist: (1) Salvador Dali (2) Rena Magritte (3) Frida Kahlo\n";
        cin >> artist;

        if(artist == 1)
        {
            cout << "Select the Artwork: (1) The Persistence of Memory (2) The Elephant\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: The Persistence of Memory";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: The Elephant";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else if(artist == 2)
        {
            cout << "Select the Artwork: (1) The Son of Man (2) The Treachery of Images\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: The Son of Man";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: The Treachery of Images";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else if(artist == 3)
        {
            cout << "Select the Artwork: (1) The Two Fridas (2) Self-Portrait with Thorn Necklace\n";
            cin >> artwork;
            if(artwork == 1)
            {
                cout << "You have reserved the artwork: The Two Fridas";
            }
            else if(artwork == 2)
            {
                cout << "You have reserved the artwork: Self-Portrait with Thorn Necklace";
            }
            else
            {
                cout << "Please enter a valid input." << endl;
            }
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    else
    {
        cout << "Please enter a valid input." << endl;
    }

    return 0;
}