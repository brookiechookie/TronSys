// Dutch.cpp
//
// Implementation file for the derived class: Latin



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Dutch.h"
#include "Speaker.h"

//-----------------------------------------------------------------------------
// Constructor for English derived class
Dutch::Dutch( )
{
    //_helloPhrase = "Hallo, Wereld!";
    std::cout << "[CTor1]: The Dutch Person has been initalised "
    << std::endl;
    _GreetingCount = 0;
}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
Dutch::~Dutch( )
{
    std::cout << "[DTor1]: The Dutch Person is signing off."
    << std::endl;
}


//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Dutch::GreetUser( )
{
      std::cout << "[Greet]: The Dutch greeting is - " << _helloPhrase << std::endl;
      _GreetingCount++;
}

//---------------------------------------------------------------
// Count how many times the person has said a greeting
void Dutch::GreetingReport( )
{
    std::cout << "[Report]: Dutch greeting count is: " << _GreetingCount << std::endl;
}
