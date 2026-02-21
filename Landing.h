//-----------------------------------------
// CLASS: Landing
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this Event subclass
//  is to process the plane contained within
//  the class itself that is Landing.
//  As well as refine the print method
//
//-----------------------------------------


#ifndef LANDING_H
#define LANDING_H

#include "Event.h"
#include "Simulation.h"

class Landing : public Event {
   private:
    int runwayNum;

   public:
    Landing();
    Landing(const int, Plane*, const int);
    virtual ~Landing();
    void process(Simulation*) override;
    void print() override;
};

#endif