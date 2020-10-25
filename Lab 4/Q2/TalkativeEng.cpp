// TalkativeEng.cpp
//
// Implementation file for the double derived class: TalkativeEnglish
// Completed by:


#include <iostream>
#include <stdlib.h>
#include <string>

#include "TalkativeEng.h"
#include "English.h"
#include "Speaker.h"


//-----------------------------------------------------------------------------
// Constructor for English derived class
TalkativeEng::TalkativeEng( )
{

    _helloPhrase = "Hello, World! I'm a bit of a talkative person. Welcome to my crib!";
    std::cout << "[CTor2]: The Talkative Person has been initalised "
    << std::endl;

}


//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor of english speakers
TalkativeEng::~TalkativeEng( )
{
    std::cout << "[DTor2]: The Talkative Person is signing off."
    << std::endl;
}

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void TalkativeEng::GreetUser( )
{
      std::cout << "[Greet]: The Talkative English greeting is - " << _helloPhrase << std::endl;
      _GreetingCount++;
}

//---------------------------------------------------------------
// Count how many times the person has said a greeting
void TalkativeEng::GreetingReport( )
{
    std::cout << "[Report]: The Talkative English greeting count is: " << _GreetingCount << std::endl;
}
