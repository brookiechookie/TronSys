// Italian.cpp
//
// Implementation file for the derived class: Italian



#include <iostream>
#include <stdlib.h>
#include <string>

#include "Italian.h"
#include "Speaker.h"

//-----------------------------------------------------------------------------
// Constructor for English derived class
Italian::Italian( std::string Name )
{
    _personName = Name;
    _helloPhrase = "Ciao, Mondo!";
    std::cout << "[CTor1]: The Person " << _personName << " has been initalised "
    << std::endl;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
Italian::~Italian()
{
    std::cout << "[DTor1]: The Person " << _personName << " is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Italian::GreetUser()
{
      std::cout << "[GreetUser]: "<< _personName <<"'s greeting is - " << _helloPhrase << std::endl;
}
