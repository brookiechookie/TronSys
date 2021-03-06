// Doors.h
//
// Header file for the class: Doors

#ifndef _DOORS_H
#define _DOORS_H

#include <iostream>
#include <stdlib.h>
#include <string>


class Doors
{
    public:
        Doors();
        int* DoorsGetter();     // This getter function returns a pointer to an array
        int NumOfDoorsGetter();
        int CarDoorGetter();

    private:
        //Doors* pDoors;        // Create a pointer to pointer to store info about the doors
        int _random;
        int _CarDoor;
        int _NumberOfDoors = 4;
        int pDoors[4];

};


#endif
