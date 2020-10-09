// ProcessingRobot.cpp
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Implementation file for the ProcessingRobot class


#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <vector>       // vector

#include "ProcessingRobot.h"
#include "Conveyor.h"
#include "Item.h"

//------------------------------------------------------------------------------
// Constructor for Processing Robot
ProcessingRobot::ProcessingRobot( Conveyor* WhichConveyor, float MaxProcessingTime, int ErrorVal )
{
    _Conveyor           = WhichConveyor;
    _MaxTotalProcTime   = MaxProcessingTime;
    _CycleCount         = 0;
    _RobotArmUsageTime  = 0;
    _TotNumProcItem     = 0;
    _TotalWaitTime      = 0;
    _ErrorValue         = ErrorVal;
    _TotalItemProcTime  = 0;
    _AvgItemProcTime    = 0;

}


//------------------------------------------------------------------------------
// The purpose of this function is to process a number of items within a fixed
// processing time frame.
// Steps:
//      1.  Get the Processing time private variable of the first
//          item in the vector
//      2.  Add this items processing time to a variable storing the count
//      3.  Once the count passes a certain value, we have maxed out on time
//          so feed into the ProcessItems function how many items have managed
//          to be processed.
//
void ProcessingRobot::ProccessItemsTimed()
{

    // Reset all the relevant variables to their base value every time this
    // function is called
    _TotalTime          = 0;
    _UnderTimeLimit     = 1;
    _FirstItemTime      = 0;

    _CycleCount = _Conveyor->CycleCountGetter();

    while( _UnderTimeLimit )
    {
        _FirstItemTime = _Conveyor->GetFirstItemProcTime();

        if( _FirstItemTime == float(_ErrorValue) )
        {
            // If this input is received from the function, this means that we
            // have exceeded the number of items that are in the array. So just
            // return from the while loop with the current calculated total time
            _UnderTimeLimit = 0;
            std::cout << "[Proc]: No more items left to process! " << std::endl;
        }
        else if( _TotalTime < _MaxTotalProcTime )
        {
            //std::cout << "[Proc]: Total time is currently less than max time " << std::endl;
            //std::cout << "[Proc]: Max Time = "<< _MaxTotalProcTime << std::endl;
            //std::cout << "[Proc]: Total Time = "<< _TotalTime << std::endl;

            if( (_TotalTime + _FirstItemTime) <= _MaxTotalProcTime )
            {
                _TotalTime = _TotalTime + _FirstItemTime;

                std::cout << "[Proc]: Safe to add next time, new tot time = " << _TotalTime << std::endl;

                _TimeOFFCalculated = ( _CycleCount * _MaxTotalProcTime ) + _TotalTime;
                _Conveyor->SettingItemTimeOFF( _TimeOFFCalculated );

                std::cout << "[Proc]: Item Time OFF = " << _TimeOFFCalculated << std::endl;

                // Before we get rid of the item we quickly want to store the
                // amount of time that this item waited before being processed.
                CalcWaitTime( );

                // We also wish to keep a count of the processing time for all the items
                _TotalItemProcTime = _TotalItemProcTime + _FirstItemTime;
                ProcessItem( );

            }
            else
            {
                _UnderTimeLimit = 0;
                //std::cout << "[Proc]: Not safe to process next item" << std::endl;
            }
        }

    }

    _RobotArmUsageTime = _RobotArmUsageTime + _TotalTime;
    //std::cout << "[Proc]: Current Index = "<< _CurrentIndex << std::endl;

}


//------------------------------------------------------------------------------
// This function is called every time an item is being processed. Before it
// gets removed we want to store the amount of time it was waiting on the
// conveyor line in order to calculate average wait time
void ProcessingRobot::CalcWaitTime( )
{
    _ItemTimeON = _Conveyor->GetFirstItemTimeON( );
    _ItemWaitTime = _TimeOFFCalculated - _ItemTimeON;

    _TotalWaitTime = _TotalWaitTime + _ItemWaitTime;
}


//------------------------------------------------------------------------------
// This function removes items from the conveyor and also counts the number
// of items that have been processed in total
void ProcessingRobot::ProcessItem( )
{
    _Conveyor->RemoveItem( );

    _TotNumProcItem = _TotNumProcItem + 1;
    //std::cout << "[Proc]: Total number of proc items = " << _TotNumProcItem << std::endl;
}


/*

//------------------------------------------------------------------------------
// This is a getter function returning the number of items that have been removed
int ProcessingRobot::GetProcessedItems()
{
    return _CurrentIndex;
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
    std::cout << "Total Run Time = " << _TotalRunTime << " sec"<< std::endl;
    // std::cout << "Robot arm usage time = " << _RobotArmUsageTime << std::endl;

    std::cout << "Average Arm Utilisation Time = "<< _AvgArmUtilTime << "%" << std::endl;
}


//------------------------------------------------------------------------------
// To calculate the average wait time, we must the total weight time of all the
// items by the number of items that has been processed
void ProcessingRobot::AvgItemWaitTime()
{
    _AVGWaitTime = _TotalWaitTime/float(_TotNumProcItem);
    std::cout << "Average Item Wait Time = "<< _AVGWaitTime << " sec"<< std::endl;

}

//------------------------------------------------------------------------------
// To calculate the average processing time of an item, we must know two things.
// 1. We must know the processing time of all the items.
// 2. We must know the total number of items that have been added.
// To calculate the avg proc time per item, we divide the total processing time
// of all the items by the number of items that have been added.
void ProcessingRobot::FindAvgItemProcTime()
{
    _AvgItemProcTime = _TotalItemProcTime/float( _TotNumProcItem );
    std::cout << "Average Processing Time per Item = " << _AvgItemProcTime <<
    " sec" << std::endl;
}

*/
