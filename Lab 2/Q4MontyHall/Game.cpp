// Game.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Game.h"

//------------------------------------------------------------------------------
// This function essentially runs the whole game. The two configurable aspects
// of this function is the players name and whether they decide to stay or switch.
// NB: an int action of 1 = a switcher, whilst 0 = stayer.
void Game::RunGame( std::string Name, int action )
{
    // Create separation between each game. Instantiate new objects of the class
    std::cout << "-----------------------New Game---------------------" << std::endl;
    Doors   myDoors;
    Player  myPlayer( Name );
    Host    myHost( &myPlayer );

    _ThePlayerName = Name;

    // Start the game off
    myHost.TryingToGetDoors( &myDoors );
    myHost.StarterQuestion();
    myPlayer.PickDoor();
    myHost.RevealDoor();

    // Allow the player to see what the option is to switch doors
    int _TheDoorSwitcher = 0;
    _TheDoorSwitcher = myHost.DoorSwitchGetter();
    myPlayer.SetSwitchDoorNumber( _TheDoorSwitcher );

    // Now allow the player to switch or stay. NB: an int of 1 = a switcher,
    // whilst 0 = stayer.
    if( action == 1)
    {
        myPlayer.PlayerWhoSwitches();
    }
    else if( action == 0 )
    {
        myPlayer.PlayerWhoStays();
    }

    // Tell the player whether they have won or not
    _Outcome = myHost.WinOrLose();
    //std::cout << "_Outcome in Game class has the value " << _Outcome << std::endl;

    _TotalScore = _TotalScore + _Outcome;

}


//------------------------------------------------------------------------------
// This function calculates the average success rate of a player in the game. It
// requires the input of the number of games being played and will output the
// success rate as a percentage
double Game::AverageScoreReport( int NumberOfGames )
{
    //std::cout << "Total score = " << _TotalScore << "\nGamesPlayed = " << NumberOfGames << std::endl;
    _AverageScore = ( double(_TotalScore) / double(NumberOfGames) ) * 100;

    std::cout << "\n**************FINAL REPORT**************\n[Report]: Report on Player " <<
    _ThePlayerName << "\n[Report]: Total Games Played = " << NumberOfGames <<
    "\n[Report]: Total Games won " << _TotalScore << "\n[Report]:" <<
    _ThePlayerName << "'s average score = " << _AverageScore << "%"<< std::endl;

}
