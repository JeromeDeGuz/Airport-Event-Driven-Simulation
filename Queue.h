//-----------------------------------------
// CLASS: Queue
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this class it to 
//  create and maintain an Queue ADT
//  the Queue will keep track of where the head, tail
//  and the lastLand (event) nodes in the queue.
//  The Queue class will contain methods that 
//  is used to manage the Queue, such as
//  enqueue, dequeue, isEmpty, setters, and getters.
//
//  We will enqueue onto the tail, and dequeue the head
//  
//  The Queue ADT will maintain a sorted data structure
//  with Landing Event types at the head and Takeoff Event types
//  at the end, so there are 2 layers of sorted data structures
//  Landing -> Takeoff
//  if Event is Landing place at the end of lastLand
//  if Event is Takeoff place at the tail
//
//-----------------------------------------


#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
   private:
    Node* tail;
    Node* head;
    // will keep a pointer to where the last Landing Event
    // so that when we 

   public:
    // Constructor
    Queue();

    // Destructor
    virtual ~Queue();

    // Getters
    Node* getTail();
    Node* getHead();
    bool isEmpty();
    virtual void print();

    // Setters
    void setTail(Node*);
    void setHead(Node*);
    virtual void enqueue(Event*);  // to be overwritten
    virtual Event* dequeue();
};

#endif