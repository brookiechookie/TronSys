// Game.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Game.h"


void Game::RunGame( std::string Name, int action )
{
    std::cout << "-----------------------New Game---------------------" << std::endl;
    Doors   myDoors;
    Player  myPlayer( Name );
    Host    myHost( &myPlayer );

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
    myHost.WinOrLose();

}
