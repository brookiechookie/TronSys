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


int main()
{
    // Create the instances of the different classes
    Conveyor        myConveyor;
    LoadingRobot    myLoader          ( myConveyor     );


    ProcessingRobot myProcessor       ( myConveyor, 5  );
    ProcessingRobot secondRobotArm    ( myConveyor, 1  );

    bool run = 1;
    while( run )
    {
        std::cout << "___________________________________________________"
        << std::endl;

        // Items added to conveyor and reports to the screen
        myLoader.AddItems();
        myConveyor.Report();

        // Both robot arms process items. Stats and Cycle count displayed
        std::cout << "[Main]: Arm 1 - ";
        myProcessor.ProcessItems( );
        std::cout << "[Main]: Arm 2 - ";
        secondRobotArm.ProcessItems( );
        myProcessor.CycleReport();

        // Stats on each arm displayed
        std::cout << "[Main]: Arm 1 Stats " << std::endl;
        myProcessor.ItemReport();
        myProcessor.Report( );
        std::cout << "[Main]: Arm 2 Stats " << std::endl;
        secondRobotArm.ItemReport();
        secondRobotArm.Report();

        // Reporting and stats displayed to the screen
        myConveyor.Report( );
        std::cout << "[Main]: Total Processed Items: " <<
        myProcessor.TotalItems( ) + secondRobotArm.TotalItems( ) << std::endl;
        myProcessor.ConveyorLimit( );
        myProcessor.OverflowBin( );
        myProcessor.OverflowBinReport( );

        //run = 0;
    }

}
