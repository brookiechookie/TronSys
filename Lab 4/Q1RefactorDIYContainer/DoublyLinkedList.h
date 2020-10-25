// DoublyLinkedList.h
//
// Creator:   Brookie
// Date:      24.10.20
// Purpose:   Header file for DoublyLinkedList class


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
        void printItemList();

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
// object to be stored in the list.
template <class T>
void DoublyLinkedList<T>::push_back( T& object )
{
    std::cout << "[Back]: Push back"  << std::endl;

    // Record that a new element is being added to the list
    m_CountOfItems++;

    // Add the element to a new node, assign this as the last element in list
    Node<T>* new_Node = new Node<T>( object );
  	new_Node->next = NULL;

    // If the Head Reference point is equal to NULL, then the list is empty. We
    // must reassign the head reference to now point to the first item in the
    // list.
  	if( _HeadRef == NULL )
  	{
    		new_Node->prev = NULL;
    		_HeadRef = new_Node;
        std::cout << "[Back]: This is the first item in the list" << std::endl;
    		return;
  	}

    // Find the end of the list
    Node<T>* last = _HeadRef;
  	while( last->next != NULL )
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
// This function prints the list for the general types of int, float, string.
// It does not print the list for types such as class objects.
template <class T>
void DoublyLinkedList<T>::printList()
{
    std::cout << "[DLL ]: Printing contents of list; " << std::endl;
    Node<T>* node = _HeadRef;
    int i = 0;
  	while (node != NULL)
  	{
        // Grab the element from the node and store it in a variable
        T _StoredObjectValue;
        _StoredObjectValue = node->ObjectStoredGetter();

        // Print the element to the screen then go to the next element in list
        std::cout << "[List]: Index:" << i << ", Element = "<<
        _StoredObjectValue << std::endl;
    		node = node->next;
        i++;
  	}
}


//------------------------------------------------------------------------------
// This print list function is UNIQUE to the class item with an ID value. This
// function will print the ID's of the items to the screen.
template <class T>
void DoublyLinkedList<T>::printItemList()
{
    Node<T>* node = _HeadRef;
    int i = 0;

    // If the list is empty, advise the user.
    if( node == NULL )
    {
        std::cout << "[List]: List is empty, nothing to print!!" << std::endl;
    }

    // Print the ID's of the items in the list until the end of list is reached
  	while (node != NULL)
  	{
        int _GotItemID = node->NodeItemIDGetter();
        std::cout << "[List]: Index:" << i << ", Item ID = "<< _GotItemID <<
        " stored" << std::endl;

        // Go to the next item object in the list
    		node = node->next;
        i++;
  	}

}


//------------------------------------------------------------------------------
// This function pops and deletes the front item in the list
template <class T>
void DoublyLinkedList<T>::pop_front( )
{
    Node<T>* _FirstItem = _HeadRef;
    int OkayToDelete = 1;
    int DontEnter = 0;

    // If there is nothing currently being stored in the list then we cannot
    // delete anything
    if( _HeadRef == _HeadRefBase )
    {
        std::cout << "[Pop ]: There is nothing in the list. Cannot pop the "<<
        "front item!" << std::endl;
        OkayToDelete = 0;
    }

    if( OkayToDelete != 0 )
    {
        // If the last item in the list is being popped off, reassign the head
        // ref back to the base reference
        if( _FirstItem->prev == NULL && _FirstItem->next == NULL )
        {
            std::cout << "[Pop ]: There is only one item left" << std::endl;
            _HeadRef = _HeadRefBase;
            DontEnter = 1;
        }

        // If the front of the list was not found properly then find it
        while( _FirstItem->prev != NULL && DontEnter != 1)
        {
            std::cout << "[Pop ]: First Node not given, Finding First Node" <<
            std::endl;
            _FirstItem = _FirstItem->prev;
        }

        // Assign the next element in the list as the head element of the list
        if( _FirstItem->next != NULL && DontEnter != 1 )
        {
            _FirstItem->next->prev = NULL;
            _HeadRef = _FirstItem->next;
        }

    }

    // If it has been recorded that the first item must be deleted, then delete
    // it
    if( OkayToDelete == 1 )
    {
        delete _FirstItem;
        m_CountOfItems--;
    }

    return;
}



#endif
