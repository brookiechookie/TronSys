// Item.h
//
// Header file ffor Item class in Simulated Conveyor Belt

#ifndef _ITEM_H
#define _ITEM_H


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()


class Item
{
    public:
        Item( int index );
        ~Item();

    private:
        int _ItemID;


};




#endif
