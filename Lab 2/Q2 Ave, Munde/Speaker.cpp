// Speaker.cpp
//
// Implementation file for the base class Speaker
// Completed by:


#include <iostream>
#include <stdlib.h>
#include <string>

#include "Speaker.h"
#include "English.h"

//---------------------------------------------------------------
// Greet the user in the persons respective language!
void Speaker::GreetUser()
{
      std::cout << _personName <<"'s phrase is: " << _helloPhrase << std::endl;
}
