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

    // The following lines of code assign a processing time to each item in a
    // uniformly distributed manner of type float.
    const float range_from  = 1;
    const float range_to    = 5.1;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distr(range_from, range_to);
    _ProcTime = distr(generator);

    std::cout << "[Item]: Item with ID " << _ItemID << " and proc time "<< _ProcTime
    << " added" << std::endl;
}

//------------------------------------------------------------------------------
// Class Item Destructor
Item::~Item()
{
    std::cout << "[DTor]: Item with ID " << _ItemID << " is signing off."
    << std::endl;
}

//------------------------------------------------------------------------------
// This function returns the processing time variable of an item
float Item::ProcTimeGetter()
{
    return _ProcTime;
}
