// main.cpp
//
// Date:    8.10.20
// Creator: Brookie
// Purpose: Main file for the test DIY container

#include "DoublyLinkedList.h"
#include "Item.h"

//------------------------------------------------------------------------------
int main()
{

    // First create the head of the list which we will always have access to
    // then create the actual list and point it to the reference head
    // We had a vector of item objects in Q2, now we are going to have a list
    // of item objects

    //Item* HeadRef = NULL;
    //DoublyLinkedList* myList;

    DoublyLinkedList myList;

    //int _UniqueID = 2;

    //Item* pItems = new Item( _UniqueID );
    //myList.push_back( pItems, _UniqueID);
    myList.push_back( 1 );
    myList.push_back( 2 );
    myList.push_back( 3 );
    myList.printList( );
    myList.pop_front( );
    myList.pop_front( );
    myList.pop_front( );
    myList.printList( );
    myList.push_back( 4 );
    myList.push_back( 5 );
    myList.printList( );
    myList.pop_front( );
    myList.pop_front( );
    myList.printList( );

    std::cout << "[Main]: I am done here." << std::endl;



    /*
    Item* head = NULL;

    printList(head);

  	// Insert 6. So linked list becomes 6->NULL
  	push_back(&head, 6);

  	// Insert 7 at the beginning. So
  	// linked list becomes 7->6->NULL
  	push_back(&head, 7);

  	// Insert 1 at the beginning. So
  	// linked list becomes 1->7->6->NULL
  	push_back(&head, 1);

  	// Insert 4 at the end. So linked
  	// list becomes 1->7->6->4->NULL
  	push_back(&head, 4);


  	std::cout << "[Main]: Created DLL is: " << std::endl;
  	printList(head);
    pop_front(&head);
    printList(head);
    pop_front(&head);
    printList(head);
    pop_front(&head);
    printList(head);

    pop_front(&head);
    printList(head);
    pop_front(&head);
    printList(head);
    push_back(&head, 10);
    printList(head);
    */

}
