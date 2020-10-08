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
        Item( int SpecialID );
        //Item();
        ~Item();
        //int   data;
        Item* next;
        Item* prev;
        int IDGetter();



    private:
        int   _ItemID;
        float _ProcTime;



};



#endif
