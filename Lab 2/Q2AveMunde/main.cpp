/*
main.cpp

Creator:        Brooke Agostino
Date created:   17/9/20
Purpose:        Question 2 of lab 2; Ave, munde

Modificatio
*/

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Speaker.h"
#include "English.h"
#include "Italian.h"
#include "Dutch.h"
#include "TalkativeEnglish.h"

int main()
{
    int numOfSpeakers = 3;

    Speaker** pPeops;                       // Create a pointer array of people
    pPeops = new Speaker*[numOfSpeakers];   // pPeops pointer points to the array of speakers now
    pPeops[0] = new English( "Bob" );       // At the first element, create the english speaker Bob
    pPeops[1] = new Italian( "Mario" );     // Create Italian Speaker
    pPeops[2] = new Dutch( "Eise" );        // Create Dutch Speaker


    for( int i = 0; i < numOfSpeakers; i++ )
    {
        pPeops[i]->GreetUser();
    }

    for( int i = 0; i < numOfSpeakers; i++ )
    {
        delete pPeops[i];
    }


}
