//-----------------------------------------
// CLASS: PriorityQueue 
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this class is to implement a subclass
//  of the Queue superclass, to create a more specific ADT
//  The PriorityQueue will store everything the Queue class stores,
//  but will store it in order of requesTime and if they are the same
//  order by ATCID.
//
//  The PriorityQueue class will override the enqueue method
//   that has been inherited from the superclass Queue
//-----------------------------------------


#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Queue.h"

class PriorityQueue : public Queue {
   private:
   public:
    // Constructor
    PriorityQueue();  // calls the constructor of the parent class
    virtual ~PriorityQueue(); // Destructor
    
    // Setters
    void enqueue(Event *) override;
};

#endif