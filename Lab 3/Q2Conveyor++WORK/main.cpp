// main.cpp
//
// Main file for simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <stdlib.h>

#include "Conveyor.h"
#include "LoadingRobot.h"
#include "ProcessingRobot.h"
#include "ItemParent.h"
#include "IndiItem.h"


int main()
{

    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;


    int NumberOfItemsToBeRemoved = 5;
    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor, NumberOfItemsToBeRemoved );

    ItemParent *myItem = new ItemParent( &myConveyor, &myProcessor, NumberOfItemsToBeRemoved );


    while( 1 )
    {
        std::cout << "___________________________" << std::endl;
        int ItemsBeingAdded = myLoader.AddItems();
        IndiItem *theNewItem = new IndiItem( ItemsBeingAdded );

        myConveyor.Report();
        myProcessor.RemovalItemReport();
        myProcessor.ProcessItems();
        myItem->AmountOfItemsRemoved();

        myConveyor.Report();
    }



}


// Steps:
//    1. I want to create a vector that is going to load
