// LoadingRobot.cpp
//
// Implementation file for a robot that can load items onto a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:


#include <cstdlib>      // rand
#include <iostream>
#include <string>

#include "LoadingRobot.h"
#include "Conveyor.h"


//---------------------------------------------------------------
void LoadingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//---------------------------------------------------------------
int LoadingRobot::AddItems()
{
    _ItemsToAdd = rand() % 10;
    _Conveyor->AddItems( _ItemsToAdd );
    std::cout << "[LoadingRob]: " << _ItemsToAdd << " items added to conveyor" << std::endl;
    return _ItemsToAdd;
}
