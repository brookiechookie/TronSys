// ProcessingRobot.h
//
// Creator:   Brookie
// Date:      6.10.20
// Purpose:   Header file for ProcessingRobot class in Simulated Conveyor Belt

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
        ProcessingRobot( Conveyor* WhichConveyor, float MaxProcessingTime, int ErrorVal, int ShortOrLongProcessing );
        void      ProcessItem( int ItemIndex );
        void      ProccessItemsTimed();
        void      AvgArmUtil();
        void      CalcWaitTime( int ItemIndex );
        void      AvgItemWaitTime();
        void      FindAvgItemProcTime();
        void      ReportPriorityType();


    private:
        Conveyor* _Conveyor;
        int       _MaxItemRemoval;
        int       _NumItemsOnConv;
        int       _ProcessedItems;
        Item*     _Item;
        float     _IndividualItemProcTime;
        float     _TotalTime;
        int       _UnderTimeLimit;
        float     _FirstItemTime;
        float     _MaxTotalProcTime;
        int       _CycleCount;
        float     _RobotArmUsageTime;
        float     _AvgArmUtilTime;
        float     _TotalRunTime;
        float     _TimeOFFCalculated;
        float     _ItemTimeON;
        int       _TotNumProcItem;
        float     _ItemWaitTime;
        float     _TotalWaitTime;
        float     _AVGWaitTime;
        int       _ErrorValue;
        float     _AvgItemProcTime;
        float     _TotalItemProcTime;
        float     _ShortestItemTime;
        int       _ShortestTimeItemIndex;

        float     _ItemProcTime;
        int       _ItemIndex;
        int       _ShortOrLong;

};

#endif
