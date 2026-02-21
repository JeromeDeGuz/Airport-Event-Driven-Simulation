//-----------------------------------------
// CLASS: RequestLanding
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this Event subclass is to 
//  process the plane contained within in it that is
//  requesting to land. As well as refine the print method
//
//-----------------------------------------

#ifndef REQUESTLANDING_H
#define REQUESTLANDING_H

#include "Event.h"
#include "Simulation.h"

class RequestLanding : public Event {
   private:
   public:
    // Constructor
    RequestLanding();
    RequestLanding(const int, Plane*);  // calls the constructor of the parent class
    virtual ~RequestLanding();

    void process(Simulation*) override;
    void print() override;
};

#endif