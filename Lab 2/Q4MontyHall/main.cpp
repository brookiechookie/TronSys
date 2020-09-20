/*
main.cpp

Creator:        Brooke Agostino
Date created:   19/9/20
Purpose:        Question 4 of lab 2; The Monty Hall Problem

Modifications:
*/

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Doors.h"
#include "Game.h"
#include "Player.h"
#include "Host.h"


int main()
{
    // All that the game class has to know is the name of the player and whether
    // they are a stayer or a switcher
    Game  GameUno;
    Game  GameDue;
    std::string Person1Name = "Switcher";
    std::string Person2Name = "Stayer";

    // Variables defining the game
    int NumberOfGames = 10000;
    double AverageScore;
    int PersonScore;

    // Get a door from the user
    int _UserSelectedDoor1;
    int _UserSelectedDoor2;

    // Prompt the user to select doors for both the players
    std::cout << "Hi User! Please select a door for " << Person1Name << " and for " <<
    Person2Name << ".\nNB: The program is set to 4 doors so your door selection must be between 0-3."<< std::endl;
    std::cin >> _UserSelectedDoor1 >> _UserSelectedDoor2;

    // Run the game a certain number of times
    for( int k = 0; k < NumberOfGames; k++ )
    {
        GameUno.RunGame( Person1Name, 1, _UserSelectedDoor1 );
        GameDue.RunGame( Person2Name, 0, _UserSelectedDoor2 );
    }

    // Report the stats of each player to the user at the end of the cycles
    GameUno.AverageScoreReport( NumberOfGames );
    GameDue.AverageScoreReport( NumberOfGames );

}
