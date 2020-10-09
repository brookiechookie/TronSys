// Conveyor.cpp
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Implementation file for the Conveyor class


#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "Conveyor.h"
#include "Item.h"

//------------------------------------------------------------------------------
// Constructor for Conveyor, setting various variables
Conveyor::Conveyor( float MaxProcessingTime, int ErrorValue )
{
    _NumItemsOnConveyor   = 0;
    _CycleCount           = 0;
    _TotalItemsInPointer  = 0;
    _i                    = 0;
    _UniqueID             = 0;
    _MaxProcessingTime    = MaxProcessingTime;
    _ErrorValue           = ErrorValue;
    _Overflow             = 0;
    _TotalNumItemsAdded   = 0;
}


//------------------------------------------------------------------------------
// This function adds items to the conveyor, keeps track of the cycle count and
// also creates objects for all the new items being added and stores them in
// a vector of class item
void Conveyor::AddItems( int n )
{
    //_NumItemsOnConveyor += n;
    _CycleCount++;
    _TotalNumItemsAdded = _TotalNumItemsAdded + n;

    if( _NumItemsOnConveyor > 50)
    {
        _Overflow++;
    }

    std::cout << "[Conv]: " <<  n << " items added to the conveyor" << std::endl;

    for( _i = _TotalItemsInPointer ; _i < (n + _TotalItemsInPointer) ; _i++ )
    {
        // 1. Create a new object Item with an ID
        // 2. Add this object to the vector

        //std::cout << "[Conv]: At Index " << _i << std::endl;

        //pItems = new Item( _UniqueID );     // Creating new item object
        //MyListOfItems.push_back( pItems );  // Put a pointer to this object in the vector

        // This records the time the item was loaded onto the conveyor, then
        // adds this item to the back of the doublylinkedlist (DLL)
        _TimeONCalculated = _CycleCount * _MaxProcessingTime;
        myList.push_back( _UniqueID, _TimeONCalculated );


        //_TimeONCalculated = _CycleCount * _MaxProcessingTime; // Record the time that the
        //pItems->TimeONSetter( _TimeONCalculated );            // item was loaded onto conveyor

        //std::cout << "[Conv]: Time ON = " << _TimeONCalculated << std::endl;
        _UniqueID++;

    }
    std::cout << "[Conv]: Finished Loading List with items" << std::endl;
    myList.printList( );
    //int sizeUp = myList.Size();
    _NumItemsOnConveyor = myList.Size();
    std::cout << "[Conv]: Size of List is " << _NumItemsOnConveyor << std::endl;



    _TotalItemsInPointer = _TotalItemsInPointer + n;

    std::cout << "[Conv]: Current Cycle: " << _CycleCount << std::endl;
}


//------------------------------------------------------------------------------
// This simply reports the number of items currenly on the conveyor
void Conveyor::Report()
{
    std::cout << "[Conv]: Items on conveyor: " << _NumItemsOnConveyor << std::endl;
}


//------------------------------------------------------------------------------
// The purpose of this getter is to return the cycle count
int Conveyor::CycleCountGetter()
{
    return _CycleCount;
}


//------------------------------------------------------------------------------
// The purpose of this function is to feedback to the user, the processing
// time for the first item in the list
float Conveyor::GetFirstItemProcTime( )
{
    float _ValToReturn;

    int _IsListEmpty = myList.CheckIfListEmpty();
    if( _IsListEmpty == _ErrorValue )
    {
         _ValToReturn = float(_ErrorValue);
         std::cout << "[Conv]: List is EMPTY!" << std::endl;
    }
    else
    {
        Item* _FirstItem = myList.ReturnFirstItem();
        float _ItemProcTime = _FirstItem->ProcTimeGetter();
        std::cout << "[Conv]: The first item proc time is " << _ItemProcTime << " sec" << std::endl;
        _ValToReturn = _ItemProcTime;
    }

    return _ValToReturn;
}

//------------------------------------------------------------------------------
// This function sets the off time for an item. In order to do this, we must
// know the index of the item in the vector, and also the time that the item
// was taken off the conveyor
void Conveyor::SettingItemTimeOFF( float TimeOFFcalculated )
{
    Item* pLilItem = myList.ReturnFirstItem();
    pLilItem->TimeOFFSetter( TimeOFFcalculated );

}


//------------------------------------------------------------------------------
// This function is essentially a double getter function as it is first getting
// the timeon variable from item and then the function itself is a getter which
// returns the timeOn value
float Conveyor::GetFirstItemTimeON( )
{
    Item* pAnothItem = myList.ReturnFirstItem();
    _ItemTimeON = pAnothItem->TimeONgetter();
    return _ItemTimeON;
}


//------------------------------------------------------------------------------
// This function removes items from the conveyor belt, and at the same time also
// deletes the object item and removes it from the vector storing all the items
void Conveyor::RemoveItem( )
{
    // Note that we cannot have a negative number of items on belt
    //_NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);

    std::cout << "[Conv]: First Item being removed" << std::endl;

    _TotalItemsInPointer = _TotalItemsInPointer - 1;

    myList.pop_front();
    _NumItemsOnConveyor = myList.Size();

    //for( std::vector<Item*>::iterator pObj = MyListOfItems.begin(); pObj < ( MyListOfItems.begin() + n ) ; ++pObj  )
    //{
    //    delete *pObj; // Deletes the item object
    //}

    // Deletes the element in the vector
    //MyListOfItems.erase( MyListOfItems.begin(), MyListOfItems.begin() + n );
}



/*
//------------------------------------------------------------------------------
// The purpose of this function is to feedback to the user, the processing
// time for the first item in the list
float Conveyor::GetFirstItemProcTime( )
{
    float ItemProcTimeFromList = myList.GetProcTime();
    return ItemProcTimeFromList;
}




//------------------------------------------------------------------------------
// This function is essentially a double getter function as it is first getting
// the timeon variable from item and then the function itself is a getter which
// returns the timeOn value
float Conveyor::GetFirstItemTimeON( )
{
    // Pointer to the desired element
    Item* pAnothItem = MyListOfItems.at( currentIndex );
    _ItemTimeON = pAnothItem->TimeONgetter();


    _ItemTimeON = myList.GetItemTimeOn()
    return _ItemTimeON;
}


//------------------------------------------------------------------------------
// Getter function which returns the number of items on conveyor
int Conveyor::GetNumItemsOnConveyor()
{
    return _NumItemsOnConveyor;
}


//------------------------------------------------------------------------------
// This function reports the number of overflows that occur
void Conveyor::ReportOverflows()
{
    std::cout << "Counted number of overflows = " << _Overflow << std::endl;
}


//------------------------------------------------------------------------------
// This function calculates the average number of items added in a cycle
void Conveyor::AvgNumbAddedItems()
{
    _AvgNumbItems = float(_TotalNumItemsAdded) / float(_CycleCount);

    std::cout << "Average Number of Items Added in a Cycle = " << _AvgNumbItems <<
    std::endl;
}

*/
