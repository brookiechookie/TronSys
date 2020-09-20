// Player.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Player.h"

Player::Player( std::string Name )
{
    _PlayerName = Name;
}

void Player::PickDoor()
{
    // Player has to choose a door to pick
    // Hard code this at first and then build it up

    _PickedDoor = 1;

    std::cout << "[Player]: Player " << _PlayerName << " has picked door " << _PickedDoor << std::endl;

}

int Player::PickedDoorGetter()
{
    std::cout << "[Player]: In getter func, door picked is " << _PickedDoor << std::endl;

    return _PickedDoor;
}

std::string Player::NameGetter()
{
    return _PlayerName;
}
