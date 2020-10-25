// ProcessingRobot.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Implementation file for a robot that processes items off a conveyor belt
//
// Modifications:
//

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <stdlib.h>

#include "ProcessingRobot.h"

//---------------------------------------------------------------
// This initalise method sets all the variables to point to the correct
// variable or object, or sets the variable to zero
void ProcessingRobot::Init( Conveyor* WhichConveyor, int ProcessingNumber )
{
    _Conveyor = WhichConveyor;

    _MaxProcessingNum = ProcessingNumber;

    _ProcessedItems = 0;

    _CurrentLoad = 0;

    _AverageLoad = 0;

    _TotalProcessedItems = 0;

    _AverageLoadUsage = 0;

    _CountCycle = 0;

    _NumberOfItemOnConv = 0;

    _OverflowBinContents = 0;

    _MaxItemsOverflowBin = 0;
}

//---------------------------------------------------------------
// This method calculates how many items the processing robot is
// getting through. It also counts the number of cycles and the
// total number of processed items. It also removes items from
// the conveyor each cycle.
void ProcessingRobot::ProcessItems( )
{

    _CountCycle++; // Count each process cycle

    _NumberOfItemOnConv = _Conveyor->getConvItemNum(); // Get the number of items on the conveyor

    if ( _NumberOfItemOnConv <= _MaxProcessingNum )
    {
        _ProcessedItems = _NumberOfItemOnConv;

        _TotalProcessedItems += _ProcessedItems;
    }
    else if( _NumberOfItemOnConv > _MaxProcessingNum )
    {
        _ProcessedItems = _MaxProcessingNum;

        _TotalProcessedItems += _ProcessedItems;
    }


    _Conveyor->RemoveItems( _MaxProcessingNum );

    std::cout << "Processed Items: " << _ProcessedItems << std::endl;
}

//---------------------------------------------------------------
//
void ProcessingRobot::ItemReport()
{
    std::cout << "- Number of Processed Items: " << _TotalProcessedItems << std::endl;

}

//---------------------------------------------------------------
// This method simply prints the current cycle count
void ProcessingRobot::CycleReport()
{
    std::cout << "The Current Count Cycle is: " << _CountCycle << std::endl;
}

//---------------------------------------------------------------
// The Report method calculates the load of the processing robot. Full capacity
// of the processing robot corresponds to the robot processing the max
// number of items per cycle.
// To find the true average we need the total number of processed items and
// then divide that by the number of conveyor cycles currently processed
// multipled by the _MaxProcessingNum.
// The formula is; ProcessingPower = #(processedItems/_MaxProcessingNum)*100;
void ProcessingRobot::Report( )
{
    _AverageLoadUsage = ( double(_TotalProcessedItems) / ( double(_CountCycle)*double(_MaxProcessingNum) ) )*100;
    std::cout << "- Average Load Usage: " << _AverageLoadUsage << "%" << std::endl;
}

//---------------------------------------------------------------
// This method simply returns the total number of processed items thus far
int ProcessingRobot::TotalItems()
{
    return _TotalProcessedItems;
}

//---------------------------------------------------------------
// This method provides a limit to the number of items that can
// possibly be on the conveyor at any one time. If this limit is
// exceeded then an error message appears and the program is terminated.
void ProcessingRobot::ConveyorLimit( )
{
    if ( _NumberOfItemOnConv > _ConveyorItemLimit )
    {
        std::cout << "[ERROR]: The number of items on the conveyor has exceeded the limit of " <<
        _ConveyorItemLimit << ". PROGRAM TERMINATED." << std::endl;

        exit(0);

    }
}

//---------------------------------------------------------------
// This method is a device that aids the conveyor process items. This device
// is an overflow bin. When the number of items on the conveyor exceeds a certain
// number of items then the overflow bin provides an area for these items to be
// stored. Then once the conveyor and the processing robots have reached a stable
// number of items on the conveyor, the overflow bin starts returning the stored
// items to the belt
void ProcessingRobot::OverflowBin( )
{
    if( _NumberOfItemOnConv > 50 )
    {
        _Conveyor->RemoveItems( _OverflowRemovalRate );
        std::cout << "Overflow Bin: " << _OverflowRemovalRate <<
        " item removed from conveyor" << std::endl;

        _OverflowBinContents++; // Put the item removed from the conveyor into
                                // the overflow bin

        _Conveyor->Report();


    }
    else if( _NumberOfItemOnConv < 10 )
    {

        // We have to make sure that the overflow bin actually has items in it.
        // I.e. we dont want to add items back to the conveyor that were not
        // taken off in the first place. So if there is items in the overflow
        // bin, add these back to the conveyor at a rate of one item per cycle
        // and then record this by taking one item out of the overflow bin.
        if( _OverflowBinContents > 0 )
        {
            _Conveyor->AddItems( _OverflowAddition );
            std::cout << "Overflow Bin: " << _OverflowAddition <<
            " item added to the conveyor" << std::endl;

            _OverflowBinContents--;

            _Conveyor->Report();
        }

    }

}

//---------------------------------------------------------------
// This method reports the number of items that are currently in the bin and
// also keeps track of the max number of items that have ever been in the bin
// at any one given time
void ProcessingRobot::OverflowBinReport()
{
    // Printing the number of elements currently in the overflow bin
    std::cout << "Number of Items in Overflow Bin: " << _OverflowBinContents
    << std::endl;

    // Calculating the max items that have been in the overflow bin
    if( _OverflowBinContents > _MaxItemsOverflowBin )
    {
        _MaxItemsOverflowBin = _OverflowBinContents;
    }

    std::cout << "Max Number of Items stored in Overflow Bin: " << _MaxItemsOverflowBin
    << std::endl;

}
