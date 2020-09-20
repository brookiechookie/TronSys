// Doors.h
//
// Header file for the derived speaker class: Italian

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <string>

//#include "Host.h"
//#include "Doors.h"


class Player
{
    public:
        Player( std::string Name );
        void PickDoor();            // Player chooses a door
        void PlayerWhoStays();    // Player who stays with their decision of doors
        void PlayerWhoSwitches();
        int PickedDoorGetter();
        std::string NameGetter();
        void SetSwitchDoorNumber( int s );
        int DoorSelectionGetter();

    private:
        std::string _PlayerName;
        int _PickedDoor;
        int _SwitchDoorNumber;
        int _DoorSelection;
        int _NumberOfDoors = 3;


};


#endif
