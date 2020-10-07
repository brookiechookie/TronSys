// Conveyor.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

#include <vector>     // Vector STL
#include "Item.h"

//---------------------------------------------------------------
// Simulate a conveyor belt. This version just counts how many
// objects are on the belt, and accepts requests to add and remove
// objects.
class Conveyor
{
    public:
        void Init( float MaxProcessingTime );
        int AddItems( int n );
        void RemoveItems( int n );
        void Report();
        int GetNumItemsOnConveyor();
        float GetItemProcTime( int _ItemIndex );
        int CycleCountGetter();
        void SettingItemTimeOFF( int currentIndex, float TimeOFFcalculated );
        float TimeONGetGet( int currentIndex );


    private:
        int _NumItemsOnConveyor;
        std::vector<Item*> MyListOfItems;
        int _CycleCount;
        Item* pItems;
        int _TotalItemsInPointer;
        int _i;
        int _UniqueID;
        float _ProcTimeReturning;
        float _MaxProcessingTime;
        float _TimeONCalculated;
        float _ItemTimeON;


};



#endif
