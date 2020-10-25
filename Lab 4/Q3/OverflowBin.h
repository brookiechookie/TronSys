// OverflowBin.h
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Header file for a robot that can load items onto a
//                conveyor belt
//
// Modifications:
//

#ifndef _OVERFLOWBIN_H
#define _OVERFLOWBIN_H

#include "Conveyor.h"


//-------------------------------------------------------------------
// Simulate a loading robot that places items on a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will load.
// This version simulates an irregular source of parts by adding a
// random number of parts to the conveyor when AddItems() is called.
class OverflowBin
{
    public:
        void UseOverflowBin( );
        void OverflowBinReport( );
    private:
        Conveyor* _Conveyor;
        int _NumberOfItemOnConv;
};


#endif
