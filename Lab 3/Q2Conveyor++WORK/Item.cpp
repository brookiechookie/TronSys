// Item.cpp
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Implementation file for the Item class


#include "Item.h"

//------------------------------------------------------------------------------
// Class Item Constructor
Item::Item( int index )
{
    //_ItemID = rand() % 999;
    _ItemID = index;
    std::cout << "[ItemCon]: Item with ID " << _ItemID << " added" << std::endl;

    /*
    _ItemID = rand() % 999;
    MyVectorOfItems.push_back( _ItemID );
    std::cout << "[Item]: New Item added" << std::endl;
    */
}

//------------------------------------------------------------------------------
// Class Item Destructor
Item::~Item()
{
    std::cout << "[DTor]: Item " << _ItemID << " is signing off."
    << std::endl;
}
