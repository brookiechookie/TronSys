// Latin.cpp
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
    _helloPhrase = "Hallo, Wereld!";
    std::cout << "[CTor1]: The Dutch Person has been initalised "
    << std::endl;
}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
Dutch::~Dutch()
{
    std::cout << "[DTor1]: The Dutch Person is signing off."
    << std::endl;
}


//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Dutch::GreetUser()
{
      std::cout << "[GreetUser]: The Dutch greeting is - " << _helloPhrase << std::endl;
}
