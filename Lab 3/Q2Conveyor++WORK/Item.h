// Item.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _ITEM_H
#define _ITEM_H

#include "Conveyor.h"
#include <vector>     // Vector STL
#include <iostream>     // std::cout
#include <cstdlib>      // For rand()

class Item
{
    public:
        Item( );
        Item( Conveyor* WhichConveyor );
        //void NewItem();
        //virtual ~Item( );

    protected:                // Protected classes allow derived classes to access the variable
        Conveyor* _Conveyor;
        std::vector<int> TheHugeVector;

};



#endif
