//-----------------------------------------
// CLASS: Takeoff
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this Event subclass
//  is to process the plane contained within
//  the class itself that is going to Takeoff.
//  As well as refine the print method
//
//-----------------------------------------

#ifndef TAKEOFF_H
#define TAKEOFF_H

#include "Event.h"
#include "Simulation.h"

class Takeoff : public Event {
   private:
    int runwayNum;

   public:
    Takeoff();
    Takeoff(const int, Plane*, const int);
    virtual ~Takeoff();

    virtual void process(Simulation*) override;
    virtual void print() override;
};

#endif
