// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <vector>       // vector

#include "ProcessingRobot.h"

//------------------------------------------------------------------------------
void ProcessingRobot::Init( Conveyor* WhichConveyor, int NumItemsToBeRemoved )
{
    _Conveyor = WhichConveyor;
    _MaxItemRemoval = NumItemsToBeRemoved;
}


//------------------------------------------------------------------------------
// This function removes items from the conveyor
void ProcessingRobot::ProcessItems()
{
    _Conveyor->RemoveItems( _MaxItemRemoval );
}


//------------------------------------------------------------------------------
// This is a getter function returning the number of items that have been removed
int ProcessingRobot::GetProcessedItems()
{
    return _ProcessedItems;
}


//------------------------------------------------------------------------------
// This function calculates how many items have been removed from the conveyor
void ProcessingRobot::RemovalItemReport()
{
    _NumItemsOnConv = _Conveyor->GetNumItemsOnConveyor();

    if( _NumItemsOnConv <= _MaxItemRemoval )
    {
        _ProcessedItems = _NumItemsOnConv;
    }
    else if( _NumItemsOnConv > _MaxItemRemoval )
    {
        _ProcessedItems = _MaxItemRemoval;
    }

    std::cout << "[Processor]: " << _ProcessedItems << " items removed" << std::endl;
}
