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

#include <vector>

#include "Speaker.h"
#include "English.h"
#include "Italian.h"
#include "Dutch.h"
#include "TalkativeEng.h"

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

    //Steps:
    // 1.  Initialise the number of speakers and create an integer array to store the user input
    // 2. Take in the user input, storing it in each element of the integer array
    // 3. Report back to the user what they have entered in


    std::vector<int> pSpeakers;

    // The loop runs and takes in all the user input. When the user enters the
    // symbolic value of -1, The loop is exited.
    int UserInput = 1;
    int IntEnterred;
    while( UserInput )
    {
        // Check if the user input is valid
        while( !( std::cin >> IntEnterred) || (IntEnterred < -2 || IntEnterred > 3) )
        {
            std::cout << "Invalid Input: Numbers entered are out of range!" <<
            std::endl;

            std::cin.clear();
            std::cin.ignore(132, '\n');
        }

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

    std::cout << "Exited While loop" << std::endl;

    std::cout << "The size of the vector is: " << pSpeakers.size() <<
    std::endl;
    std::cout << "The numbers enterred by the user were; " << std::endl;
    for( int i = 0; i < pSpeakers.size(); i++ )
    {
        std::cout << pSpeakers[i] << ", ";
    }
    std::cout << std::endl;

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
