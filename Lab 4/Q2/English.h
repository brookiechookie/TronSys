// English.h
//
// Header file for the derived speaker class: english

#ifndef _ENGLISH_H
#define _ENGLISH_H

#include "Speaker.h"

class English: public Speaker
{
    public:
        English( );
        ~English( );
        void GreetUser( );
        void GreetingReport( );

        static const std::string _helloPhrase;

};



#endif
