// DoublyLinkedList.h
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Header file for DoublyLinkedList class in Test DIY List


#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include "Item.h"

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

    private:
        int   _ItemID;
        Item* _HeadRefBase = NULL;
        Item* _HeadRef;
        int   _CountOfItems;
        int   _ErrorValue;
        int   _NoError;

};



#endif
