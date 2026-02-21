//-----------------------------------------
// CLASS: CompleteEvent
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of the Event subclass is
//  to process the plane contained within the class
//  itself that is going to be Complete.
//  As well as refine the print method.
//
//-----------------------------------------

#ifndef COMPLETEEVENT_H
#define COMPLETEEVENT_H

#include "Event.h"
#include "Simulation.h"


class CompleteEvent : public Event {
   private:
    int runwayNum;

   public:
    // Constructor
    CompleteEvent();
    CompleteEvent(int, Plane*, int);
    virtual ~CompleteEvent();

    // accessors
    void process(Simulation*) override;
    void print() override;
};

#endif