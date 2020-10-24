// Item.cpp
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Implementation file for the Item class


#include "Item.h"


Item::Item()
{
    std::cout<< "[CTor]: Item with no values constructed" << std::endl;
}


//------------------------------------------------------------------------------
// Class Item Constructor
Item::Item( int SpecialID )
{
    _ItemID   = SpecialID;

    std::cout << "[CTor]: Item ID = " << _ItemID << " added" << std::endl;

}

//------------------------------------------------------------------------------
// Class Item Destructor
Item::~Item()
{
    //std::cout << "[DTor]: Item with ID " << _ItemID << " is signing off."
    //<< std::endl;

}

//------------------------------------------------------------------------------
// Getter function returning the item ID's of each Item object
int Item::IDGetter()
{
    return _ItemID;
}
