// Doors.h
//
// Header file for the derived speaker class: Italian

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <string>

class Player
{
    public:
        Player( std::string Name );
        void PickDoor();        // Player chooses a door
        void StayOrSwitch();    // Player decides whether they want to stick or switch doors
        int PickedDoorGetter();
        std::string NameGetter();

    private:
        std::string _PlayerName;
        int _PickedDoor;

};


#endif
