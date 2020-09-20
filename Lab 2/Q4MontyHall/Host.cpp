// Host.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Host.h"
#include "Player.h"

Host::Host( Player* WhichPlayer, Doors* WhichDoor )
{
    _Player = WhichPlayer;
    _LePlayerName = _Player->NameGetter();

    _Doors = WhichDoor;
    //StoredDoors = _Doors->DoorsGetter();

}


void Host::StarterQuestion()
{
    // We want the host to ask the player which door they would like to open
    std::cout << "[Host]: Player "<< _LePlayerName << ", which door would you like to open?" << std::endl;
}

void Host::RevealDoor()
{
    // The host has to know which door the player has picked and choose one of
    // doors with a goat and reveal this door.
    _PlayerDoorPicked = _Player->PickedDoorGetter();
    std::cout << "[Host]: Player " << _LePlayerName << " has picked door " << _PlayerDoorPicked << std::endl;

    // The host must eliminate one of the Doors
    // If the player has picked a door with a goat, the host must reveal the other
    // door with the goat
    // If the player has picked the door with the car, the host can reveal either
    // of the two remaining doors.

    // 1. Host needs to see the doors and whats behind them



}
