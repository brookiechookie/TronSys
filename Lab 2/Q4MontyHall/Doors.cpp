// Doors.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Doors.h"


Doors::Doors()
{
    _NumberOfDoors = 3;
    _CarDoor = 1;

    // Three doors should be made as an array and with a pointer accessing the array
    //int* pDoors  = new int[_NumberOfDoors];
    pDoors[_NumberOfDoors];

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
        std::cout << "The value at door " << i << " is " << pDoors[i] << std::endl;
    }

}

//------------------------------------------------------------------------------
// This function is to return the array of doors and what is behind them
int Doors::DoorsGetter()
{
    std::cout << "The address of pDoors is " << pDoors <<
    ". The first element in pDoors is " << pDoors[0] << std::endl;
    return *pDoors;
}
