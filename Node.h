//-----------------------------------------
// CLASS: Node
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of the Node class is to
//  be a container for the ADT for the 
//  Queue and the PriorityQueue.
//  The Node class contains the Event that will be
//  Stored in the ADT as well as a pointer to 
//  the next Node in the ADT.
//
//-----------------------------------------


#ifndef NODE_H_
#define NODE_H_

#include "Event.h"

class Node {
   private:
    Event* event;
    Node* next;

   public:
    // Constructor
    Node();
    Node(Event*, Node*);
    virtual ~Node();

    // Getters
    Event* getEvent();
    Node* getNext();

    // Setters
    void setNext(Node*);
    void print();
};

#endif