/*
main.cpp

Creator:        Brooke Agostino
Date created:   18/9/20
Purpose:        Question 2 of lab 2; Ave, munde

Modifications:

*/
#include <iostream>
#include <stdlib.h>

class Speaker
{
    public:
        void GreetUser();

    protected:                      // Protected classes allowed derived classes to access variables
        std::string _helloPhrase;   // The hello phrase in that speakers language
        std::string _personName;    // Every person no matter what language they speak has a name

};

class English: public Speaker
{

    public:
        English( std::string Name );
        ~English();

};



int main()
{
    English Bob( "Bob" );
    Bob.GreetUser();
}


//-----------------------------------------------------------------------------
// Constructor for English derived class
English::English( std::string Name )
{
    _personName = Name;
    _helloPhrase = "Hello, World!";   // If a person speaks english this is their hello phrase
    std::cout << "[CTor1]: The Person " << _personName << " has been initalised "
    << std::endl;
    //std::cout << _personName <<"'s phrase is: " << _helloPhrase << std::endl;

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
void Speaker::GreetUser()
{
      std::cout << _personName <<"'s phrase is: " << _helloPhrase << std::endl;
}
