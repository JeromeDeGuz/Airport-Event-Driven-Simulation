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

#include "CompleteEvent.h"
#include "Landing.h"
#include "Takeoff.h"

// Constructors
CompleteEvent::CompleteEvent() : Event() {}
CompleteEvent::CompleteEvent(int time, Plane* plane, int rwNum) : Event(time, plane), runwayNum(rwNum) {}
CompleteEvent::~CompleteEvent() {}


//------------------------------------------------------
// CompleteEvent::process
//
// PURPOSE: Override the superclass abstract method to implement.
//  The purpose is to process the class itself (this), setting the
//  Runway used by the plane and printing the end result.
//  Since this is the end of the events for a plane, take the next
//  plane that is in the waitQueue and place them into the PriorityQueue
//
//  Once CompleteEvent is finished, delete plane contained with in.
//  Simulation will handle deleting (this) event
//  
// PARAMETERS: The Simulation pointer parameter will be used
//  to access methods needed to keep our simulation going.
//  Like fetching RunwayMgr and scheduling the next event from
//  the waitQueue.
//------------------------------------------------------
void CompleteEvent::process(Simulation* sim) {
    // the simulation has indicated that we are to process the next event in queue.
    RunwayManager* rwMgr = sim->getRunwayMgr();
    Event* nextEvent;
    Takeoff* take;
    Landing* land;
    string reqType;

    rwMgr->setRunwayUnoccupied(runwayNum);

    if (sim->isWaitQueueEmpty() == false) {
        nextEvent = sim->dequeueWaitQueue();
        reqType = nextEvent->getPlane()->getRequestType();

        if (reqType == "landing") {
            land = new Landing(getRequestTime(), nextEvent->getPlane(), rwMgr->getFreeRunway());
            sim->scheduleEvent(land);

        } else if (reqType == "takeoff"){
            take = new Takeoff(getRequestTime(), nextEvent->getPlane(), rwMgr->getFreeRunway());
            sim->scheduleEvent(take);
        }
    }

    print();
    //do not delete land/take because it will still be used, delete elsewhere
    delete getPlane();  // delete plane contained within event, since simulation will delete (this) event.
}

void CompleteEvent::print() {
    Event::print();
    cout << "has cleared the runway " << runwayNum + 1 << "." << endl;
}
