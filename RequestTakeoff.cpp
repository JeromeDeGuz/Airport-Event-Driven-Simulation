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

#include "RequestTakeoff.h"
#include "Takeoff.h"

// Constructor
RequestTakeoff::RequestTakeoff() : Event() {}
RequestTakeoff::RequestTakeoff(const int time, Plane* plane) : Event(time, plane) {}
RequestTakeoff::~RequestTakeoff() {}


//------------------------------------------------------
// RequestTakeoff::process
//
// PURPOSE: Override the superclass abstract method to implement.
//  The purpose is to process the class itself (this),
//  checking to make sure if there is a runway open and pass it to
//  a new Takeoff event with the contents of (this) event, the plane.
//  if there is no runway open, place the Takeoff in the waitQueue.
//  Finally, print the contents of this event, and read the next line in the simulation
//
// PARAMETERS: The Simulation pointer parameter will be used
//  to access methods needed to keep our simulation going.
//  Like fetching RunwayMgr to access its methods, and place Takeoff event
//  into PriorityQueue or waitQueue.
//------------------------------------------------------
void RequestTakeoff::process(Simulation* sim) {
    // the simulation has indicated that we are to process the next event in queue.
    // The next event in queue. Is ourselves.
    RunwayManager* runwayMgr = sim->getRunwayMgr();
    Takeoff* takeoff;
    int runwayNum;

    runwayNum = runwayMgr->getFreeRunway();

    if (runwayNum >= 0) {
        // if there is an open runway, the runwayNum will always be greater than 0
        runwayMgr->setRunwayOccupied(runwayNum);
        takeoff = new Takeoff(getRequestTime(), getPlane(), runwayNum);
        sim->scheduleEvent(takeoff);    // process event immediately

    } else {    
        // no runway open because runwayNum is -1, place event into our waitlist not priority queue
        takeoff = new Takeoff(getRequestTime(), getPlane(), runwayNum);
        takeoff->getPlane()->setWaitTime(getRequestTime());
        sim->enqueueWaitQueue(takeoff); // put this event into the waitlist

    }
    print();
    sim->readFileLine();
    // this is what makes this a event driven simulation
    // we can only take in the next event after processing this one
}

void RequestTakeoff::print() {
    Event::print();
    cout << "ready for takeoff." << endl;
}
