// Conveyor.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Implementation file for a simulated conveyor belt
//
// Modifications:
//


#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "Conveyor.h"

//---------------------------------------------------------------
// Initialise method - setting variables to zero
Conveyor::Conveyor()
{
    _NumItemsOnConveyor = 0;
}


//------------------------------------------------------------------------------
// Copy Constructor for Conveyor
Conveyor::Conveyor( const Conveyor& other )
{
    std::cout << "[STUFFEDUP ]: Copy Created of Conveyor Object :(" << std::endl;
}

//------------------------------------------------------------------------------
// Destructor
Conveyor::~Conveyor()
{
    std::cout << "[DTor]: Conveyor signing off" << std::endl;
}

//---------------------------------------------------------------
// Method that adds items on to the conveyor according to the input
void Conveyor::AddItems( int n )
{
    _NumItemsOnConveyor += n;
}

//---------------------------------------------------------------
// Method that removes items on to the conveyor according to the input
// The items on the conveyor can never go below zero
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);
}

//---------------------------------------------------------------
// Method that reports how many items are on the conveyor currently
void Conveyor::Report()
{
    std::cout << "[Conv]: Items on Conveyor: " << _NumItemsOnConveyor << std::endl;

}

//---------------------------------------------------------------
// Getter method that returns how many items are on the conveyor currently
int Conveyor::getConvItemNum()
{
    return _NumItemsOnConveyor;
}
