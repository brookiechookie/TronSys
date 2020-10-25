// Item.h
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Header file for Item class in Test DIY List


#ifndef _ITEM_H
#define _ITEM_H


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()
#include <random>       // For uniform number generation


class Item
{
    public:
        Item();
        Item( int SpecialID );
        ~Item();
        int IDGetter();
        Item( const Item& other );
        Item& operator=( const Item& other );

    private:
        int   _ItemID;

};



#endif
