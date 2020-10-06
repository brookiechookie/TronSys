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
        //int ItemsBeingAdded = myLoader.AddItems();

        myLoader.AddItems();
        //IndiItem *theNewItem = new IndiItem( ItemsBeingAdded );
//        //ItemParent  NewItem( ItemsBeingAdded );
        //NewItem.ItemParent( ItemsBeingAdded );

        //IndiItem NewItem( ItemsBeingAdded );

        /*
        for( int i = 1; i <= ItemsBeingAdded; i++ )
        {
            int _ItemID = rand() % 999;
            myVector.push_back( _ItemID );

            std::cout << "[Main]: New Item " << i << " added to HugeVec. Item ID: " <<
            _ItemID << std::endl;
        }
        print_container( myVector );
        */


        myConveyor.Report();
        myProcessor.RemovalItemReport();
        myProcessor.ProcessItems();
        //myItem->AmountOfItemsRemoved();

        myConveyor.Report();

/*
        int ItemsRemoving = myProcessor.GetProcessedItems();
        std::cout << "[Main]: The number of items to remove is " << ItemsRemoving << std::endl;
        for( int i = 0; i < ItemsRemoving; i++ )
        {
            std::cout << "[Main]: Index " << i << ", Item ID " << myVector.at(i) <<
            " is being removed" << std::endl;

        }
        myVector.erase( myVector.begin(), myVector.begin() + ItemsRemoving );
        print_container( myVector );
*/

        //myItem->DeleshItems();

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
