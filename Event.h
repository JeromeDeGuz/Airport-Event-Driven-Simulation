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


#ifndef EVENT_H_
#define EVENT_H_

#include "Plane.h"

//Forward reference for Simulation b/c we are only using it for a parameter

class Simulation;

class Event {
   private:
    int requestTime;
    Plane* plane;

   public:
    // Fully virtual Abstract class
    virtual void process(Simulation*) = 0;
    // The Event class cannot implement a process method
    // Force the subclasses to implement

    // Constructor
    Event();
    Event(const int, Plane*);
    virtual ~Event();

    // getters
    int getRequestTime();
    Plane* getPlane();
    virtual void print();
};

#endif