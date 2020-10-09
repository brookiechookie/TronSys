// DoublyLinkedList.cpp
//
// Creator:   Brookie
// Date:      9.10.20
// Purpose:   Implementation file for the DoublyLinkedList class

#include "DoublyLinkedList.h"
#include "Item.h"

//------------------------------------------------------------------------------
// Constructor for DoublyLinkedList
DoublyLinkedList::DoublyLinkedList( )
{
    _HeadRef        = _HeadRefBase;
    _ItemID         = 0;
    _CountOfItems   = 0;
    _ErrorValue     = 999;
    _NoError        = 1;
}


//------------------------------------------------------------------------------
// This function acts to push back a node to the end of a doubly linked list.
// The two vital pieces of information that are required is the Item ID and the
// time in which the node was added to the system
void DoublyLinkedList::push_back( int _TheItemID, float TimeOn )
{
    //std::cout << "[Back]: Push back"  << std::endl;

    Item* new_Item = new Item( _TheItemID, TimeOn );
    Item* last = _HeadRef;
    _CountOfItems++;

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
        //std::cout << "[Back]: This is the first item in the list" << std::endl;
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
// This function prints contents of the doubly linked list starting from the
// head reference point of the list
void DoublyLinkedList::printList()
{
    Item* item = _HeadRef;
  	std::cout <<"[Disp]: Traversal in forward direction" << std::endl;
  	while (item != NULL)
  	{
        _ItemID = item->IDGetter();
        std::cout << "[List]: Item with ID "<< _ItemID << std::endl;
    		item = item->next;
  	}

}



//------------------------------------------------------------------------------
// This function pops the front item of the list. In order to pop the front of
// the stack, we must first make sure that there is items in the list. Then we
// must find the head of the list and pop the first item.
void DoublyLinkedList::pop_front( )
{
    //std::cout << "[Pop ]: Popping Front Item"  << std::endl;
    Item* _FirstItem = _HeadRef;

    if( _FirstItem->prev == NULL && _FirstItem->next == NULL)
    {
        _ItemID = _FirstItem->IDGetter();
        //std::cout << "[Pop ]: There is only one item left" << std::endl;
        //std::cout << "[Pop ]: The current item value is = " << _ItemID << std::endl;

        // IF we are popping the last item in the list, then we must reset the
        // head reference point back to the base head.
        _HeadRef = _HeadRefBase;

        delete( _FirstItem );
        _CountOfItems--;

        return;
    }

    // Find the front of the list
    while( _FirstItem->prev != NULL )
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

//------------------------------------------------------------------------------
// This function checks whether or not the list is empty
int DoublyLinkedList::CheckIfListEmpty()
{
    int _ReturningVal;

    // We must perform a little bit of error checking here. If the list is empty
    // we will return the symbolic value to communciate this.
    if(_HeadRef == _HeadRefBase)
    {
        _ReturningVal = _ErrorValue;
    }
    else
    {
        _ReturningVal = _NoError;
    }

    return _ReturningVal;
}

//------------------------------------------------------------------------------
// This function returns the first element in the array
Item* DoublyLinkedList::ReturnFirstItem()
{
    Item* _FirstItemInList = _HeadRef;
    return _FirstItemInList;
}

//------------------------------------------------------------------------------
// This function deletes an element in the DLL at the nth item. The list starts
// at zero, i.e. the first index is zero and the second index is one.
void DoublyLinkedList::DeleteElement( int n )
{
    std::cout << "[DLLI]: Deleting Item at index " << n << std::endl;

    Item* _ItemToDelete = _HeadRef;

    // Error checking for an invalid index position
    if( n < 0 )
    {
        std::cout << "[DLLI]: Invalid index position given of " << n << std::endl;
        return;
    }

    if( _ItemToDelete == NULL )
    {
        std::cout << "[DLLI]: List is Empty, cannot delete anything" << std::endl;
    }

    // Now traverse through the list until we are at the location to delete
    // the desired element. Note the traversing will have to stop when we reach
    // the end of the array of when we hit the desired element
    for( int i = 0; i < n && _ItemToDelete != NULL; i++ )
    {
        _ItemToDelete = _ItemToDelete->next;
    }

    _ItemID = _ItemToDelete->IDGetter();
    _ItemProcTime = _ItemToDelete->ProcTimeGetter();


    // Once we have found the item to delete we must check for four different
    // scenarios.
    // 1. If the item to delete is the last item in the list, we must point the
    //    head reference back to base
    // 2. If the item to delete is at the start of the list, we must assign a
    //    new head reference pointer
    // 3. If the item to delete is at the end of the list, we must assign the
    //    prev element to be the last element in the list
    // 4. If the item to delete is in the middle of the list, we must correctly
    //    connect the preceeding and proceeding node

    // Case 1: If the item is the last item remaining in the list
    // NB: This MUST be the first test case as if the item can be the first or
    // end element AS WELL as the last item in the list. If it the last item
    // remaining then additional steps must be carried out, thus we need to test
    // for this case first.
    if( _ItemToDelete->prev == NULL && _ItemToDelete->next == NULL)
    {
        // IF we are popping the last item in the list, then we must reset the
        // head reference point back to the base head.
        _HeadRef = _HeadRefBase;

        //std::cout << "[DLLI]: Case 1 reached" << std::endl;
        //std::cout << "[DLLI]: Deleting Last item in list with ID = " << _ItemID <<
        //" and Proc Time " << _ItemProcTime << std::endl;

        _CountOfItems--;
        delete _ItemToDelete ;
        return;
    }

    // Case 2: If the item to delete is the first Item
    if( _ItemToDelete == _HeadRef )
    {
        _HeadRef = _ItemToDelete->next;
        _ItemToDelete->next->prev = NULL;

        //std::cout << "[DLLI]: Case 2 reached" << std::endl;

        //std::cout << "[DLLI]: Deleting First item in list with ID = " << _ItemID <<
        //" and Proc Time " << _ItemProcTime << std::endl;

        _CountOfItems--;
        delete _ItemToDelete ;
        return;
    }


    // Case 3: If the item to delete is at the end of the list
    if( _ItemToDelete->next == NULL )
    {
        _ItemToDelete->prev->next = NULL;

        //std::cout << "[DLLI]: Deleting End item in list with ID = " << _ItemID <<
        //" and Proc Time " << _ItemProcTime << std::endl;
        //std::cout << "[DLLI]: Case 3 reached" << std::endl;
        _CountOfItems--;
        delete _ItemToDelete ;
        return;

    }




    // Case 4: If the item to delete is in the middle of the list
    // Make sure there is a proceeding node to connect the preceeding node to
    if( _ItemToDelete->next != NULL )
    {
        _ItemToDelete->next->prev = _ItemToDelete->prev;
    }
    // Make sure there is a preceeding node to connect the proceeding node to
    if( _ItemToDelete->prev != NULL )
    {
        _ItemToDelete->prev->next = _ItemToDelete->next;
    }
    //std::cout << "[DLLI]: Deleting a middle item in list with ID = " << _ItemID <<
    //" and Proc Time " << _ItemProcTime << std::endl;

    //std::cout << "[DLLI]: Case 4 reached" << std::endl;
    delete _ItemToDelete;
    _CountOfItems--;
    return;
}
