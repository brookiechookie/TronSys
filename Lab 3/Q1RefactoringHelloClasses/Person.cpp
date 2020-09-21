// Person.cpp
//
// Date created:  6.9.20
// Creator:       Brooke Agostino
// Purpose:       Implementation for the class of Person.
//                The methods include; greetings from one person to another,
//                error checking and reporting
// Modifications:
//



#include <iostream>
#include <string>

#include "Person.h"


//---Class implementation for Person---------------------------
// Init zeroes the hello count, and assigns a name
Person::Person( std::string Name )
{
    _helloCount = 0;
    _name = Name;
    _errorCount = 0;

    Report();

}

//-------------------------------------------------------------
// SendHello passes the information of two people on to the next method.
// It performs error checking to observe whether someone has said hello to
// themself. If they have not then the method invokes a reciprocation of a hello
void Person::SendHello( Person* pDest )
{

    ReceiveHello( pDest );

    // If there is no current error then allow a reciprocation of a hello
    if (_errorCount != 1)
    {
        pDest->ReceiveHello( this );
    }
    // Clear the error state so that we can start up with the next person
    else
    {
        _errorCount = 0;
    }

}


//-------------------------------------------------------------
// Report prints to the screen a persons name and their respective
// hello count
void Person::Report()
{
    std::cout << "[Count]: "<< _name
        << "'s hello count is " << _helloCount
        << std::endl;
}


//-------------------------------------------------------------
// ReceiveHello increases a persons hello count and displays to the
// screen the person who has received the hello
void Person::ReceiveHello()
{
    // Increase the hello count
    _helloCount++;

    std::cout << "[Received]: " << _name << " has received a hello"
    << std::endl;

    Report();

}

//-------------------------------------------------------------
// The second ReceiveHello prints to the screen who is saying
// hello to who. It also performs the error checking to see
// if someone is saying hello to themself
void Person::ReceiveHello(Person* pSource)
{
    std::cout << "[SendHello]: " << _name
        << " is saying hello to " << pSource->_name << std::endl;

    if ( _name == pSource->_name )
    {
        std::cout << "[ERROR]: " << _name
          << " is trying to to say hello to themself" << std::endl;

        _errorCount = 1; // Record if we are currently in an error state
    }
    else
    {
        // Record that a hello has been sent
        pSource->ReceiveHello();

    }

}

std::string Person::NameGetter()
{
    return _name;
}

/*
//-------------------------------------------------------------
// Within the Person class, allow a computer to say hello to a person.
// Print the greeting to the screen
void Person::Greeting( Computer* Cpoint )
{
    std::cout << "[SendHello]: " << Cpoint->_CompName
        << " is saying hello " << _name << std::endl;

    ReceiveHello();

}
*/
