// Person.h
//
// Date created:  6.9.20
// Creator:       Brooke Agostino
// Purpose:       Header file for the class of Person.
//
// Modifications:
//


#ifndef _PROCESSINGROBOT_H
#define _PROCESSINGROBOT_H

#include "Person.h"
#include "Computer.h"

//---Class definition for Person-------------------------------
// This defines the interface for this class
class Person
{
    public:

      Person( std::string Name );   // initialise a person with a given name

      // say hello to another person;
      // the second person is specified using a pointer
      void SendHello( Person* pDest );

      // Returns a persons hello count
      void Report();

      // Increases a persons hello count and displays that the person has
      // received a hello
      void ReceiveHello();

      // Displays who is sending a hello and the recipient
      // Method checks for the error of someone trying to say hello to
      // themself
      void ReceiveHello(Person* pSource);

      // Enables a greeting between a person and a computer. Must feed this
      // method a pointer to an instance of a computer within the Person class
      void Greeting( Computer* Cpoint );

    private:
        std::string _name; // The person's name
        int _helloCount; // How many times someone's said hello to this person
        int _errorCount; // This variable records if a person has tried to say hello to themself
};

#endif
