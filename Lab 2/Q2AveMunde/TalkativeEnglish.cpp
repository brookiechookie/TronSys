// TalkativeEnglish.cpp
//
// Implementation file for the double derived class: TalkativeEnglish
// Completed by:


#include <iostream>
#include <stdlib.h>
#include <string>

#include "TalkativeEnglish.h"
#include "English.h"
#include "Speaker.h"

//-----------------------------------------------------------------------------
// Constructor for English derived class
TalkativeEnglish::TalkativeEnglish( std::string Name )
{
    _personName = Name;
    _helloPhrase = "Hello, World!";   // If a person speaks english this is their hello phrase
    std::cout << "[CTor2]: The Person " << _personName << " has been initalised "
    << std::endl;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
TalkativeEnglish::~TalkativeEnglish()
{
    std::cout << "[DTor2]: The Person " << _personName << " is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void TalkativeEnglish::GreetUser()
{
      std::cout << "[GreetUser]: "<< _personName <<"'s greeting is - " << _helloPhrase << std::endl;
}
