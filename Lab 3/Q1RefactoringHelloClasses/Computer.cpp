// Computer.cpp
//
// Date created:  6.9.20
// Creator:       Brooke Agostino
// Purpose:       Implementation for the class of Computer.
//                Computers can say hello to people but not vice versa.
// Modifications:
//


#include <iostream>
#include <string>

#include "Computer.h"

//----------------------------------------------------------------------
// Create an initalise method that gives a Computer an official name and
// prints their name to the screen
Computer::Computer( std::string ComputerName )
{
    _CompName = ComputerName;

    std::cout << "[NewComp]: "<< _CompName
        << " the Computer has been created "
        << std::endl;

}

//-------------------------------------------------------------
// This function allows the computer to say hello to a person
void Computer::SendHelloComp( Person* WhichPerson )
{
    _Person = WhichPerson;

    std::cout << "[SendHello]: " << _CompName
        << " is saying hello to " << _Person->NameGetter() << std::endl;

}
