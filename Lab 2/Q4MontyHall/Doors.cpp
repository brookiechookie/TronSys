// Doors.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>
//#include <cstdlib>    // For rand()

#include "Doors.h"

//------------------------------------------------------------------------------
// This is the constructor for Doors. This creates the doors with goats behind
// them and a car
Doors::Doors()
{
    // Assign the car behind a door

    _CarDoor = 1;

    // Assign zeros to all the doors (i.e. goats)
    for(int i = 0; i < _NumberOfDoors; i++)
    {
        pDoors[i] = 0;
    }

    // In one of the doors, assign a one (i.e. the car)
    pDoors[_CarDoor] = 1;


    // See whats behind all the doors
    for(int i = 0; i < _NumberOfDoors; i++)
    {
        std::cout << "[Doors]: The value at door " << i << " is " << pDoors[i] << std::endl;
    }

}

//------------------------------------------------------------------------------
// This function is to return the array of doors and what is behind them
int* Doors::DoorsGetter()
{
    /*
    std::cout << "The address of pDoors is " << pDoors << ". The first element can be expressed as: " <<
    *pDoors << ", or " << pDoors[0] << std::endl;

    std::cout << "[Doors]: First, second, third elements in StoredDoors: " << pDoors[0] << ", " <<
    pDoors[1] << " and  "<< pDoors[2] << std::endl;
    */

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
