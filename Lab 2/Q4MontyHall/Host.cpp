// Host.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Host.h"
//#include "Doors.h"

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
    _Player = WhichPlayer;
    _LePlayerName = _Player->NameGetter();

}

void Host::TryingToGetDoors( Doors* WhichDoors )
{
    _Doors = WhichDoors;
}


//------------------------------------------------------------------------------
// This is a function that contains the hosts initial question to be asked
void Host::StarterQuestion()
{
    std::cout << "[Host]: Welcome to the Monty Hall Game!" << std::endl;
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

    // std::cout << "[Host]: Player " << _LePlayerName << " has picked door " << _PlayerDoorPicked << std::endl;

    // 1. Host needs to see the doors and whats behind them
    StoredDoors = _Doors->DoorsGetter();

    // Now display whats at the doors...?
    //std::cout << "[Host]: First, second, third elements in StoredDoors: " << StoredDoors[0] << ", " <<
    //StoredDoors[1] << " and  "<< StoredDoors[2] << std::endl;


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
    " contains a goat. Player " << _LePlayerName << ", would you like to stay with door " <<
    _PlayerDoorPicked << " or would you like to switch to door " << _DoorSwitchPotential << "?"<< std::endl;

}

//------------------------------------------------------------------------------
// This is a getter function which returns the door that the player can potentially
// switch to
int Host::DoorSwitchGetter()
{
    return _DoorSwitchPotential;
}

//------------------------------------------------------------------------------
// This purpose of this function is to see if the player has won or lost
int Host::WinOrLose()
{
    _PlayerDoorSelectV2 = _Player->DoorSelectionGetter();

    if( StoredDoors[ _PlayerDoorSelectV2 ] == 1 )
    {
        std::cout << "[Host]: Congratulations Player " << _LePlayerName <<
        " you have WON!!" << std::endl;
        _PlayerOutcome = 1;
    }
    else if(  StoredDoors[ _PlayerDoorSelectV2 ] == 0 )
    {
        std::cout << "[Host]: Sorry Player " << _LePlayerName <<
        " you have LOST!!" << std::endl;
        _PlayerOutcome = 0;
    }

    return _PlayerOutcome;

  }
