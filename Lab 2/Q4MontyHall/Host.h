// Doors.h
//
// Header file for the derived speaker class: Italian

#ifndef _HOST_H
#define _HOST_H

//#include "Speaker.h"
#include "Player.h"
#include "Doors.h"

class Host
{
    public:
        Host( Player* WhichPlayer, Doors* WhichDoor );
        void StarterQuestion();   // What door would you like to pick?
        void RevealDoor();        // The car is not behind THIS door. Do you want to stay or switch doors?
        void Answer();            // Tell the player whether they are right or wrong

    private:
        Player* _Player;
        Doors* _Doors;
        std::string _LePlayerName;
        int _PlayerDoorPicked;
        int *StoredDoors;

};

#endif
