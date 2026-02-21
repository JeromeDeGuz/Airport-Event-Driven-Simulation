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
//
//-----------------------------------------

#include "PriorityQueue.h"

// Constructor
PriorityQueue::PriorityQueue() : Queue() {}
PriorityQueue::~PriorityQueue() {}

//------------------------------------------------------
// PriorityQueue::enqueue
//
// PURPOSE: To store the event passed in parameter in our PriorityQueue
//  we will sort by requestTime, and if they are the same, sort by AtcId.
//  Traverse through linked list and find where to place event
//
// PARAMETERS: Pointer to the event that we will store into queue
//------------------------------------------------------
void PriorityQueue::enqueue(Event* event) {
    Node* node = new Node(event, nullptr);
    Node* currNode = getHead();
    Node* prevNode = nullptr;

    // if empty, head and tail are the same
    if (isEmpty()) {
        Queue::enqueue(event);
        // use super class method since it handles enqueue in empty adt
    } else {
        while (currNode != nullptr && (node->getEvent()->getRequestTime() > currNode->getEvent()->getRequestTime() 
        || (node->getEvent()->getRequestTime() == currNode->getEvent()->getRequestTime() 
        && node->getEvent()->getPlane()->getAtcId() > currNode->getEvent()->getPlane()->getAtcId()))) {
        // this while condition will sort by requestTime, and if nodes have the same requestTime, will sort by ATCID

            prevNode = currNode;
            currNode = currNode->getNext();
        }
        if (prevNode != nullptr) {  
            // adding inside list
            prevNode->setNext(node);
            node->setNext(currNode);
        } else {  
            // adding at the head
            setHead(node);
        }
    }
}