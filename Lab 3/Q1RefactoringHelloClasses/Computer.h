// Computer.h
//
// Date created:  6.9.20
// Creator:       Brooke Agostino
// Purpose:       Header file for the class of Computer.
//                Computers can say hello to people but not vice versa.
//
// Modifications: 21.9.20 - Brooke A: Added a constructor for this class
//                21.9.20 - Brooke A: Corrected code so now the computer saying
//                          hello to a person is now in the computer classs instead
//                          of being in the person class. This is in response to
//                          my tutors feedback from lab 1. 
//


#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "Person.h"

class Computer
{
    public:
        Computer( std::string ComputerName );   // Constructor for computer
        void SendHelloComp( Person* WhichPerson );

    private:
        Person* _Person;                        // Pointer to a person
        std::string _CompName;                  // The Computers name
};


#endif
