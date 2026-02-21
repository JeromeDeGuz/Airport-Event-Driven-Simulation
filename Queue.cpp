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

#include "Queue.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

Node* Queue::getHead() {
    return head;
}

Node* Queue::getTail() {
    return tail;
}

bool Queue::isEmpty() {
    return (head == nullptr);
    // if (head == nullptr) {
    //     return true;
    // }
    // return false;
}

void Queue::setTail(Node* n) {
    Node* oldTail = tail;
    tail = n;
    oldTail->setNext(tail);
}

void Queue::setHead(Node* n) {
    Node* oldHead = head;

    head = n;
    head->setNext(oldHead);
}

//------------------------------------------------------
// Queue::enqueue
//
// PURPOSE: To store the event passed in parameter in our waitQueue,
//  we will sort by 2 blocks landing first then takeoff second. Since
//  landing is more important then takeoff. Place every takeoff at the tail
//  and place landing at the head so it will be next up to dequeue Then in each block sort by
//  requestTime so take whoever requested to land or takeoff is sorted.
//  Traverse through linked list and find where to place event
//
// PARAMETERS: Pointer to the event that we will store into queue
//------------------------------------------------------
void Queue::enqueue(Event* event) {
    Node* node = new Node(event, nullptr);
    Node* currNode = getHead();
    Node* prevNode = nullptr;


    if (isEmpty()) {
        // if empty, head and tail point to same node
        head = node;
        tail = node;
    } else {
        // add into adt sorted by landing first then take off

        if (node->getEvent()->getPlane()->getRequestType() == "takeoff") {
            setTail(node);
            // place takeoff at the tail, placing it at the end of importance compared to other takeoff events
            // side effect is this also sorts it by requestTime

        } else {  // now deal with sorting landing events
            if (currNode->getEvent()->getPlane()->getRequestType() == "takeoff") {
                // in our queue there is nothing but takeoff
                // place Landing node at the head so it can be processed first
                setHead(node);
            } else {
                // in our queue there exists Landing nodes, so place new Landing node in correct position
                // we will be storing Landing nodes in order of requestTime
                while (currNode != nullptr && node->getEvent()->getRequestTime() > currNode->getEvent()->getRequestTime()) {
                    prevNode = currNode;
                    currNode = currNode->getNext();
                }
                // We have found the position to place Landing node
                if (prevNode != nullptr) {  // adding inside list
                    prevNode->setNext(node);
                    node->setNext(currNode);
                }  // no need to check for placing at the beginning, this was handled earlier
            }
        }
    }
}

//------------------------------------------------------
// Queue::dequeue
//
// PURPOSE: dequeue the node at the head of the queue,
//  when we dequeue the node we pass the event within the node.
//  Meaning we no longer need the node, lets clean up our memory
//  so we have no memory leaks by deleting that head node.
//
// Returns: return a pointer to the Event contain in the head node.
//------------------------------------------------------
Event* Queue::dequeue() {
    Event* event;
    Node* newHead;
    if (!isEmpty()) {
        event = head->getEvent();   // store the event to be dequeued
        newHead = head->getNext();  // store the next node
        delete head;                // delete the head node
        head = newHead;             // set the head to the next node
    }

    return event;
    // if queue is empty, then the return will be nullptr
}

void Queue::print() {
    Node* currNode = head;

    if (isEmpty() == false) {
        while (currNode != nullptr) {
            currNode->print();
            currNode = currNode->getNext();
        }
    }
}