// Item.h
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Header file for Item class in Simulated Conveyor Belt


#ifndef _ITEM_H
#define _ITEM_H


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()
#include <random>       // For uniform number generation


class Item
{
    public:
        Item( int SpecialID );
        ~Item();
        float ProcTimeGetter();
        float TimeONSetter( float TimeON );
        float TimeOFFSetter( float TimeOFF );
        float TimeONgetter();

    private:
        int   _ItemID;
        float _ProcTime;
        float _TimeON;
        float _TimeOFF;

};



#endif
