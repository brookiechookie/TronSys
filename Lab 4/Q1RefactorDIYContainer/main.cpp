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
    // The following section test the list can handle integers
    /*
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

    // Pop the items from the list. Intentionally delete more items than there
    // is in the list to check DLL is robust
    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );
    intList.pop_front( );
    */
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

    // Pop the items from the list. Intentionally delete more items than there
    // is in the list to check DLL is robust
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.pop_front( );
    ItemList.printItemList();    // Pop Item from the List
    */
    //--------------------------------------------------------------------------




    //--------------------------------------------------------------------------
    // The below code test the operation of the list with strings

    // Create the string list
    DoublyLinkedList<std::string> StringList;

    // Create strings and put them into the list
    std::string a( " hot "      );
    std::string b( " chocolate ");
    std::string c( " tastes "   );
    std::string d( " better "   );
    std::string e( " at the "   );
    std::string f( " snow"      );
    StringList.push_back(a);
    StringList.push_back(b);
    StringList.push_back(c);
    StringList.push_back(d);
    StringList.push_back(e);
    StringList.push_back(f);

    // Print List and advice how many items are in the list
    NumberOfItems = StringList.Size();
    std::cout<< "[Main]: Number of items in the list = " << NumberOfItems <<
    std::endl;
    StringList.printList();

    // Pop the items from the list. Intentionally delete more items than there
    // is in the list to check DLL is robust
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );
    StringList.pop_front( );

    //--------------------------------------------------------------------------

    std::cout << "[Main]: I am done here." << std::endl;

}
