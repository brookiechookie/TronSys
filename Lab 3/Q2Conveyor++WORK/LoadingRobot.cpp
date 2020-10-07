// LoadingRobot.cpp
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Implementation file for the LoadingRobot class



#include <cstdlib>      // rand
#include <iostream>
#include <string>

#include "LoadingRobot.h"
#include "Conveyor.h"


//------------------------------------------------------------------------------
// Constructor for Loading Robot
LoadingRobot::LoadingRobot( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//------------------------------------------------------------------------------
// This function is responsible for loading a "random" number of items onto the
// conveyor 
int LoadingRobot::AddItems()
{
    _ItemsToAdd = rand() % 10;
    _Conveyor->AddItems( _ItemsToAdd );
    return _ItemsToAdd;
}
