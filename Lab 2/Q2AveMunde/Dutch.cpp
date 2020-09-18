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
Dutch::Dutch( std::string Name )
{
    _personName = Name;
    _helloPhrase = "Hallo, Wereld!";
    std::cout << "[CTor1]: The Person " << _personName << " has been initalised "
    << std::endl;


}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
Dutch::~Dutch()
{
    std::cout << "[DTor1]: The Person " << _personName << " is signing off."
    << std::endl;
}


//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Dutch::GreetUser()
{
      std::cout << "[GreetUser]: "<< _personName <<"'s greeting is - " << _helloPhrase << std::endl;
}
