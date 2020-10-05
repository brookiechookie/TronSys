// Item.cpp
//
// Implementation file for the Item class

#include "Item.h"

/* Steps
      1. First we want to create a vector which is going to store each item
          and assign each item an ID number

*/

//---------------------------------------------------------------
Item::Item()
{

}


//---------------------------------------------------------------
Item::Item( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}
