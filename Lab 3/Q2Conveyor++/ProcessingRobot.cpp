// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max

#include "ProcessingRobot.h"

//---------------------------------------------------------------
void ProcessingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//---------------------------------------------------------------
void ProcessingRobot::ProcessItems()
{
    _Conveyor->RemoveItems( 5 );
}


