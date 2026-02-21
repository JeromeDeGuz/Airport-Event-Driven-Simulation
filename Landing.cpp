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


#include "Landing.h"
#include "CompleteEvent.h"

Landing::Landing() : Event() {}
Landing::Landing(const int time, Plane* plane, const int rwNum) : Event(time, plane), runwayNum(rwNum) {}
Landing::~Landing() {}


//------------------------------------------------------
// Landing::process
//
// PURPOSE: Override the superclass abstract method to implement.
//  The purpose is to process the class itself (this),
//  setting the runway to occupied for the plane,
//  increment the waketime of a plane since it is landing,
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
void Landing::process(Simulation* sim) {
    RunwayManager* runwayMgr;
    CompleteEvent* complete;
    runwayMgr = sim->getRunwayMgr();

    runwayMgr->setRunwayOccupied(runwayNum);
    // landing adds +2 minutes to time because plane is landing
    getPlane()->incrementWakeTime(2);

    //increment timeWasted only if plane did incur WaitTime
    if (getPlane()->getWaitTime() != 0) {
        sim->incrementTimeWasted(getRequestTime() - getPlane()->getWaitTime());
    }

    complete = new CompleteEvent(getRequestTime() + getPlane()->getWakeTime(), getPlane(), runwayNum);
    sim->scheduleEvent(complete);
    print();
    // do not delete complete event, still needed
}

void Landing::print() {
    Event::print(); // call superclass and refine method
    cout << "cleared for landing on runway " << runwayNum + 1 << ". (time req. for landing: " << getPlane()->getWakeTime() << ")" << endl;
}