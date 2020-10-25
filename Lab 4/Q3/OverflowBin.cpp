// OverflowBin.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Implementation file for a robot that can load items onto a
//                conveyor belt
//
// Modifications:
//

#include <cstdlib>      // rand

#include "LoadingRobot.h"
#include "Conveyor.h"
#include "OverflowBin.h"

OverflowBin::OverflowBin( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}
//---------------------------------------------------------------
// This method is a device that aids the conveyor process items. This device
// is an overflow bin. When the number of items on the conveyor exceeds a certain
// number of items then the overflow bin provides an area for these items to be
// stored. Then once the conveyor and the processing robots have reached a stable
// number of items on the conveyor, the overflow bin starts returning the stored
// items to the belt
void OverflowBin::UseOverflowBin( )
{
    _NumberOfItemOnConv = _Conveyor->getConvItemNum();

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
void OverflowBin::OverflowBinReport()
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
