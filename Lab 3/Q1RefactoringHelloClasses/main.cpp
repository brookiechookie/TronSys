// main.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau. Edits by Brooke Agostino
// Purpose:       Main file for lab 1 assignment.
//                Example of how classes interact and creating a multi file
//                project. Computers can say hello to people but not vice versa.
// Modifications:
//


#include <iostream>
#include <string>

#include "Person.h"
#include "Computer.h"


//-------------------------------------------------------------
int main()
{

    Person Alice; // Alice is an instance of the class Person
    Person Bob;   // Bob is another instance of Person
    Person Carol; // Make Carol!
    Computer Hal; // Hal is an instance of the class computer

    // Assign names to each object
    Alice.Init( "Alice" );
    Bob.Init( "Bob" );
    Carol.Init( "Carol" );
    Hal.Creator( "Hal" );   // Give the instance of Hal an official name

    // Let's introduce Alice and Bob
    Alice.SendHello( &Bob );

    // Let's make them say hello to themselves. This should cause an error
    Alice.SendHello( &Alice );
    Bob.SendHello( &Bob );

    // Get Carol to say hello to Alice and Bob
    Carol.SendHello( &Alice );
    Carol.SendHello( &Bob );

    // Introduce Hal the computer and Carol
    Carol.Greeting( &Hal );

}
