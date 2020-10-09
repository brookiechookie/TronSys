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

    // This variable controls whether the program priorities either shorter or
    // longer tasks.
    // 0 = Shorter tasks prioritised
    // 1 = Longer tasks prioritised
    int   ShortOrLongProcessing;
    int   InputError = 1;

    std::cout << "Hi User. Please advise whether you desire shorter or longer"<<
    " tasks to be prioritised. \n 0 = Shorter Tasks Prioritised \n 1 = Longer"<<
    " Tasks Prioritised" << std::endl;


    while( InputError )
    {
        std::cin >> ShortOrLongProcessing; // Take in User Input

        // If the user input is not 1 or 0, then tell them invalid input, and
        // allow them to try again
        if( ShortOrLongProcessing == 1 || ShortOrLongProcessing == 0 )
        {
            InputError = 0;
        }
        else
        {
            std::cout << "Invalid Input! Please try again." << std::endl;
        }
    }



    Conveyor myConveyor( MaxProcessingTime, ErrorVal );
    LoadingRobot myLoader( &myConveyor );
    ProcessingRobot myProcessor( &myConveyor, MaxProcessingTime, ErrorVal, ShortOrLongProcessing );

    int i = 0;
    int _DesiredCycles = 1000;

    while( i < _DesiredCycles )
    {
        std::cout << "__________________________________________________ " << std::endl;

        myLoader.AddItems();
        myConveyor.Report();
        myProcessor.ProccessItemsTimed();
        myConveyor.Report();

        i++;
    }


    // Provide the final report
    std::cout << "__________________________________________________ " << std::endl;
    std::cout << "***************************************************" << std::endl;
    std::cout << "*                  Final Report                   *" << std::endl;
    std::cout << "***************************************************" << std::endl;
    myProcessor.ReportPriorityType();
    myProcessor.AvgArmUtil();
    myProcessor.AvgItemWaitTime();
    myConveyor.ReportOverflows();
    myConveyor.AvgNumbAddedItems();
    myProcessor.FindAvgItemProcTime();
    std::cout << "***************************************************" << std::endl;

}
