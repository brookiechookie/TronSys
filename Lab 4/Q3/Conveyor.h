// Conveyor.h
//
// Date created:  6.9.20
// Creator:       Donald G Dansereau, 2019. Edits by Brooke Agostino
// Purpose:       Header file for a simulated conveyor belt
//
// Modifications:
//

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

//---------------------------------------------------------------
// Simulate a conveyor belt. This version counts how many
// objects are on the belt, accepts requests to add and remove
// objects, and can report how many items are on the belt to other
// classes.
class Conveyor
{
    public:
        void Init();
        void AddItems( int n );
        void RemoveItems( int n );
        void Report();
        int getConvItemNum();

    private:
        int _NumItemsOnConveyor;
};



#endif
