// Item.h
//
// Creator:   Brookie
// Date:      23.10.20
// Purpose:   Header file for Item class 


#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>     // std::cout

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
