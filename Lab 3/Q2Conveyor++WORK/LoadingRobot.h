// LoadingRobot.h
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Header file for LoadingRobot class in Simulated Conveyor Belt

#ifndef _LOADINGROBOT_H
#define _LOADINGROBOT_H

#include "Conveyor.h"


//-------------------------------------------------------------------
// Simulate a loading robot that places items on a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will load.
// This version simulates an irregular source of parts by adding a
// random number of parts to the conveyor when AddItems() is called.
class LoadingRobot
{
    public:
        LoadingRobot( Conveyor* WhichConveyor );
        int AddItems();
    private:
        Conveyor* _Conveyor;
        int _ItemsToAdd;
};


#endif
