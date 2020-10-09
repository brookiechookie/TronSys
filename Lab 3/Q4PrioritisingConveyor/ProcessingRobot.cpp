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
ProcessingRobot::ProcessingRobot( Conveyor* WhichConveyor, float MaxProcessingTime, int ErrorVal, int ShortOrLongProcessing )
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
    _ShortOrLong        = ShortOrLongProcessing;

}

//------------------------------------------------------------------------------
// The purpose of this function is to process a number of items within a fixed
// processing time frame, in either shorter or longer tasks prioritised
void ProcessingRobot::ProccessItemsTimed()
{

    // Reset all the relevant variables to their base value every time this
    // function is called
    _TotalTime          = 0;
    _UnderTimeLimit     = 1;
    _FirstItemTime      = 0;

    _CycleCount = _Conveyor->CycleCountGetter();

    std::cout << "[Proc]: Removing Items " << std::endl;
    while( _UnderTimeLimit )
    {
        // 1. Get either the shortest or longest processed item
        // 2. _ItemShort = _Conveyor->GetShortestProcTimeItem()
        // 3. Check for the error value
        // 4. If clear, then make sure we're still within the processing time frame
        // 5. Perform the required calculations lines of code
        // 6. Then for process item, we're going to need to know what the index
        //    is for the item that needs to be deleted

        // The variable ShortOrLong corresponds to the system prioritising
        // shorter or longer tasked activities.
        // 0 = Shorter tasks prioritised
        // 1 = Longer tasks prioritised
        if( _ShortOrLong == 0 )
        {
            _ItemProcTime   = _Conveyor->GetShortestItemProcTime();
            _ItemIndex      = _Conveyor->GetShortestItemIndex();
        }
        else if( _ShortOrLong == 1 )
        {
            _ItemProcTime   = _Conveyor->GetLongestItemProcTime();
            _ItemIndex      = _Conveyor->GetLongestItemIndex();
        }



        if( _ItemProcTime == float(_ErrorValue) )
        {
            // If this input is received from the function, this means that we
            // have exceeded the number of items that are in the array. So just
            // return from the while loop with the current calculated total time
            _UnderTimeLimit = 0;
            std::cout << "[Proc]: No more items in list left to process!" << std::endl;
        }
        else if( _TotalTime < _MaxTotalProcTime )
        {

            if( (_TotalTime + _ItemProcTime ) <= _MaxTotalProcTime )
            {

                _TotalTime = _TotalTime + _ItemProcTime;

                //std::cout << "[Proc]: Safe to add next time, new tot time = " << _TotalTime << std::endl;

                _TimeOFFCalculated = ( _CycleCount * _MaxTotalProcTime ) + _TotalTime - _ItemProcTime;
                _Conveyor->SettingItemTimeOFF( _TimeOFFCalculated );

                //std::cout << "[Proc]: Item Time OFF = " << _TimeOFFCalculated << std::endl;

                // Before we get rid of the item we quickly want to store the
                // amount of time that this item waited before being processed.
                CalcWaitTime( _ItemIndex );

                // We also wish to keep a count of the processing time for all the items
                _TotalItemProcTime = _TotalItemProcTime + _ItemProcTime;
                //std::cout << "[Proc]: Adding item proc time = " << _ItemProcTime << " sec" << std::endl;
                //std::cout << "[Proc]: Total Proc time =  " << _TotalItemProcTime << " sec" << std::endl;
                ProcessItem( _ItemIndex );

            }
            else
            {
                _UnderTimeLimit = 0;
                std::cout << "[Proc]: Time Frame Reached " << std::endl;
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
void ProcessingRobot::CalcWaitTime( int ItemIndex )
{
    //_ItemTimeON     = _Conveyor->GetFirstItemTimeON( );

    _ItemTimeON     = _Conveyor->GetItemTimeOn( ItemIndex );
    _ItemWaitTime   = _TimeOFFCalculated - _ItemTimeON;
    _TotalWaitTime  = _TotalWaitTime + _ItemWaitTime;

    std::cout << "[Proc]: Calc Item Wait Time = " << _ItemWaitTime << " sec" << std::endl;
    std::cout << "[Proc]: Total Wait Time = " << _TotalWaitTime << " sec" << std::endl;
}


//------------------------------------------------------------------------------
// This function removes items from the conveyor and also counts the number
// of items that have been processed in total
void ProcessingRobot::ProcessItem( int ItemIndex )
{
    _Conveyor->RemoveItem( _ItemIndex );
    _TotNumProcItem = _TotNumProcItem + 1;
    std::cout << "[Proc]: Total # Proc Items = " << _TotNumProcItem << std::endl;

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
    //std::cout << "Robot arm usage time = " << _RobotArmUsageTime << std::endl;
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
    _AvgItemProcTime = float(_TotalItemProcTime)/float( _TotNumProcItem );
    std::cout << "Average Processing Time per Item = " << _AvgItemProcTime <<
    " sec" << std::endl;
}


//------------------------------------------------------------------------------
// This function reports to the screen whether shorter or longer tasks were
// prioritised
void ProcessingRobot::ReportPriorityType()
{
    if( _ShortOrLong == 0 )
    {
        std::cout << "Shorter Tasks Prioritised" << std::endl;
    }
    else if( _ShortOrLong == 1 )
    {
        std::cout << "Longer Tasks Prioritised" << std::endl;
    }

}
