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
    // Creating the first instance of the different classes
    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;

    // Creating the second instance of Processor which represents the second
    // robot. Note that a second conveyor and second loader are not required
    // since this second robot arm is also working on the same conveyor as the
    // first robot arm
    ProcessingRobot secondRobotArm;

    // Initialise the first instance of the varying classes
    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor, 5 );

    // Initialise the second robot arm with a define processing number
    secondRobotArm.Init( &myConveyor, 1 );


    while( 1 )
    {
        std::cout << "___________________________________________________"
        << std::endl;

        myLoader.AddItems();
        myConveyor.Report();

        std::cout << "[First Robot Arm] "; // First robot arm processor
        myProcessor.ProcessItems( );

        std::cout << "[Second Robot Arm] "; // Second robot arm processor
        secondRobotArm.ProcessItems( );


        myProcessor.CycleReport(); // Advises us the number of cycles that the
                                   // program is currently on

        std::cout << "[First Robot Arm]: " << std::endl; // First robot arm processor
        myProcessor.ItemReport(); // Reports Total number of processed items by
                                  // the first robot arm
        myProcessor.Report( );


        std::cout << "[Second Robot Arm]: " << std::endl; // Second robot arm processor
        secondRobotArm.ItemReport(); // Reports the total number of processed
                                      // items by the second robot arm
        secondRobotArm.Report();


        myConveyor.Report( );
        std::cout << "Total Processed Items: " << myProcessor.TotalItems( ) +
        secondRobotArm.TotalItems( ) << std::endl;

        // Provides extra reporting and functionality 
        myProcessor.ConveyorLimit( );
        myProcessor.OverflowBin( );
        myProcessor.OverflowBinReport( );

    }
}
