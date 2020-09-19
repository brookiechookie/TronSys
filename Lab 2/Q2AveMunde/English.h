// English.h
//
// Header file for the derived speaker class: english

#ifndef _ENGLISH_H
#define _ENGLISH_H

//#include "English.h"
#include "Speaker.h"

class English: public Speaker
{
    public:
        English( );
        ~English();
        void GreetUser();

};

#endif
