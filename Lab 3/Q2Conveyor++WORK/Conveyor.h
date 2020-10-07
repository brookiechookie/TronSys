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
        void Init();
        int AddItems( int n );
        void RemoveItems( int n );
        void Report();
        int GetNumItemsOnConveyor();

    private:
        int _NumItemsOnConveyor;
        //std::vector<int> MyListOfItems;
        std::vector<Item*> MyListOfItems;
        int _CycleCount;
        Item* pItems;
        int _TotalItemsInPointer;
        int _i;
        int _UniqueID;
};



#endif
