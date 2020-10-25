// TalkativeEng.h
//
// Header file for the double derived speaking class: English - talkative english

#ifndef _TALKATIVEENG_H
#define _TALKATIVEENG_H

#include "English.h"
#include "Speaker.h"


class TalkativeEng: public English
{
    public:
        TalkativeEng( );
        ~TalkativeEng( );
        void GreetUser( );
        void GreetingReport( );

        static const std::string _helloPhrase;
};





#endif
