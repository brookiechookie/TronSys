// Doors.h
//
// Header file for the derived speaker class: Italian

#ifndef _HOST_H
#define _HOST_H

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Player.h"
#include "Doors.h"

class Host
{
    public:
        //Host( Player* WhichPlayer, Doors* WhichDoor );
        Host( Player* WhichPlayer );
        void StarterQuestion();   // What door would you like to pick?
        void RevealDoor();        // The car is not behind THIS door. Do you want to stay or switch doors?
        void Answer();            // Tell the player whether they are right or wrong
        int DoorSwitchGetter();
        void TryingToGetDoors( Doors* WhichDoors );
        int WinOrLose();


    private:
        //Doors* _TheDoors;
        //Player* _Player;
        //Doors* _Doors;
        Player* _Player;

        Doors* _Doors;

        std::string _LePlayerName;
        int _PlayerDoorPicked;
        int *StoredDoors;         // A pointer to the doors storing whats behind each door!
        int _NumberOfDoors;
        int _CarDoor;             // Represents the door with the car
        int _DoorToBeRevealed;
        int _DoorSwitchPotential;
        int _PlayerDoorSelectV2;
        int _PlayerOutcome;

};

#endif
