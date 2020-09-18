// Speaker.h
//
// Header file for the base class speaker

#ifndef _SPEAKER_H
#define _SPEAKER_H

#include "English.h"
#include "Speaker.h"

class Speaker
{
    public:
        void GreetUser();
        //virtual void Naming( std::string Name );
    protected:                      // Protected classes allowed derived classes to access variables
        std::string _helloPhrase;   // The hello phrase in that speakers language
        std::string _personName;    // Every person no matter what language they speak has a name

};


#endif
