// main.cpp
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau. Edits by Brooke Agostino
// Purpose:       Main file for lab 1 assignment.
//                Example of how classes interact and creating a multi file
//                project. Computers can say hello to people but not vice versa.
// Modifications: 21.9.20 Code refactored and structure restyled in response to
//                feedback from lab 1.
//


#include <iostream>
#include <string>

#include "Person.h"
#include "Computer.h"


//-------------------------------------------------------------
int main()
{
    // Instantiate new objects for people and computer
    Person Alice( "Alice" ); // Alice is an instance of the class Person
    Person Bob( "Bob" );   // Bob is another instance of Person
    Person Carol( "Carol" ); // Make Carol!
    Computer Hal( "Hal" ); // Hal is an instance of the class computer

    // Let's introduce Alice and Bob
    Alice.SendHello( &Bob );

    // Let's make them say hello to themselves. This should cause an error
    Alice.SendHello( &Alice );
    Bob.SendHello( &Bob );

    // Get Carol to say hello to Alice and Bob
    Carol.SendHello( &Alice );
    Carol.SendHello( &Bob );

    // Get the Computer to say hello to Carol, note that Carol's hello count
    // must go up but the computer itself does not have a hello count.
    Hal.SendHelloComp( &Carol );
    Carol.ReceiveHello();

}
