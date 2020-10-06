// Item.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _ITEMPARENT_H
#define _ITEMPARENT_H

#include "Conveyor.h"
#include "ProcessingRobot.h"
#include <vector>     // Vector STL
#include <iostream>     // std::cout
#include <cstdlib>      // For rand()

class ItemParent
{
    public:
        ItemParent();
        //ItemParent( int NewItemsAdded );
        ItemParent( Conveyor* WhichConveyor, ProcessingRobot* WhichProcessor, int NumberOfItemsToBeRemoved );
        void AmountOfItemsRemoved();
        void DeleshItems();
        void print_container(const std::vector<int>& insertVector );


    protected:                // Protected classes allow derived classes to access the variable
        Conveyor* _Conveyor;
        ProcessingRobot* _ProcessingRobot;
        std::vector<int> TheHugeVector;
        int _NumItemsRemoved;
        int _ItemID;
        int ItemsRemoving;


};



#endif
