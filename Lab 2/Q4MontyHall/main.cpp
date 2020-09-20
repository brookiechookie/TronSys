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
    Game  myGame;
    myGame.RunGame( "Molly", 1 );

    Game  newGame;
    newGame.RunGame( "Puval", 0 );




    /*
    std::cout << "--------------------------------New Game--------------------------------" << std::endl;
    Doors   myDoors;
    Player  myPlayer( "Stayer" );
    Host    myHost( &myPlayer );
    */

    /*
    // Start the game off
    myHost.TryingToGetDoors( &myDoors );
    myHost.StarterQuestion();
    myPlayer.PickDoor();
    myHost.RevealDoor();

    // Allow the player to see what the option is to switch doors
    int _TheDoorSwitcher;
    _TheDoorSwitcher = myHost.DoorSwitchGetter();
    myPlayer.SetSwitchDoorNumber( _TheDoorSwitcher );

    // Now allow the player to switch or stay and tell them whether they have
    // won or not
    //myPlayer.PlayerWhoSwitches();
    myPlayer.PlayerWhoStays();
    myHost.WinOrLose();
    */
//------------------------------------------------------------------------------

    /*
    std::cout << "--------------------------------New Game--------------------------------" << std::endl;
    Doors   Doors2;
    Player  Player2( "Switcher" );
    Host    Host2( &Player2 );

    // Start the game off
    Host2.TryingToGetDoors( &Doors2 );
    Host2.StarterQuestion();
    Player2.PickDoor();
    Host2.RevealDoor();

    // Allow the player to see what the option is to switch doors
    int _TheDoorSwitcher2;
    _TheDoorSwitcher2 = Host2.DoorSwitchGetter();
    Player2.SetSwitchDoorNumber( _TheDoorSwitcher2 );

    // Now allow the player to switch or stay and tell them whether they have
    // won or not
    Player2.PlayerWhoSwitches();
    //myPlayer.PlayerWhoStays();
    Host2.WinOrLose();

    */



}
