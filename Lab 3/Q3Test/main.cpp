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
    DoublyLinkedList myList;

    int sizeUp = 0;

    myList.push_back( 1 );
    myList.push_back( 2 );
    myList.push_back( 3 );
    myList.printList( );
    sizeUp = myList.Size();
    std::cout << "[Main]: Size of List is " << sizeUp << std::endl;


    myList.pop_front( );
    myList.pop_front( );
    myList.pop_front( );
    myList.printList( );
    sizeUp = myList.Size();
    std::cout << "[Main]: Size of List is " << sizeUp << std::endl;


    myList.push_back( 4 );
    myList.push_back( 5 );
    myList.printList( );
    sizeUp = myList.Size();
    std::cout << "[Main]: Size of List is " << sizeUp << std::endl;

    myList.pop_front( );
    myList.pop_front( );
    myList.printList( );
    sizeUp = myList.Size();
    std::cout << "[Main]: Size of List is " << sizeUp << std::endl;

    std::cout << "[Main]: I am done here." << std::endl;

}
