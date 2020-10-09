// Item.cpp
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Implementation file for the Item class


#include "Item.h"

//------------------------------------------------------------------------------
// Class Item Constructor
Item::Item( int SpecialID )
{
    _ItemID = SpecialID;

    // The following lines of code assign a processing time to each item in a
    // uniformly distributed manner of type float.
    // The following code was sourced online from cppreference. I used this
    // resource on the 7/10/20, and it can be found at
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    const float range_from  = 1;
    const float range_to    = 5.1;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distr(range_from, range_to);
    _ProcTime = distr(generator);

    std::cout << "[CTor]: Item ID = " << _ItemID << ", Proc time = "<< _ProcTime
    << " sec added" << std::endl;

}

//------------------------------------------------------------------------------
// Class Item Destructor
Item::~Item()
{
    std::cout << "[DTor]: Item with ID " << _ItemID << " is signing off."
    << std::endl;
}

//------------------------------------------------------------------------------
// Getter function returning the item ID's of each Item object
int Item::IDGetter()
{
    return _ItemID;
}
