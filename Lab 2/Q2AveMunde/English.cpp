// English.cpp
//
// Implementation file for the derived class: English
// Completed by:


#include <iostream>
#include <stdlib.h>
#include <string>

#include "English.h"
#include "Speaker.h"

//-----------------------------------------------------------------------------
// Constructor for English derived class
English::English( )
{
    _helloPhrase = "Hello, World!";   // If a person speaks english this is their hello phrase
    std::cout << "[CTor1]: The English Person has been initalised "
    << std::endl;
    _GreetingCount = 0;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
English::~English( )
{
    std::cout << "[DTor1]: The English Person is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void English::GreetUser( )
{
      std::cout << "[Greet]: The English greeting is - " << _helloPhrase << std::endl;
      _GreetingCount++;
}

//---------------------------------------------------------------
// Count how many times the person has said a greeting
void English::GreetingReport( )
{
    std::cout << "[Report]: English greeting count is: " << _GreetingCount << std::endl;
}
