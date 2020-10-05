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
#include "Item.h"
#include "IndiItem.h"


int main()
{

    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;

    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor );

    while( 1 )
    {
        std::cout << "___________________________" << std::endl;
        myLoader.AddItems();
        myConveyor.Report();
        myProcessor.ProcessItems();
        myConveyor.Report();
    }



}


// Steps:
//    1. I want to create a vector that is going to load
