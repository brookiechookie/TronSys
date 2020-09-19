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
    int numOfSpeakers = 4;

    Speaker** pPeops;                       // Create a pointer array of people
    pPeops = new Speaker*[numOfSpeakers];   // pPeops pointer points to the array of speakers now
    pPeops[0] = new English( );             // At the first element, create the english speaker
    pPeops[1] = new Italian( );             // Create Italian Speaker
    pPeops[2] = new Dutch( );               // Create Dutch Speaker
    pPeops[3] = new TalkativeEng( );



    for( int i = 0; i < numOfSpeakers; i++ )
    {
        pPeops[i]->GreetUser();
    }

    // Get le Italian to greet again
    pPeops[1]->GreetUser();
    //pPeops[1]->GreetingReport();

    for( int i = 0; i < numOfSpeakers; i++ )
    {
        delete pPeops[i];
    }


}
