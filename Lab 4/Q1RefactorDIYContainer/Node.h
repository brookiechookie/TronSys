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

#include "Item.h"

template <class T>
class Node
{
    public:
        Node( T& object );
        ~Node();
        Node<T>* next;
        Node<T>* prev;
        T ObjectStoredGetter();
        int NodeItemIDGetter();

    private:
        const T& m_ObjectStored;
        int _ItemIDCode;

};

//------------------------------------------------------------------------------
// Node Object Consructor
template <class T>
Node<T>::Node( T& object ) : m_ObjectStored( object )
{
    _ItemIDCode = object.IDGetter();

    std::cout << "[DLL ]: Item with ID = " << _ItemIDCode << " put in list" <<
    std::endl;

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


//------------------------------------------------------------------------------
// Getter function returning the item ID's of each Item object
template <class T>
int Node<T>::NodeItemIDGetter()
{
    return _ItemIDCode;
}



#endif
