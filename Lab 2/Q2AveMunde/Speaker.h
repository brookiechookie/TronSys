// Speaker.h
//
// Header file for the base class speaker

#ifndef _SPEAKER_H
#define _SPEAKER_H

class Speaker
{
    public:
        virtual void GreetUser( ) = 0;      // Note that with virtual functions, every derived class
        virtual void GreetingReport( ) = 0; // must contain this function and an implementation of it
        virtual ~Speaker( );         // Allow destructor to be virtual so that derived class destructors
                                    // can be called

    protected:                      // Protected classes allowed derived classes to access variables
        std::string _helloPhrase;   // The hello phrase in that speakers language
        int _GreetingCount;
};


#endif
