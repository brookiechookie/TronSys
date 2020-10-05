// IndiItem.cpp
//
// Implementation file for an individual Item on the conveyor belt

#include "IndiItem.h"
#include "Item.h"
#include "Conveyor.h"

#include <cstdlib>    // For rand()

IndiItem::IndiItem()
{
    // Assign a new ID to each object of Item that gets created
    _ItemID = rand() % 999999;
}

//pPeops[i] = new English( );
