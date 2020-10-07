// main.cpp
//
// Main file for simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max
#include <stdlib.h>
#include <vector>       // Vector STL

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


    int NumberOfItemsToBeRemoved = 2;
    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor, NumberOfItemsToBeRemoved );

    //ItemParent *myItem = new ItemParent( &myConveyor, &myProcessor, NumberOfItemsToBeRemoved );

    int i = 0;
    //std::vector<int> myVector;

    while( i < 10 )
    {
        std::cout << "___________________________" << std::endl;

        myLoader.AddItems();

        myConveyor.Report();
        myProcessor.RemovalItemReport();
        myProcessor.ProcessItems();
        myConveyor.Report();

        i++;
    }

}


/*
//------------------------------------------------------------------------------
void Conveyor::print_container(const std::vector<Object*>& insertVector )
{
    for (auto &i : insertVector )
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}
*/
