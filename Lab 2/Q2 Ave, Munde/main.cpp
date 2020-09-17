/*
main.cpp

Creator:        Brooke Agostino
Date created:   17/9/20
Purpose:        Question 2 of lab 2; Ave, munde

Modifications:

*/

#include <iostream>
#include <stdlib.h>

class Speaker
{
    public:
        void GreetUser();
        void Naming( std::string Name );
    protected:
        std::string _helloPhrase;
        std::string _personName;

};

class English: public Speaker
{
    public:
        English();
        ~English();

    private:

};

int main()
{
    English Bob( );
    Bob.Naming( "Bob" );
    //Bob.GreetUser();
}



//-----------------------------------------------------------------------------
void Speaker::GreetUser()
{
      std:: cout << _helloPhrase << std::endl;
}

void Speaker::Naming( std::string Name )
{
    _personName = Name;
    std::cout << "This person's name is " << _personName << std::endl;

}

//-----------------------------------------------------------------------------
// Constructor for English
English::English( )
{
    //_personName = Name;
    //_helloPhrase = "Hello, World!";
    std::cout << "[CTor1]: The Person " << _personName << " has been initalised "
    << std::endl;

}

//-----------------------------------------------------------------------------
// We need a corresponding Deconstructor for the constructor 0f countries
English::~English()
{
    std::cout << "[DTor1]: The Person " << _personName << " is signing off."
    << std::endl;
}
