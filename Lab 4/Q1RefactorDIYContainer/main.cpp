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
    // Variable to store the number of elements that are in the list
    int NumberOfItems = 0;

    //--------------------------------------------------------------------------

    // Create a new list of integers
    DoublyLinkedList<int> intList;

    // Create integers and put them into the list
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    intList.push_back( a );
    intList.push_back( b );
    intList.push_back( c );
    intList.push_back( d );

    // Print the items in the list and the size of the List
    intList.printList();
    NumberOfItems = intList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;




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

    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    /*
    // The below code is to test whether class objects can be added to the list
    // Some unique functions have been created to test its operation

    // Create the new item object, assigning ID's to each Item
    int ID1 = 1;
    int ID2 = 2;
    int ID3 = 3;
    Item ItemLolly  ( ID1 );
    Item ItemBanana ( ID2 );
    Item ItemNut    ( ID3 );

    // Create the list of Item references
    DoublyLinkedList<Item> ItemList;

    // Feed in the new Item object made
    ItemList.push_back( ItemLolly   );
    ItemList.push_back( ItemBanana  );
    ItemList.push_back( ItemNut     );

    // Print List and advice how many items are in the list
    ItemList.printItemList();
    NumberOfItems = ItemList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;

    // Pop Item from the List
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.printItemList();
    */
    //--------------------------------------------------------------------------

/*
    int NumberOfItems = ItemList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    ItemList.printItemList();

    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
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





    /*
    DoublyLinkedList<std::string> StringList;

    std::string c("chocolate");
    std::string d("hot");

    StringList.push_back(c);
    StringList.push_back(d);

    int NumberOfItems = StringList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    StringList.printList();

    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    */




    std::cout << "[Main]: I am done here." << std::endl;

}
