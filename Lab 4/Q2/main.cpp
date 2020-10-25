/*
main.cpp

Creator:        Brooke Agostino
Date created:   17/9/20
Purpose:        Question 2 of lab 2; Ave, munde

Modifications:
*/

#include <iostream>
#include <stdlib.h>
#include <string>

#include <vector>   // vector
#include <memory>   // shared_ptr
#include <cassert>  // the built-in assert is ignored if we #define NDEBUG

#include "MyLogger.h"
#include "Speaker.h"
#include "English.h"
#include "Italian.h"
#include "Dutch.h"
#include "TalkativeEng.h"

const std::string English::_helloPhrase       = "Hello, World!";
const std::string Dutch::_helloPhrase         = "Hallo, Wereld!";
const std::string Italian::_helloPhrase       = "Ciao, Mondo!";
const std::string TalkativeEng::_helloPhrase  = "Hello, World! I'm a bit of a talkative person. Welcome to my crib!";

int main()
{
    // Provide a starting message to the terminal asking the user to input a series
    // of number that will determine what speakers go into the array
    std::cout << "Hi User, you need to input some speakers. You get to" <<
    " choose the language of the speaker and the number of speakers. The" <<
    " number identifiers for the speakers are as follows;" <<
    " \n 0: English Speaker \n 1: Italian Speaker\n 2: Dutch Speaker\n" <<
    " 3: Talkative English Speaker\nIf you are finished enterring your" <<
    " speakers, enter -1. Each input must be followed by pressing the enter" <<
    " key. An example of appropriate input is; 0 2 3 2 1 2 \n" << std::endl;

    std::vector<int> pSpeakers;

    // The loop runs and takes in all the user input. When the user enters the
    // symbolic value of -1, The loop is exited.
    int UserInput = 1;
    int IntEnterred;
    int ErrorRecorded = 0;
    while( UserInput )
    {
        //std::cin >> IntEnterred;
        //assert( IntEnterred < -1 );
        // Check if the user input is valid, i.e. that it is an int and in the
        // range of -1 to 3

        //std::cin >> IntEnterred;
        //assert( IntEnterred >= -1 );
        //assert( IntEnterred <= 3  );

        while( !( std::cin >> IntEnterred) || (IntEnterred < -1 ||IntEnterred > 3 ) )
        {
            ErrorRecorded = 1;
            //assert( ErrorRecorded == 1 );
            std::cout << "Invalid Input: Numbers entered are out of range!" <<
            std::endl;

            //assert( ErrorRecorded == 1 );
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }

      //  assert( ErrorRecorded == 1 );

        // If the user wants to stop input, they should enter the number -1.
        // Otherwise, store their input to the back of the vector
        if( IntEnterred == -1 )
        {
            std::cout << "User has signified end of input. Using " << IntEnterred <<
            std::endl;
            UserInput = 0;
        }
        // Store valid input
        else
        {
            std::cout << "Storing int enterred = " << IntEnterred << std::endl;
            pSpeakers.push_back(IntEnterred);
        }

    }

    std::cout << "The size of the vector is: " << pSpeakers.size() <<
    std::endl;
    std::cout << "The numbers enterred by the user were; " << std::endl;
    for( int i = 0; i < pSpeakers.size(); i++ )
    {
        std::cout << pSpeakers[i] << ", ";
    }
    std::cout << std::endl;

    int numOfSpeakers = pSpeakers.size();

    int* pInputString = new int[numOfSpeakers];

    // Create the speakers, put them all in an array
    //Speaker** pPeops;                       // Create a pointer array of people
    //pPeops = new Speaker*[numOfSpeakers];   // pPeops pointer points to the array of speakers now

    //std::vector<int> pSpeakers;

    std::vector< std::shared_ptr<Speaker> > pPeople;

    //std::shared_ptr<Speaker> pPeople(NULL);

    // Now create a for loop assigning the users input to a person speaking that language
    for( int i = 0; i < numOfSpeakers; i++ )
    {
        if( pSpeakers[i] == 0 )
        {
            pPeople.push_back( std::make_shared<English>() );
            //std::cout << "pPeople.use_count(): " << pPeople[i].use_count() << std::endl;
            //pPeople->GreetUser();
            //pPeops[i] = new English( );
        }
        if( pSpeakers[i] == 1 )
        {
            pPeople.push_back( std::make_shared<Italian>() );
            //std::cout << "pPeople.use_count(): " << pPeople[i].use_count() << std::endl;
            //pPeople->GreetUser();
            //pPeops[i] = new Italian( );
        }
        if( pSpeakers[i] == 2 )
        {
            pPeople.push_back( std::make_shared<Dutch>() );
            //std::cout << "pPeople.use_count(): " << pPeople[i].use_count() << std::endl;
            //pPeople->GreetUser();
            //pPeops[i] = new Dutch( );
        }
        if( pSpeakers[i] == 3 )
        {
            pPeople.push_back( std::make_shared<TalkativeEng>() );
            //std::cout << "pPeople.use_count(): " << pPeople[i].use_count() << std::endl;
            //pPeople->GreetUser();
            //pPeops[i] = new TalkativeEng( );
        }

    }

    // Run through each speaker and make them say their respective greeting
    for( int i = 0; i < pPeople.size(); i++ )
    {
        pPeople[i]->GreetUser();
        //pPeops[i]->GreetUser();
    }

    // Get some of the speakers to greet a few more times
    std::cout << "Adding more greetings" << std::endl;
    pPeople[1]->GreetUser();
    pPeople[0]->GreetUser();
    pPeople[2]->GreetUser();

    // Provide a report of how many times each speaker has greeted the user
    for( int i = 0; i < pPeople.size(); i++ )
    {
        pPeople[i]->GreetingReport();
    }

/*
    // Now go through and delete the speakers to ensure there are no memory leaks
    for( int i = 0; i < numOfSpeakers; i++ )
    {
        delete pPeops[i];
    }

*/
    std::cout << "Finished in main" << std::endl;
}
