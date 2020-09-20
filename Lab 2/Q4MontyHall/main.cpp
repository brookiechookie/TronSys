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
#include "Host.h"
#include "Player.h"

int main()
{
    Doors   myDoors;
    Player  myPlayer( "UNO" );
    Host    myHost( &myPlayer, &myDoors );


    myHost.StarterQuestion();
    myPlayer.PickDoor();
    myHost.RevealDoor();

}
