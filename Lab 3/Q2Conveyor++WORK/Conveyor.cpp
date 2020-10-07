// Conveyor.cpp
//
// Implementation file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "Conveyor.h"
#include "Item.h"

//------------------------------------------------------------------------------
void Conveyor::Init( float MaxProcessingTime )
{
    _NumItemsOnConveyor = 0;
    _CycleCount = 0;
    _TotalItemsInPointer = 0;
    _i = 0;
    _UniqueID = 0;
    _MaxProcessingTime = MaxProcessingTime;
}


//------------------------------------------------------------------------------
// Adds items to the conveyor and also doubles as a getter function
// to return the number of items that were just added to the conveyor
int Conveyor::AddItems( int n )
{
    _NumItemsOnConveyor += n;
    _CycleCount++;

    std::cout << "[Conv]: " <<  n << " items added to the conveyor" << std::endl;

    for( _i = _TotalItemsInPointer ; _i < (n + _TotalItemsInPointer) ; _i++ )
    {
        // 1. Create a new object Item with an ID
        // 2. Add this object to the vector

        std::cout << "[Conv]: At Index " << _i << std::endl;

        pItems = new Item( _UniqueID );     // Creating new item object
        MyListOfItems.push_back( pItems );  // Put a pointer to this object in the vector
        _TimeONCalculated = _CycleCount * _MaxProcessingTime;
        pItems->TimeONSetter( _TimeONCalculated );

        std::cout << "[Conv]: Time ON = " << _TimeONCalculated << std::endl;
        _UniqueID++;

    }

    _TotalItemsInPointer = _TotalItemsInPointer + n;

    std::cout << "[Conv]: Current Cycle: " << _CycleCount << std::endl;

    return n;
}



//------------------------------------------------------------------------------
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);

    std::cout << "[Conv]: " << n << " items being removed" << std::endl;


    // Delete the item
    // Delete the element where the item was

    _TotalItemsInPointer = _TotalItemsInPointer - n;

    for( std::vector<Item*>::iterator pObj = MyListOfItems.begin(); pObj < ( MyListOfItems.begin() + n ) ; ++pObj  )
    {

        delete *pObj; // Deletes the item object
    }

    MyListOfItems.erase( MyListOfItems.begin(), MyListOfItems.begin() + n );  // Deletes the element in the vector


}



//------------------------------------------------------------------------------
void Conveyor::Report()
{
    std::cout << "[Conv]: Items on conveyor: " << _NumItemsOnConveyor << std::endl;

}



//------------------------------------------------------------------------------
// Getter function which returns the number of items on conveyor
int Conveyor::GetNumItemsOnConveyor()
{
    return _NumItemsOnConveyor;
}



//------------------------------------------------------------------------------
// The purpose of this function is to take an integer input at which the user
// desires to obtain data from the vector that contains the items. I.e. input
// the index in which you wish to obtain the processing time variable for.
float Conveyor::GetItemProcTime( int _ItemIndex )
{
    // If the input index is less than the current highest index for the vector
    // then there exists a valid item. If the desired index is greater than the
    // current index then there is no item and we must return a value that the
    // processing robot can check against to make sure it is a valid proc time
    if( _ItemIndex < _i )
    {
      // Right hand side is going to return a pointer to an Item
      // we need to dereference this item and access the proc time variable
        Item* pItem = MyListOfItems.at( _ItemIndex );
        _ProcTimeReturning = pItem->ProcTimeGetter();

    }
    else
    {
        _ProcTimeReturning = 999;
    }

    return _ProcTimeReturning;

}


//------------------------------------------------------------------------------
// The purpose of this getter is to return the cycle count
int Conveyor::CycleCountGetter()
{
    return _CycleCount;
}


//------------------------------------------------------------------------------
//
void Conveyor::SettingItemTimeOFF( int currentIndex, float TimeOFFcalculated )
{
    Item* pLilItem = MyListOfItems.at( currentIndex );
    pLilItem->TimeOFFSetter( TimeOFFcalculated );
}


//------------------------------------------------------------------------------
//
float Conveyor::TimeONGetGet( int currentIndex )
{
    Item* pAnothItem = MyListOfItems.at( currentIndex );
    _ItemTimeON = pAnothItem->TimeONgetter();
    return _ItemTimeON;
}
