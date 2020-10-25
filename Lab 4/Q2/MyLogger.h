// Dutch.h
//
// Header file for the derived speaker class: Italian
#include <iostream>
#include <string>
#include <cassert>  // the built-in assert is ignored if we #define NDEBUG

#ifndef _MYLOGGER_H
#define _MYLOGGER_H

class MyLogger
{
  public:
    static void LogMessage( const std::string& rMessage ) {
    #ifndef NDEBUG
    std::cout << rMessage << std::endl;
    #endif
  }
};


#endif
