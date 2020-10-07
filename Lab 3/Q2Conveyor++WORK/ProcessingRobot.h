// ProcessingRobot.h
//
// Header file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _PROCESSINGROBOT_H
#define _PROCESSINGROBOT_H

#include "Conveyor.h"
#include "Item.h"


//-------------------------------------------------------------------
// Simulate a processing robot that removes items from a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will use.
class ProcessingRobot
{
    public:
        void Init( Conveyor* WhichConveyor, int NumItemsToBeRemoved, float MaxProcessingTime );
        void ProcessItems();
        int GetProcessedItems();
        void RemovalItemReport();
        void ProccessItemsTimed();
        void AvgArmUtil();

    private:
        Conveyor* _Conveyor;
        int _MaxItemRemoval;
        int _NumItemsOnConv;
        int _ProcessedItems;
        Item* _Item;
        float _IndividualItemProcTime;
        float _TotalTime;
        int   _UnderTimeLimit;
        int _CurrentIndex;
        float _CurrentItemTime;
        float _MaxTotalProcTime;
        int _CycleCount;
        float _RobotArmUsageTime;
        float _AvgArmUtilTime;
        float _TotalRunTime;

};

#endif
