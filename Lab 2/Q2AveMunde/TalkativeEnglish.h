// TalkativeEnglish.h
//
// Header file for the double derived speaking class: English - talkative english

#ifndef _TALKATIVEENGLISH_H
#define _TALKATIVEENGLISH_H

#include "English.h"
#include "Speaker.h"

class TalkativeEnglish: public English
{
    public:
        TalkativeEnglish( std::string Name );
        ~TalkativeEnglish();
        void GreetUser();
};


#endif
