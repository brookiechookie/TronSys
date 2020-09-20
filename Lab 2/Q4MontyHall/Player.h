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
        //Player( Host* WhichHost );
        void PickDoor();        // Player chooses a door
        //void PlayerWhoStays();    // Player who stays with their decision of doors
        //void PlayerWhoSwitches();
        int PickedDoorGetter();
        std::string NameGetter();
        //void SetHost( Host* WhichHost );

    private:
        std::string _PlayerName;
        int _PickedDoor;


};


#endif
