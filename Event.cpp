//-----------------------------------------
// CLASS: Event
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this class to create an Event object
//  This is an abstract event class that will be inherited by its subclasses
//  We will not be creating an Event class, but will be creating subclasses
//  The Event will contain a Plane object as well as when the requestTime
//  of the Event has been issued
// 
//-----------------------------------------

#include "Event.h"

// Constructor
Event::Event() : requestTime(0), plane(nullptr) {}
Event::Event(const int time, Plane* p) : requestTime(time), plane(p) {}

// Destructor
Event::~Event() {
    // cout << "Event Destroyed" << endl;
    // uncomment to see that it does work and is called as well as delete event and delete ndoe
}

int Event::getRequestTime() {
    return requestTime;
}

Plane* Event::getPlane() {
    return plane;
}

void Event::print() {
    // Implemention of print that will be inherinted by subclasses
    // and eventually used by them to in replacement (redefinition)
    cout << "TIME: " << requestTime << " -> " << plane->print();
}


