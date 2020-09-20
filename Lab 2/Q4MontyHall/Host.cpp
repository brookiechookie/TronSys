// Host.cpp
//
// Implementation file for the class: Host



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Host.h"
//#include "Doors.h"


//------------------------------------------------------------------------------
// This is the constructor for host which draws information from other classes
Host::Host( Player* WhichPlayer )
{
    _Player = WhichPlayer;
    _LePlayerName = _Player->NameGetter();
}

//------------------------------------------------------------------------------
// This function gets the address of the relevant instantiated object class
void Host::TryingToGetDoors( Doors* WhichDoors )
{
    _Doors = WhichDoors;
}

//------------------------------------------------------------------------------
// This is a function that contains the hosts initial question to be asked
// We want the host to ask the player which door they would like to open
void Host::StarterQuestion()
{
    std::cout << "[Host]: Welcome to the Monty Hall Game!" << std::endl;
    std::cout << "[Host]: Player "<< _LePlayerName << ", which door would you like to open?" << std::endl;
}

//------------------------------------------------------------------------------
// This is a function that figures out which door to reveal based on which door
// the player has picked and which door has the car behind it. It also figures
// out which door the person has the option to switch to
void Host::RevealDoor()
{
    _PlayerDoorPicked = _Player->PickedDoorGetter();
    _NumberOfDoors = _Doors->NumOfDoorsGetter();
    _CarDoor = _Doors->CarDoorGetter();


    // Host needs to see the doors and whats behind them
    StoredDoors = _Doors->DoorsGetter();

    // Find the door with the car behind it
    for( int i = 0; i < _NumberOfDoors; i++ )
    {
        // If the player has picked a door with a goat, then the potential door
        // that they can switch to will be the door with the car
        if( StoredDoors[i] == 1 && i != _PlayerDoorPicked )
        {
            _DoorSwitchPotential = i;
        }
        // If the player has picked the door with the car, give them the option
        // to switch to another random door.
        else if( StoredDoors[_PlayerDoorPicked] == 1 ) //
        {
            while ( _DoorToSwitchTo == _PlayerDoorPicked )
            {
                _DoorToSwitchTo = rand() % _NumberOfDoors;
            }
            _DoorSwitchPotential = _DoorToSwitchTo;
        }
    }

    // 4. Now reveal the door options that they player has
    _DoorsRevealed = _NumberOfDoors - 2;

    std::cout << "[Host]: The host reveals " << _DoorsRevealed << " doors. There are now " <<
    "two doors remaining; door "<< _PlayerDoorPicked << " picked by the player and door " <<
    _DoorSwitchPotential << ". Player " << _LePlayerName << ", would you like to stay with door " <<
    _PlayerDoorPicked << ", or would you like to switch to door " << _DoorSwitchPotential << "?"<< std::endl;

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
