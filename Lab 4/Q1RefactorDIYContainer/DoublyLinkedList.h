// DoublyLinkedList.h
//
// Creator:   Brookie
// Date:      8.10.20
// Purpose:   Header file for DoublyLinkedList class in Test DIY List


#ifndef _TEMPLATEDDOUBLYLINKEDLIST_H
#define _TEMPLATEDDOUBLYLINKEDLIST_H

#include "Node.h"

template <class T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList( );
        void push_back( T& object );
        void pop_front( );
        void printList( );
        int Size();

    private:
        Node<T>* _HeadRefBase = NULL;
        Node<T>* _HeadRef;
        int m_CountOfItems;

};



//------------------------------------------------------------------------------
// Constructor for DLL
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : m_CountOfItems( 0 )
{
    _HeadRef  = _HeadRefBase;

    std::cout << "[Ctor]: The DLL has been created" << std::endl;
}


//------------------------------------------------------------------------------
// We want to add a new entry to the list. Feed in a reference to the item
// object to be stored in the list. Use const to avoid accidental updates of the
// object
template <class T>
void DoublyLinkedList<T>::push_back( T& object )
{
    std::cout << "[Back]: Push back"  << std::endl;

    // We want to increase the number of objects that are being stored
    m_CountOfItems++;

    //std::cout << "[Back]: The item object " << object << " has been received" <<
    //std::endl;



//    Node* new_Node = new Node( object );
    Node<T>* new_Node = new Node<T>( object );
    //std::cout << "[DLL ]: Reached here" << std::endl;

    Node<T>* last = _HeadRef;

    // Since this is the last element, no elements exist after this one, thus
    // assign the next of this item object to null
  	new_Node->next = NULL;

    // If the Head Reference point is equal to NULL, then the list is empty. We
    // must reassign the head reference to now point to the first item in the
    // list. If the Head Reference Point is not equal to NULL then the list is
    // not empty
  	if( _HeadRef == NULL )
  	{
    		new_Node->prev = NULL;
    		_HeadRef = new_Node;   // Point the head to the first item
        std::cout << "[Back]: This is the first item in the list" << std::endl;
    		return;
  	}


  	while( last->next != NULL )  // Find the end of the list
    {
        last = last->next;
    }

  	last->next = new_Node;       // Assign the second last item's next pointer to point to the last item
  	new_Node->prev = last;       // Assign the prev pointer for last item to second last item

  	return;


}

//------------------------------------------------------------------------------
// This function simply returns the size of the list i.e. the number of Item
// objects in the list
template <class T>
int DoublyLinkedList<T>::Size()
{
    return m_CountOfItems;
}


//------------------------------------------------------------------------------
template <class T>
void DoublyLinkedList<T>::printList()
{
    Node<T>* node = _HeadRef;
    int i = 0;
  	while (node != NULL)
  	{
        T _StoredObjectValue;
        _StoredObjectValue = node->ObjectStoredGetter();
        std::cout << "[List]: Index:" << i << ", object of value = "<< _StoredObjectValue <<
        " stored" << std::endl;
    		node = node->next;
        i++;
  	}

}

//------------------------------------------------------------------------------
template <class T>
void DoublyLinkedList<T>::pop_front( )
{
//    std::cout << "[Pop ]: Popping Front Item"  << std::endl;
    Node<T>* _FirstItem = _HeadRef;
    T _StoredNodeValue;

    // If there is nothing currently being stored in the list then we cannot
    // delete anything
    if( _HeadRef == _HeadRefBase )
    {
        std::cout << "[Pop ]: There is nothing in the list. Cannot pop the "<<
        "front item!" << std::endl;

        return;
    }

    // The first condition which must be checked is if the last item in the
    // list is being popped off
    if( _FirstItem->prev == NULL && _FirstItem->next == NULL)
    {

        _StoredNodeValue = _FirstItem->ObjectStoredGetter();
        std::cout << "[Pop ]: There is only one item left" << std::endl;
        std::cout << "[Pop ]: The current object value is = " <<
        _StoredNodeValue << std::endl;

        // IF we are popping the last item in the list, then we must reset the
        // head reference point back to the base head.
        _HeadRef = _HeadRefBase;

        delete( _FirstItem );
        m_CountOfItems--;

        return;
    }

    // If the front of the list was not found properly then find it
    while( _FirstItem->prev != NULL )
    {
        std::cout << "[Pop ]: First Node not given, Finding First Node" << std::endl;
        _StoredNodeValue = _FirstItem->ObjectStoredGetter();
        _FirstItem = _FirstItem->prev;

    }

    // We need to reassign the prev of the new head item to NULL, only if the
    // item that we are currently working with is not the last item
    if( _FirstItem->next != NULL )
    {
        _FirstItem->next->prev = NULL;

        // We need to reassign the head item to the next item in the list
        _HeadRef = _FirstItem->next;
    }

    _StoredNodeValue = _FirstItem->ObjectStoredGetter();
    std::cout << "[Pop ]: First Node being deleted. Object Value = " <<
    _StoredNodeValue << std::endl;

    delete _FirstItem;
    m_CountOfItems--;

    return;
}


#endif
