// Dutch.h
//
// Header file for the derived speaker class: Italian

#ifndef _DUTCH_H
#define _DUTCH_H

#include "Dutch.h"
#include "Speaker.h"

class Dutch: public Speaker
{

    public:
        Dutch( std::string Name );
        ~Dutch();
        void GreetUser();
};


#endif
