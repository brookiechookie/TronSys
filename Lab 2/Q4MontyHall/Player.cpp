// Player.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Player.h"

//------------------------------------------------------------------------------
// This is the constructor for player which creates a player with a name
Player::Player( std::string Name )
{
    _PlayerName = Name;

}

/*
Player::Player( Host* WhichHost )
{
    _Host = WhichHost;
}
*/
//------------------------------------------------------------------------------
// This function is where the player makes an initial door selection
void Player::PickDoor()
{
    // Player has to choose a door to pick
    // Hard code this at first and then build it up

    _PickedDoor = 1;

    std::cout << "[Player]: Player " << _PlayerName << " has picked door " << _PickedDoor << std::endl;

}

//------------------------------------------------------------------------------
// This is a getter function which returns the door that the player has picked
int Player::PickedDoorGetter()
{
    //std::cout << "[Player]: In getter func, door picked is " << _PickedDoor << std::endl;

    return _PickedDoor;
}

//------------------------------------------------------------------------------
// This is a getter function which returns the players name
std::string Player::NameGetter()
{
    return _PlayerName;
}

/*
void Player::SetHost( Host* WhichHost )
{
    _Host = WhichHost;
}
*/

/*
//------------------------------------------------------------------------------
// This is a function that implements the actions of the player who chooses to
// always stick with their decision to stay
void Player::PlayerWhoStays()
{
    // This player when given the choice, always chooses to STAY with the door
    // that they had originally chosen.
    //_DoorSelection = _PickedDoor;
    //std::cout << "[Player]: The player has decided to STAY with the selection of door " <<
    //_DoorSelection << std::endl;

}

//------------------------------------------------------------------------------
// This is a function that implements the actions of a player who always decides
// to switch their decision on doors
void Player::PlayerWhoSwitches()
{
  // This player when given the choice, always chooses to SWITCH doors

}
*/
