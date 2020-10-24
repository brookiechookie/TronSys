// Node.h
//
// Creator:   Brookie
// Date:      24.10.20
// Purpose:   Header file for Item class in Test DIY List


#ifndef _NODE_H
#define _NODE_H


#include <iostream>     // std::cout
#include <cstdlib>      // For rand()
#include <random>       // For uniform number generation

template <class T>
class Node
{
    public:
        Node( const T& object );
        ~Node();
        Node<T>* next;
        Node<T>* prev;
        T ObjectStoredGetter();

    private:
        T m_ObjectStored;

};

//------------------------------------------------------------------------------
// Node Object Consructor

template <class T>
Node<T>::Node( const T& object ) : m_ObjectStored( object )
{

    //std::cout << "[DLL ]: Reached here" << std::endl;


    // Object to be stored
    // _ObjectStored = object;

    // The node function must be able to store the value that gets passed in.
    std::cout<< "[Ctor]: New node added to list" << std::endl;

}


//------------------------------------------------------------------------------
// Node Object Destructor
template <class T>
Node<T>::~Node()
{
    std::cout << "[DTor]: Node is signing off."
    << std::endl;
}


//------------------------------------------------------------------------------
// Getter function returning the item ID's of each Item object
template <class T>
T Node<T>::ObjectStoredGetter()
{
    return m_ObjectStored;
}



#endif
