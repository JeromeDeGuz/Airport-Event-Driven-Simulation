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

#include "RequestLanding.h"
#include "Landing.h"

// Constructor
RequestLanding::RequestLanding() : Event() {}
RequestLanding::RequestLanding(const int time, Plane* plane) : Event(time, plane) {}
RequestLanding::~RequestLanding() {}

//------------------------------------------------------
// RequestLanding::process
//
// PURPOSE: Override the superclass abstract method to implement.
//  The purpose is to process the class itself (this),
//  checking to make sure if there is a runway open and pass it to
//  a new landing event with the contents of (this) event, the plane.
//  if there is no runway open, place the landing in the waitQueue.
//  Finally, print the contents of this event, and read the next line in the simulation
//
// PARAMETERS: The Simulation pointer parameter will be used
//  to access methods needed to keep our simulation going.
//  Like fetching RunwayMgr to access its methods, and place Landing event
//  into PriorityQueue or waitQueue.
//------------------------------------------------------
void RequestLanding::process(Simulation* sim) {
    // we have been summoned by the simulation to process the next event in the queue contained inside the simulation
    Landing* landing;
    RunwayManager* runwayMgr = sim->getRunwayMgr();
    int runwayNum;

    runwayNum = runwayMgr->getFreeRunway();

    if (runwayNum >= 0) {
        // if there is open runway process immediately
        runwayMgr->setRunwayOccupied(runwayNum);
        landing = new Landing(getRequestTime(), getPlane(), runwayNum);
        // process event immediately
        sim->scheduleEvent(landing);
    
    } else {
        // no runway available because runwayNum is -1
        landing = new Landing(getRequestTime(), getPlane(), runwayNum); // we create a new landing event that will happen when the current event is finished
        landing->getPlane()->setWaitTime(getRequestTime());     // track waitTime for plane
        sim->enqueueWaitQueue(landing);
        // put this event into the waitlist
    }

    print();
    sim->readFileLine();    
    // this is what makes this a event driven simulation
    // we can only take in the next event after processing this one
}

void RequestLanding::print() {
    Event::print();
    cout << "inbound for landing." << endl;
}