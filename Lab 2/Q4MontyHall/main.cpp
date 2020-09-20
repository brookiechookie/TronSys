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
    //Host    myHost( &myPlayer, &myDoors );
    Host  myHost( &myPlayer );
    //myHost.Init( &myPlayer, &myDoors );

    myHost.TryingToGetDoors( &myDoors );

/*
    myHost.StarterQuestion();
    myPlayer.PickDoor();
    myHost.RevealDoor();
*/

    //int p;
    //p = myDoors.DoorsGetter();


}
