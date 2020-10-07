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
#include "Conveyor.h"
#include "Item.h"

//------------------------------------------------------------------------------
void ProcessingRobot::Init( Conveyor* WhichConveyor, int NumItemsToBeRemoved, float MaxProcessingTime )
{
    _Conveyor           = WhichConveyor;
    _MaxItemRemoval     = NumItemsToBeRemoved;
    _MaxTotalProcTime   = MaxProcessingTime;
    _CycleCount         = 0;
    _RobotArmUsageTime  = 0;

}


//------------------------------------------------------------------------------
// This function removes items from the conveyor
void ProcessingRobot::ProcessItems()
{
    _Conveyor->RemoveItems( _CurrentIndex );
}


//------------------------------------------------------------------------------
// This is a getter function returning the number of items that have been removed
int ProcessingRobot::GetProcessedItems()
{
    //return _ProcessedItems;
    return _CurrentIndex;
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

    std::cout << "[Proc]: Please remove " << _ProcessedItems << " items" << std::endl;
}


//------------------------------------------------------------------------------
// The purpose of this function is to process a number of items within a fixed
// processing time frame.
void ProcessingRobot::ProccessItemsTimed()
{
    /* Steps:
          1.  I need to get the Processing time private variable of the first
              item in the vector
          2.  Add this items processing time to a variable storing the count
          3.  Once the count passes a certain value, we have maxed out on time
              so feed into the ProcessItems function how many items have managed
              to be processed.
    */

    // Reset all the relevant variables to their base value every time this
    // function is called
    _TotalTime        = 0;
    _UnderTimeLimit   = 1;
    _CurrentIndex     = 0;
    _CurrentItemTime  = 0;

    //std::cout << "[Proc]: New Func Enterred " << std::endl;


    while( _UnderTimeLimit )
    {
        _CurrentItemTime = _Conveyor->GetItemProcTime( _CurrentIndex );

        //std::cout << "[Proc]: Current Index = " << _CurrentIndex << std::endl;
        //std::cout << "[Proc]: Current Item Time = " << _CurrentItemTime << std::endl;

        if( _CurrentItemTime == 999 )
        {
            // If this input is received from the function, this means that we
            // have exceeded the number of items that are in the array. So just
            // return from the while loop with the current calculated total time
            _UnderTimeLimit = 0;
            //std::cout << "[Proc]: Exceeded number of items in array " << std::endl;
        }
        else if( _TotalTime < _MaxTotalProcTime )
        {
            //std::cout << "[Proc]: Total time is currently less than max time " << std::endl;
            //std::cout << "[Proc]: Max Time = "<< _MaxTotalProcTime << std::endl;
            std::cout << "[Proc]: Total Time = "<< _TotalTime << std::endl;

            if( (_TotalTime + _CurrentItemTime) <= _MaxTotalProcTime )
            {
                _TotalTime = _TotalTime + _CurrentItemTime;
                _CurrentIndex++;
                std::cout << "[Proc]: Safe to add next time, new tot time = " << _TotalTime << std::endl;
            }
            else
            {
                _UnderTimeLimit = 0;
                std::cout << "[Proc]: Not safe to process next time" << std::endl;
            }
        }

    }


    _RobotArmUsageTime = _RobotArmUsageTime + _TotalTime;
    std::cout << "[Proc]: Current Index = "<< _CurrentIndex << std::endl;

}



//------------------------------------------------------------------------------
//
void ProcessingRobot::AvgArmUtil()
{
    _CycleCount = _Conveyor->CycleCountGetter();
    _TotalRunTime = _CycleCount*_MaxTotalProcTime;

    _AvgArmUtilTime = ( _RobotArmUsageTime/_TotalRunTime ) * 100;
    std::cout << "Cycle Count = " << _CycleCount << std::endl;
    std::cout << "Total Run Time = " << _TotalRunTime << std::endl;
    std::cout << "Robot arm usage time = " << _RobotArmUsageTime << std::endl;
    std::cout << "Avg Arm Util Time = " << _AvgArmUtilTime << std::endl;

    std::cout << "[Proc]: Average Arm Util Time = "<< _AvgArmUtilTime << "%" << std::endl;
}
