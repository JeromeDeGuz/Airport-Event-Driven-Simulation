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

#include "Takeoff.h"
#include "CompleteEvent.h"

Takeoff::Takeoff() : Event() {}
Takeoff::Takeoff(const int time, Plane* plane, const int rwNum) : Event(time, plane), runwayNum(rwNum) {}
Takeoff::~Takeoff() {}


//------------------------------------------------------
// Takeoff::process
//
// PURPOSE: Override the superclass abstract method to implement.
//  The purpose is to process the class itself (this),
//  setting the runway to occupied for the plane, 
//  calcualate the waitTime the plane had to incur, from when it
//  first requested to land and from when it is starting its landing event.
//  Once finished with landing, create a new CompleteEvent and pass the
//  information of the plane within (this) event and pass it to CompleteEvent.
//  Finally schedule this new CompleteEvent in the simulation, and print this.
//  
// PARAMETERS: The Simulation pointer parameter will be used
//  to access methods needed to keep our simulation going.
//  Like fetching RunwayMgr and scheduling the new CompleteEvent
//
//------------------------------------------------------
void Takeoff::process(Simulation* sim) {
    // //the simulation has indicated that we are to process the next event in queue.

    // only increment TimeWasted if the plane has incur WaitTime 
    if (getPlane()->getWaitTime() != 0) {
        sim->incrementTimeWasted(getRequestTime() - getPlane()->getWaitTime());
    }

    RunwayManager* runwayMgr = sim->getRunwayMgr();

    // create a complete event
    CompleteEvent* complete = new CompleteEvent(getRequestTime() + getPlane()->getWakeTime(), getPlane(), runwayNum);
    // schedule the complete event
    sim->scheduleEvent(complete);
    // set the runway to occupied
    runwayMgr->setRunwayOccupied(runwayNum);
    // print the takeoff event
    print();
}

void Takeoff::print() {
    Event::print();     //call superclass 
    cout << "cleared for takeoff on runway " << runwayNum + 1 << ". (time req. for takeoff: " << getPlane()->getWakeTime() << ")" << endl;
    //refine the print method
}
