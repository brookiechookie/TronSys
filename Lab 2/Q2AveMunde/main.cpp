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

#include "Speaker.h"
#include "English.h"
#include "Italian.h"
#include "Dutch.h"
#include "TalkativeEng.h"

int main()
{
    // Provide a starting message to the terminal asking the user to input a series
    // of number that will determine what speakers go into the array
    std::cout << "Hi User, you need to input 6 speakers. You get to choose the order" <<
    " of the speakers. The number identifiers for the speakers are; \n 0: English Speaker" <<
    "\n 1: Italian Speaker\n 2: Dutch Speaker\n 3: Talkative English Speaker\n" <<
    "An example appropriate input is; 0 2 3 2 1 2 \nNote: Your input must be between"<<
    " the numbers 0-3 and you must only enter 6 numbers. Please separate your numbers by a space.\n"<<
    std::endl;

    //Steps:
    // 1.  Initialise the number of speakers and create an integer array to store the user input
    // 2. Take in the user input, storing it in each element of the integer array
    // 3. Report back to the user what they have entered in
    int numOfSpeakers = 6;
    int* pInputString = new int[numOfSpeakers];
    std::cin >> pInputString[0] >> pInputString[1] >> pInputString[2] >> pInputString[3] >> pInputString[4] >> pInputString[5];
    std::cout << "The numbers entered were: " << pInputString[0] << ", " << pInputString[1] <<
    ", " << pInputString[2] << ", " << pInputString[3] << ", " << pInputString[4] <<
    " and " << pInputString[5] << std::endl;

    // Create the speakers, put them all in an array
    Speaker** pPeops;                       // Create a pointer array of people
    pPeops = new Speaker*[numOfSpeakers];   // pPeops pointer points to the array of speakers now

    // Now create a for loop assigning the users input to a person speaking that language
    for( int i = 0; i < 6; i++ )
    {
        if( pInputString[i] == 0 )
        {
            pPeops[i] = new English( );
        }
        if( pInputString[i] == 1 )
        {
            pPeops[i] = new Italian( );
        }
        if( pInputString[i] == 2 )
        {
            pPeops[i] = new Dutch( );
        }
        if( pInputString[i] == 3 )
        {
            pPeops[i] = new TalkativeEng( );
        }
        else if( pInputString[i] != 0 && pInputString[i] != 1 && pInputString[i] != 2 &&  pInputString[i] != 3 )
        {
            std::cout << "Invalid Input: Numbers entered are out of range!" << std::endl;
            exit(0);
        }

    }

    // Run through each speaker and make them say their respective greeting
    for( int i = 0; i < numOfSpeakers; i++ )
    {
        pPeops[i]->GreetUser();
    }

    // Get some of the speakers to greet a few more times
    pPeops[1]->GreetUser();
    pPeops[1]->GreetUser();
    pPeops[1]->GreetUser();
    pPeops[0]->GreetUser();
    pPeops[2]->GreetUser();
    pPeops[3]->GreetUser();
    pPeops[0]->GreetUser();
    pPeops[0]->GreetUser();
    pPeops[2]->GreetUser();


    // Provide a report of how many times each speaker has greeted the user
    for( int i = 0; i < numOfSpeakers; i++ )
    {
        pPeops[i]->GreetingReport();
    }


    // Now go through and delete the speakers to ensure there are no memory leaks
    for( int i = 0; i < numOfSpeakers; i++ )
    {
        delete pPeops[i];
    }


}
