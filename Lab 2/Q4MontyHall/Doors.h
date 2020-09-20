// Doors.h
//
// Header file for the derived speaker class: Italian

#ifndef _DOORS_H
#define _DOORS_H

//#include "Speaker.h"
class Doors
{
    public:
        Doors();
        int DoorsGetter();

    private:
        //Doors* pDoors;   // Create a pointer to pointer to store info about the doors
        int _NumberOfDoors;
        int _CarDoor;
        int pDoors[];

};


#endif
