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

#include "Node.h"

// Null constructor
Node::Node(): event(nullptr), next(nullptr) {}

// Constructor

Node::Node(Event* e, Node* n) : event(e), next(n) {}
Node::~Node(){
    // cout << "Node Destroyed" << endl;
    // uncomment to see that it does work and is called as well as delete event and delete ndoe
}

// Getters
Event* Node::getEvent() {
    return event;
}

Node* Node::getNext() {
    return next;
}

void Node::print() {
    event->print(); //make event handle its own print
}

// Setters
void Node::setNext(Node* n) {
    if (n == nullptr) {
        next = nullptr;
    } else {
        next = n;
    }
}