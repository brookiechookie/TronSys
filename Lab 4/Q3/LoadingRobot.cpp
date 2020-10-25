// LoadingRobot.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Implementation file for a robot that can load items onto a
//                conveyor belt
//
// Modifications:
//

#include <cstdlib>      // rand

#include "LoadingRobot.h"
#include "Conveyor.h"


//---------------------------------------------------------------
// Initialise the pointer conveyor to point to the right conveyor
void LoadingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//---------------------------------------------------------------
// Method that adds items to the conveyor. At the moment a random
// number of items is being added each cycle
void LoadingRobot::AddItems()
{
    _Conveyor->AddItems( rand() % 10 );

}
