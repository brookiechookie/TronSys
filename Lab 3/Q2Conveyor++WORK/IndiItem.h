// IndiItem.h
//
// Header file for the individual items on the conveyor belt

#ifndef _INDIITEM_H
#define _INDIITEM_H

#include "ItemParent.h"


class IndiItem: public ItemParent
{

    public:
        IndiItem( int NItemsAdded );


    private:
        int _ItemID;

};



#endif
