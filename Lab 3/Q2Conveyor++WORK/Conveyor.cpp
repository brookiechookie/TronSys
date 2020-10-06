// Conveyor.cpp
//
// Implementation file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "Conveyor.h"

//---------------------------------------------------------------
void Conveyor::Init()
{
    _NumItemsOnConveyor = 0;
    _CycleCount = 0;
}

//---------------------------------------------------------------
// Adds items to the conveyor and also doubles as a getter function
// to return the number of items that were just added to the conveyor
int Conveyor::AddItems( int n )
{
    _NumItemsOnConveyor += n;

    /*
    for(int i = 1; i <= n; i++ )
    {
        MyListOfItems.push_back( i );
        std::cout << "[Item]: New Item " << i << " added" << std::endl;
    }
    */

    _CycleCount++;
    std::cout << "Current Cycle: " << _CycleCount << std::endl;

    return n;
}

//---------------------------------------------------------------
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);
}

//---------------------------------------------------------------
void Conveyor::Report()
{
    std::cout << "[Conveyor]: Items on conveyor: " << _NumItemsOnConveyor << std::endl;

}

//---------------------------------------------------------------
// Getter function which returns the number of items on conveyor
int Conveyor::GetNumItemsOnConveyor()
{
    return _NumItemsOnConveyor;
}
