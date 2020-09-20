// Player.cpp
//
// Implementation file for the class: Player



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

//------------------------------------------------------------------------------
// This function is where the player makes an initial door selection
int Player::UserPickedDoorSetter( int UserPickedDoor )
{
    _PickedDoor = UserPickedDoor;
    std::cout << "[Player]: Player " << _PlayerName << " has picked door " << _PickedDoor << std::endl;
}

//------------------------------------------------------------------------------
// This is a getter function which returns the door that the player has picked
int Player::PickedDoorGetter()
{
    return _PickedDoor;
}

//------------------------------------------------------------------------------
// This is a getter function which returns the players name
std::string Player::NameGetter()
{
    return _PlayerName;
}

//------------------------------------------------------------------------------
// This functions sets the door that the player can switch to
void Player::SetSwitchDoorNumber( int s )
{
    _SwitchDoorNumber = s;
}

//------------------------------------------------------------------------------
// This is a function that implements the actions of the player who chooses to
// always stick with their decision to stay with the door that they had originally chosen.
void Player::PlayerWhoStays()
{
    _DoorSelection = _PickedDoor;
    std::cout << "[Player]: The player has decided to STAY with the selection of door " <<
    _DoorSelection << std::endl;

}

//------------------------------------------------------------------------------
// This is a function that implements the actions of a player who always decides
// to switch their decision on doors
void Player::PlayerWhoSwitches()
{
    _DoorSelection = _SwitchDoorNumber;
    std::cout << "[Player]: The player has decided to SWITCH to door " <<
    _DoorSelection << std::endl;

}

int Player::DoorSelectionGetter()
{
    return _DoorSelection;
}
