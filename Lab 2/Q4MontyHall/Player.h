// Player.h
//
// Header file for the class: Player

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <string>

class Player
{
    public:
        Player( std::string Name );
        //int UserPickedDoorSetter( int UserPickedDoor );   // User chooses a door for the player
        void PlayerWhoStays();        // Player who stays with their decision of doors
        void PlayerWhoSwitches();     // Player who switches with their decision of doors
        int PickedDoorGetter();
        void PickDoor();
        std::string NameGetter();
        void SetSwitchDoorNumber( int s );
        int DoorSelectionGetter();

    protected:                    // These variables must be protected and not private
        std::string _PlayerName;  // so that the derived classes can have access to them
        int _PickedDoor;
        int _SwitchDoorNumber;
        int _DoorSelection;
        int _NumberOfDoors = 4;

};


#endif
