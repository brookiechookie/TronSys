// IndiItem.cpp
//
// Implementation file for an individual Item on the conveyor belt

#include "IndiItem.h"
#include "Item.h"

#include "Conveyor.h"


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()


IndiItem::IndiItem( int NItemsAdded )
{

    for(int i = 1; i <= NItemsAdded; i++ )
    {
        TheHugeVector.push_back( i );
        std::cout << "[Item]: New Item " << i << " added to HugeVec" << std::endl;
    }

    /*
    // Assign a new ID to each object of Item that gets created
    _ItemID = rand() % 999999;
    */


}
