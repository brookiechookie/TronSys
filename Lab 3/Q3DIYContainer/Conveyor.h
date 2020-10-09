// Conveyor.h
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Header file for Conveyor class in Simulated Conveyor Belt

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

#include <vector>     // Vector STL
#include "Item.h"
#include "DoublyLinkedList.h"

//---------------------------------------------------------------
// Simulate a conveyor belt. This version just counts how many
// objects are on the belt, and accepts requests to add and remove
// objects.
class Conveyor
{
    public:
        Conveyor( float MaxProcessingTime, int ErrorValue );
        void  AddItems( int n );
        void  RemoveItem( );
        void  Report();
        float GetFirstItemProcTime();
        int   CycleCountGetter();
        void  SettingItemTimeOFF( float TimeOFFcalculated );
        float GetFirstItemTimeON( );
        void  ReportOverflows();
        void  AvgNumbAddedItems();



    private:
        std::vector<Item*> MyListOfItems;
        int   _NumItemsOnConveyor;
        int   _CycleCount;
        Item* pItems;
        int   _TotalItemsInPointer;
        int   _i;
        int   _UniqueID;
        float _ProcTimeReturning;
        float _MaxProcessingTime;
        float _TimeONCalculated;
        float _ItemTimeON;
        int   _ErrorValue;
        int   _Overflow;
        int   _TotalNumItemsAdded;
        float _AvgNumbItems;

        DoublyLinkedList myList;

};



#endif
