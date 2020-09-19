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
Italian::Italian( )
{
    _helloPhrase = "Ciao, Mondo!";
    std::cout << "[CTor1]: The Italian Person has been initalised "
    << std::endl;
    _GreetingCount = 0;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
Italian::~Italian()
{
    std::cout << "[DTor1]: The Italian Person is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Italian::GreetUser()
{
      std::cout << "[Greet]: The Italian greeting is - " << _helloPhrase << std::endl;
      _GreetingCount++;
}

//---------------------------------------------------------------
// Count how many times the person has said a greeting
void Italian::GreetingReport( )
{
    std::cout << "[Report]: Italian greeting count is: " << _GreetingCount << std::endl;
}
