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
        _ItemID = rand() % 999;
        TheHugeVector.push_back( _ItemID );

        std::cout << "[ItemP]: New Item " << i << " added to HugeVec. Item ID: " <<
        _ItemID << std::endl;
    }

    print_container( TheHugeVector );

}
