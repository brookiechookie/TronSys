// DoublyLinkedList.h
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Header file for DoublyLinkedList class in Test DIY List


#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include "Item.h"

//------------------------------------------------------------------------------
// This class provides a functioning doubly linked list, with standard functions
// such as push back, pop front and size, as well as some unqiue functions such
// return first item and checking if the list is empty. The way in which each
// function works is detailed in the corresponding cpp file
class DoublyLinkedList
{
    public:
        DoublyLinkedList( );
        void push_back( int _TheItemID, float TimeON );
        void pop_front( );
        void printList( );
        int Size();
        Item* ReturnFirstItem();
        int CheckIfListEmpty();
        void DeleteElement( int n );

    private:
        int   _ItemID;
        Item* _HeadRefBase = NULL;
        Item* _HeadRef;
        int   _CountOfItems;
        int   _ErrorValue;
        int   _NoError;
        float _ItemProcTime;

};



#endif
