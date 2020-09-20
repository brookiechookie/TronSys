// Doors.cpp
//
// Implementation file for the class: Doors



#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>    // For rand()

#include "Doors.h"

//------------------------------------------------------------------------------
// This is the constructor for Doors. This creates the doors with goats behind
// them and a car
Doors::Doors()
{
    // Assign the car behind a random door between the numbers of 0 to however
    // many doors there are.
    _CarDoor = rand() % _NumberOfDoors ;

    // Assign zeros to all the doors (i.e. goats)
    for(int i = 0; i < _NumberOfDoors; i++)
    {
        pDoors[i] = 0;
    }

    // In one of the doors, assign a one (i.e. the car)
    pDoors[_CarDoor] = 1;

}

//------------------------------------------------------------------------------
// This function is to return the array of doors and what is behind them
int* Doors::DoorsGetter()
{
    return pDoors;
}


//------------------------------------------------------------------------------
// This is a getter function which returns the number of doors in the game
int Doors::NumOfDoorsGetter()
{
    return _NumberOfDoors;
}

//------------------------------------------------------------------------------
// This is a getter function which returns the door that contains the car behind it
int Doors::CarDoorGetter()
{
    return _CarDoor;
}
