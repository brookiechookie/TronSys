// Host.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Host.h"
#include "Doors.h"

/*
//------------------------------------------------------------------------------
// This is the constructor for host which draws information from other classes
Host::Host( Player* WhichPlayer, Doors* WhichDoor )
{
    _Player = WhichPlayer;
    _LePlayerName = _Player->NameGetter();

    _Doors = WhichDoor;

}
*/

Host::Host( Player* WhichPlayer )
{
    //std::cout << "[Host]: Infiltrated" << std::endl;

    _Player = WhichPlayer;
    _LePlayerName = _Player->NameGetter();

}

void Host::TryingToGetDoors( Doors* WhichDoors )
{
    //std::cout << "More Infiltration" << std::endl;
    _Doors = WhichDoors;
}


//------------------------------------------------------------------------------
// This is a function that contains the hosts initial question to be asked
void Host::StarterQuestion()
{
    // We want the host to ask the player which door they would like to open
    std::cout << "[Host]: Player "<< _LePlayerName << ", which door would you like to open?" << std::endl;
}

//------------------------------------------------------------------------------
// This is a function that figures out which door to reveal based on which door
// the player has picked and which door has the car behind it. It also figures
// out which door the person has the option to switch to
void Host::RevealDoor()
{
    // The host has to know which door the player has picked and choose one of
    // doors with a goat and reveal this door.
    _PlayerDoorPicked = _Player->PickedDoorGetter();
    _NumberOfDoors = _Doors->NumOfDoorsGetter();
    _CarDoor = _Doors->CarDoorGetter();

    std::cout << "[Host]: Player " << _LePlayerName << " has picked door " << _PlayerDoorPicked << std::endl;

    // 1. Host needs to see the doors and whats behind them
    StoredDoors = _Doors->DoorsGetter();

    // Now display whats at the doors...?
    std::cout << "[Host]: First, second, third elements in StoredDoors: " << StoredDoors[0] << ", " <<
    StoredDoors[1] << " and  "<< StoredDoors[2] << std::endl;


    // 2. Time to eliminate a door by revealing one with a goat behind it
    for( int i = 0; i < _NumberOfDoors; i++ )
    {
        if( StoredDoors[i] != 1 && i != _PlayerDoorPicked )
        {
            _DoorToBeRevealed = i;
        }

    }

    // 3. Find the door that the player can switch to
    for( int i = 0; i < _NumberOfDoors; i++ )
    {
        if( i != _DoorToBeRevealed && i != _PlayerDoorPicked )
        {
            _DoorSwitchPotential = i;
        }
    }

    // 4. Now reveal this door to the contest
    std::cout << "[Host]: The host is revealing that door " << _DoorToBeRevealed <<
    " contains a goat. Player " << _LePlayerName << " would you like to stay with door " <<
    _PlayerDoorPicked << " or would you like to switch to door " << _DoorSwitchPotential << "?"<< std::endl;

}

//------------------------------------------------------------------------------
// This is a getter function which returns the door that the player can potentially
// switch to
int Host::DoorSwitchGetter()
{
    return _DoorSwitchPotential;
}
