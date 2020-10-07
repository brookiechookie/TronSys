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
    _TotNumProcItem     = 0;
    _TotalWaitTime      = 0;

}


//------------------------------------------------------------------------------
// This function removes items from the conveyor
void ProcessingRobot::ProcessItems()
{
    _Conveyor->RemoveItems( _CurrentIndex );

    // Count the number of items that have been processed
    _TotNumProcItem = _TotNumProcItem + _CurrentIndex;
    std::cout << "[Proc]: Total number of proc items = " << _TotNumProcItem << std::endl;
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

    _CycleCount = _Conveyor->CycleCountGetter();
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
            //std::cout << "[Proc]: Total Time = "<< _TotalTime << std::endl;

            if( (_TotalTime + _CurrentItemTime) <= _MaxTotalProcTime )
            {
                _TotalTime = _TotalTime + _CurrentItemTime;

                std::cout << "[Proc]: Safe to add next time, new tot time = " << _TotalTime << std::endl;

                _TimeOFFCalculated = ( _CycleCount * _MaxTotalProcTime ) + _TotalTime;
                _Conveyor->SettingItemTimeOFF( _CurrentIndex, _TimeOFFCalculated );
                std::cout << "[Proc]: Item Time OFF = " << _TimeOFFCalculated << std::endl;

                // Before we get rid of the item we quickly want to store the
                // amount of time that this item waited before being processed.
                CalcWaitTime( _CurrentIndex );



                _CurrentIndex++;
            }
            else
            {
                _UnderTimeLimit = 0;
                std::cout << "[Proc]: Not safe to process next item" << std::endl;
            }
        }

    }


    _RobotArmUsageTime = _RobotArmUsageTime + _TotalTime;
    std::cout << "[Proc]: Current Index = "<< _CurrentIndex << std::endl;

}



//------------------------------------------------------------------------------
// This function calculates the average amount of time that the robot arm is
// being used. In order to do this a time count of how much the arm is being
// used per cycle is stored and divided by the total amount of time that has
// passed in the system.
void ProcessingRobot::AvgArmUtil()
{
    _TotalRunTime = _CycleCount*_MaxTotalProcTime;

    _AvgArmUtilTime = ( _RobotArmUsageTime/_TotalRunTime ) * 100;
    std::cout << "Cycle Count = " << _CycleCount << std::endl;
    std::cout << "Total Run Time = " << _TotalRunTime << std::endl;
    std::cout << "Robot arm usage time = " << _RobotArmUsageTime << std::endl;
    std::cout << "Avg Arm Util Time = " << _AvgArmUtilTime << std::endl;

    std::cout << "[Proc]: Average Arm Util Time = "<< _AvgArmUtilTime << "%" << std::endl;
}

//------------------------------------------------------------------------------
//
void ProcessingRobot::CalcWaitTime( int currentIndex )
{
    _ItemTimeON = _Conveyor->TimeONGetGet( currentIndex );
    _ItemWaitTime = _TimeOFFCalculated - _ItemTimeON;

    _TotalWaitTime = _TotalWaitTime + _ItemWaitTime;
}

//------------------------------------------------------------------------------
// To calculate the average wait time, we must the total weight time of all the
// items by the number of items that has been processed
void ProcessingRobot::AvgItemWaitTime()
{
    _AVGWaitTime = _TotalWaitTime/float(_TotNumProcItem);
    std::cout << "[Proc]: AVG Item wait time = "<< _AVGWaitTime << " sec"<< std::endl;

}
