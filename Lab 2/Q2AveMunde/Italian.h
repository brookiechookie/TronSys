// Italian.h
//
// Header file for the derived speaker class: Italian

#ifndef _ITALIAN_H
#define _ITALIAN_H

#include "Italian.h"
#include "Speaker.h"

class Italian: public Speaker
{
    public:
        Italian( std::string Name );
        ~Italian();
        void GreetUser();
};


#endif
