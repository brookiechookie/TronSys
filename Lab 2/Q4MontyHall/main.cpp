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

    for( int k = 0; k < NumberOfGames; k++ )
    {
        GameUno.RunGame( Person1Name, 1 );
        GameDue.RunGame( Person2Name, 0 );
    }

    GameUno.AverageScoreReport( NumberOfGames );
    GameDue.AverageScoreReport( NumberOfGames );


}
