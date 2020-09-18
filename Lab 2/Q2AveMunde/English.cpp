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
English::English( std::string Name )
{
    _personName = Name;
    _helloPhrase = "Hello, World!";   // If a person speaks english this is their hello phrase
    std::cout << "[CTor1]: The Person " << _personName << " has been initalised "
    << std::endl;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
English::~English()
{
    std::cout << "[DTor1]: The Person " << _personName << " is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void English::GreetUser()
{
      std::cout << "[GreetUser]: "<< _personName <<"'s greeting is - " << _helloPhrase << std::endl;
}
