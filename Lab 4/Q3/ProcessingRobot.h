// ProcessingRobot.h
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Header file for a robot that processes items off a conveyor belt
//
// Modifications:
//

#ifndef _PROCESSINGROBOT_H
#define _PROCESSINGROBOT_H

#include "Conveyor.h"


//-------------------------------------------------------------------
// Simulate a processing robot that processed items from a conveyor belt. There
// is a significant amount of functionality which includes an overflow bin,
// a max capacity of items and reporting.
// Note that Init sets a pointer to the conveyor the robot will use.
class ProcessingRobot
{
    public:
        ProcessingRobot( Conveyor& WhichConveyor, int ProcessingNumber );
        ProcessingRobot( const ProcessingRobot& other );
        ~ProcessingRobot();
        void ProcessItems( );
        void Report( );

        int _ConveyorItemLimit = 75;
        void ConveyorLimit( );
        int _OverflowRemovalRate = 1;
        int _OverflowAddition = 1;
        void OverflowBin( );
        void OverflowBinReport();
        void ItemReport();
        void CycleReport();
        int TotalItems();


    private:
        Conveyor& _Conveyor;
        int _MaxProcessingNum;    // Configurable variable that determines processing speed
        int _ProcessedItems;      // Counts the number of processed items per robot
        int _CurrentLoad;         // Count the processing power being utilised
        int _AverageLoad;         // Stores the value for average load usage of robots
        int _TotalProcessedItems; // Records the total number of processed items
        unsigned long int _CountCycle;        // Counts the cycles
        unsigned long int _AverageLoadUsage;  // Stores the value for average load usage of robots
        int _NumberOfItemOnConv;  // Stores the number of items on the conveyor
        int _OverflowBinContents; // Stores the number of items in the overflow bin
        int _MaxItemsOverflowBin; // Stores the max number of items that have been in the bin

};

#endif
