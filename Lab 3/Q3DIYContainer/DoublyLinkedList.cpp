// DoublyLinkedList.cpp
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Implementation file for the DoublyLinkedList class

#include "DoublyLinkedList.h"
#include "Item.h"

DoublyLinkedList::DoublyLinkedList()
{
    _HeadRef        = _HeadRefBase;
    _ItemID         = 0;
    _CountOfItems   = 0;
}
//------------------------------------------------------------------------------
// Given a reference (pointer to pointer) to the head of a DLL and an int,
// push_backs a new Item at the end
//void DoublyLinkedList::push_back(Item** head_ref, int _TheItemID )
void DoublyLinkedList::push_back( int _TheItemID )
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



//------------------------------------------------------------------------------
// This function prints contents of linked list starting from the given Item
//void DoublyLinkedList::printList(Item* item)
void DoublyLinkedList::printList()
{
    Item* item = _HeadRef;
  	std::cout <<"[Disp]: Traversal in forward direction" << std::endl;
  	while (item != NULL)
  	{
        _ItemID = item->IDGetter();
        std::cout << "[List]: Item with ID "<< _ItemID << std::endl;
    		item = item->next;
        _CountOfItems++;
  	}

    /*
    if(item == NULL)
    {
        std::cout << "[List]: "<< "NULL - Last Item in the list" << std::endl;
    }
    */

}



//------------------------------------------------------------------------------
// This function pops the front item of the list. In order to pop the front of
// the stack, we must first make sure that there is items in the list. Then we
// must find the head of the list and pop the first item.
void DoublyLinkedList::pop_front( )
{
    std::cout << "[Pop ]: Popping Front Item"  << std::endl;
    Item* _FirstItem = _HeadRef;

    if( _FirstItem->prev == NULL && _FirstItem->next == NULL)
    {
        _ItemID = _FirstItem->IDGetter();
        std::cout << "[Pop ]: There is only one item left" << std::endl;
        //std::cout << "[Pop ]: The current item value is = " << _ItemID << std::endl;

        // IF we are popping the last item in the list, then we must reset the
        // head reference point back to the base head.
        _HeadRef = _HeadRefBase;

        delete( _FirstItem );
        _CountOfItems--;

        return;
    }

    while( _FirstItem->prev != NULL )  // Find the front of the list
    {
        _ItemID = _FirstItem->IDGetter();
        std::cout << "[Pop ]: Currently at Item with val " << _ItemID << std::endl;

        _FirstItem = _FirstItem->prev;

        std::cout << "[Pop ]: First Item not given, Finding First Item" << std::endl;
    }

    // We need to reassign the prev of the new head item to NULL, only if the
    // item that we are currently working with is not the last item
    if( _FirstItem->next != NULL )
    {
        _FirstItem->next->prev = NULL;

        // We need to reassign the head item to the next item in the list
        _HeadRef = _FirstItem->next;
    }

    //_ItemID = _FirstItem->IDGetter();
    //std::cout << "[Pop ]: Item with value " << _ItemID << " being deleted"<< std::endl;

    delete _FirstItem;
    _CountOfItems--;

    return;
}


//------------------------------------------------------------------------------
// This function simply returns the size of the list i.e. the number of Item
// objects in the list
int DoublyLinkedList::Size()
{
    return _CountOfItems;
}
