// Italian.h
//
// Header file for the derived speaker class: Italian

#ifndef _ITALIAN_H
#define _ITALIAN_H

#include "Speaker.h"

class Italian: public Speaker
{
    public:
        Italian( );
        ~Italian( );
        void GreetUser( );
        void GreetingReport( );

        static const std::string _helloPhrase;
};



#endif
