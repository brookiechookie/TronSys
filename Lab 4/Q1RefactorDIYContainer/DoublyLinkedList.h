// DoublyLinkedList.h
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Header file for DoublyLinkedList class in Test DIY List


#ifndef _TEMPLATEDDOUBLYLINKEDLIST_H
#define _TEMPLATEDDOUBLYLINKEDLIST_H

#include "Item.h"

template <class T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList( );
        void push_back(T _TheItemID);
        void pop_front( );
        void printList( );
        int Size();

    private:
        int   _ItemID;
        Item* _HeadRefBase = NULL;
        Item* _HeadRef;
        int   _CountOfItems;

};



//------------------------------------------------------------------------------
// Constructor for DLL
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    _HeadRef        = _HeadRefBase;
    _ItemID         = 0;
    _CountOfItems   = 0;

    std::cout << "The DLL has been created" << std::endl;

}


//------------------------------------------------------------------------------
// Given a reference (pointer to pointer) to the head of a DLL and an int,
// push_backs a new Item at the end
// The following code was inspired by a piece of code found online. I used this
// resource on the 8/10/20, and it can be found at
// https://www.geeksforgeeks.org/doubly-linked-list/
template <class T>
void DoublyLinkedList<T>::push_back( T _TheItemID )
{
    std::cout << "[Back]: Push back"  << std::endl;

    Item* new_Item = new Item( _TheItemID );
    Item* last = _HeadRef;

    // Since this is the last element, no elements exist after this one, thus
    // assign the next of this item object to null
  	new_Item->next = NULL;

    // If the Head Reference point is equal to NULL, then the list is empty. We
    // must reassign the head reference to now point to the first item in the
    // list. If the Head Reference Point is not equal to NULL then the list is
    // not empty
  	if( _HeadRef == NULL )
  	{
    		new_Item->prev = NULL;
    		_HeadRef = new_Item;   // Point the head to the first item
        std::cout << "[Back]: This is the first item in the list" << std::endl;
    		return;
  	}


  	while( last->next != NULL )  // Find the end of the list
    {
        last = last->next;
    }

  	last->next = new_Item;       // Assign the second last item's next pointer to point to the last item
  	new_Item->prev = last;       // Assign the prev pointer for last item to second last item

  	return;
}


#endif
