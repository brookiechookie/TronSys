// IndiItem.cpp
//
// Implementation file for an individual Item on the conveyor belt

#include "IndiItem.h"
#include "ItemParent.h"

#include "Conveyor.h"


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()


IndiItem::IndiItem( int NItemsAdded )
{

    for(int i = 1; i <= NItemsAdded; i++ )
    {
        TheHugeVector.push_back( i );
        _ItemID = rand() % 999999;

        std::cout << "[Item]: New Item " << i << " added to HugeVec. Item ID: " <<
        _ItemID << std::endl;
    }

}
