// Dutch.h
//
// Header file for the derived speaker class: Italian

#ifndef _DUTCH_H
#define _DUTCH_H

#include "Speaker.h"

class Dutch: public Speaker
{
    public:
        Dutch( );
        ~Dutch( );
        void GreetUser( );
        void GreetingReport( );

        static const std::string _helloPhrase;
};



#endif
