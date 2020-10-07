// Item.h
//
// Header file ffor Item class in Simulated Conveyor Belt

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

    private:
        int _ItemID;
        float _ProcTime;


};




#endif
