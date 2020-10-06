// Item.cpp
//
// Implementation file for the Item class

#include "ItemParent.h"
#include <vector>     // Vector STL

/* Steps
      1. First we want to create a vector which is going to store each item
          and assign each item an ID number

*/

//------------------------------------------------------------------------------
/*
ItemParent::ItemParent( int NewItemsAdded )
{

    for(int i = 1; i <= NewItemsAdded; i++ )
    {
        _ItemID = rand() % 999;
        TheHugeVector.push_back( _ItemID );

        std::cout << "[ItemP]: New Item " << i << " added to HugeVec. Item ID: " <<
        _ItemID << std::endl;
    }

    print_container( TheHugeVector );

}
*/
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

//------------------------------------------------------------------------------
// This function will delete the items from the vector. The function needs to
// know how many items need to be deleted. They will be deleted from the front
// and then the rest of the vector will be shifted forward
void ItemParent::DeleshItems()
{
    ItemsRemoving = _ProcessingRobot->GetProcessedItems();

    print_container( TheHugeVector );
    TheHugeVector.erase( TheHugeVector.begin(), TheHugeVector.begin() + ItemsRemoving );
    print_container( TheHugeVector );
}

//------------------------------------------------------------------------------
void ItemParent::print_container(const std::vector<int>& insertVector )
{
    for (auto &i : insertVector )
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}
