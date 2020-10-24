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

/*
    // Create the new item object
    Item myItem1( 1, 4.32 );

    // Create the list of Item references
    DoublyLinkedList<Item> ItemList;

    // Feed in the new Item object made
    ItemList.push_back( myItem1 );

*/
/*
    DoublyLinkedList<int> intList;
    int a = 1;
    intList.push_back( a );
*/

/*
    Item myItem1( 22, 4.2343 );

    DoublyLinkedList<Item&> ItemList;
    ItemList.push_back( myItem1 );
*/



    // Variable to store the number of objects that are in the list
    int NumberOfItems = 0;
    // Create a new list which contains references to the items
    DoublyLinkedList<int> intList;
    int a = 1;
    intList.push_back( a );
    NumberOfItems = intList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    intList.printList();

    a++;
    intList.push_back( a );
    NumberOfItems = intList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    intList.printList();

    a++;
    intList.push_back( a );
    NumberOfItems = intList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    intList.printList();

    a++;
    intList.push_back( a );
    NumberOfItems = intList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    intList.printList();

    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );




    std::cout << "[Main]: I am done here." << std::endl;

}
