//-----------------------------------------
// CLASS: RequestTakeoff
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this Event subclass is to 
//  process the plane contained within it that is
//  requesting to takeoff. As well as refine the print method
//
//-----------------------------------------

#ifndef REQUESTTAKEOFF_H
#define REQUESTTAKEOFF_H

#include "Event.h"
#include "Simulation.h"

class RequestTakeoff : public Event {
   private:
   public:
    // Constructor
    RequestTakeoff();
    RequestTakeoff(const int, Plane*);  // calls the constructor of the parent class
    virtual ~RequestTakeoff();

    void process(Simulation*) override;
    void print() override;
};

#endif