// Item.cpp
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Implementation file for the Item class


#include "Item.h"

//------------------------------------------------------------------------------
// Class Item Constructor
Item::Item( int SpecialID )
{
    _ItemID = SpecialID;
    std::cout << "[Item]: Item with ID " << _ItemID << " added" << std::endl;
}

//------------------------------------------------------------------------------
// Class Item Destructor
Item::~Item()
{
    std::cout << "[DTor]: Item with ID " << _ItemID << " is signing off."
    << std::endl;
}
