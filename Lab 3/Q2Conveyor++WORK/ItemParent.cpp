// Item.cpp
//
// Implementation file for the Item class

#include "ItemParent.h"

/* Steps
      1. First we want to create a vector which is going to store each item
          and assign each item an ID number

*/

//------------------------------------------------------------------------------
ItemParent::ItemParent()
{
    
}


//------------------------------------------------------------------------------
ItemParent::ItemParent( Conveyor* WhichConveyor, ProcessingRobot* WhichProcessor, int NumberOfItemsToBeRemoved )
{
    _Conveyor         = WhichConveyor;
    _ProcessingRobot  = WhichProcessor;
    _NumItemsRemoved  = NumberOfItemsToBeRemoved;
}

//------------------------------------------------------------------------------
void ItemParent::AmountOfItemsRemoved()
{
    _NumItemsRemoved = _ProcessingRobot->GetProcessedItems();

    std::cout << "[ItemParent]: I can see that " << _NumItemsRemoved << " items " <<
    "been removed." << std::endl;
}
