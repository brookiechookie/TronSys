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
    Doors   myDoors;
    Player  myPlayer( "UNO" );
    Host  myHost( &myPlayer );

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


    //int p;
    //p = myDoors.DoorsGetter();


}
