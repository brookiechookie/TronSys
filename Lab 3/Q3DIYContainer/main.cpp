// main.cpp
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Main file for the simulated conveyor robot

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <stdlib.h>
#include <vector>       // Vector STL

#include "Conveyor.h"
#include "LoadingRobot.h"
#include "ProcessingRobot.h"
#include "Item.h"



int main()
{
    // This is fixed time window in which the robot can process items in
    float MaxProcessingTime = 16.1;

    // This value is an arbitrarily large integer which serves as an error checking
    // value. The error checking is if the processing robot is up to the point
    // where it has processed all the items in the vector, and it now needs to
    // stop as there is no more items left to process. If this value is received
    // then the processing robot knows that there is no items to process right now.
    int   ErrorVal = 999;

    Conveyor myConveyor( MaxProcessingTime, ErrorVal );
    LoadingRobot myLoader( &myConveyor );
    ProcessingRobot myProcessor( &myConveyor, MaxProcessingTime, ErrorVal );

    int i = 0;
    int _DesiredCycles = 5;

    while( i < _DesiredCycles )
    {
        std::cout << "__________________________________________________ " << std::endl;

        myLoader.AddItems();
        //myConveyor.Report();
        //myProcessor.ProccessItemsTimed();
        //myProcessor.ProcessItems();
        //myConveyor.Report();

        i++;
    }

/*
    // Provide the final report
    std::cout << "***************************************************" << std::endl;
    std::cout << "                  Final Report                     " << std::endl;
    myProcessor.AvgArmUtil();
    myProcessor.AvgItemWaitTime();
    myConveyor.ReportOverflows();
    myConveyor.AvgNumbAddedItems();
    myProcessor.FindAvgItemProcTime();
    std::cout << "***************************************************" << std::endl;
*/

}
