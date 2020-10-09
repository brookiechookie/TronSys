// Item.h
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Header file for Item class in Simulated Conveyor Belt


#ifndef _ITEM_H
#define _ITEM_H


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()
#include <random>       // For uniform number generation


class Item
{
    public:
        Item( int SpecialID, float TimeOn );
        ~Item();
        float ProcTimeGetter();
        void  TimeONSetter( float TimeON );
        void  TimeOFFSetter( float TimeOFF );
        float TimeONgetter();
        Item* next;
        Item* prev;
        int   IDGetter();

    private:
        int   _ItemID;
        float _ProcTime;
        float _TimeON;
        float _TimeOFF;

};



#endif
