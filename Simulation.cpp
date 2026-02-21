//-----------------------------------------
// CLASS: Simulation
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of the simulation class is to manage
//  the creation and operation of the simulation.
//  Handling the creation of PriorityQueue, waitQueue, and RunwayManager objects,
//  managing the command-line argument and the file.
//  The simulation will be passing the events and planes that need to be processed
//  to their respective classes, and will keep store how much time has been wasted.
//
//-----------------------------------------

#include "Simulation.h"

#include "RequestLanding.h"
#include "RequestTakeoff.h"

int Simulation::atcId = 1;  // initialize static variable
// so that no matter how many simulations, the atcId is constant

Simulation::Simulation() {
    // cout << "Creating Simulation" << endl;
    eventQueue = new PriorityQueue();
    waitQueue = new Queue();
    runwayMgr = new RunwayManager(1);  // DEFAULT 1 RUNWAY
    timeWasted = 0;
}

Simulation::Simulation(const int rw) {
    eventQueue = new PriorityQueue();
    waitQueue = new Queue();
    runwayMgr = new RunwayManager(rw);
    // parameter will be used to set how many runways to simulate
    timeWasted = 0;
}

Simulation::~Simulation() {
    // cout << "Deleting Simulation" << endl;
    delete eventQueue;
    delete runwayMgr;
    delete waitQueue;
}

//------------------------------------------------------
// Simulation::runSimulation
//
// PURPOSE: dequeue our PriorityQueue and make event process.
//  Dequeue will delete the node created, and this method will
//  delete the event within it.
//
//------------------------------------------------------
void Simulation::runSimulation() {
    cout << "Simulation begins..." << endl;
    Event* event;

    while (eventQueue->isEmpty() == false) {
        event = eventQueue->dequeue();  // when an event is dequeue. That node is deleted
        event->process(this);           // grab the next event in priority queue
        delete event;                   // once we process this event, delete it
    }
}

// Setters
void Simulation::openFile(const string filename) {
    inputFile.open(filename);
}

void Simulation::closeFile() {
    inputFile.close();
}


//------------------------------------------------------
// Simulation::readFileLine
//
// PURPOSE: Handle reading a single line from the file,
//  parsing the contents of the line and converting them to their
//  respective variables and used to create a plane object.
//  from there create either a landing or takeoff event passing the 
//  plane object and time. Increment atcid for each plane as well
//  
//------------------------------------------------------
void Simulation::readFileLine() {
    string line;
    Plane* newPlane;
    RequestTakeoff* newTake;
    RequestLanding* newLand;

    // Initializing for file
    string token;
    int time = 0;
    string callSign = "";
    string flightNum = "";
    string size = "";
    string requestType = "";

    if (getline(inputFile, line))  // gets the next line from the file and saves it in 'line', if there is one
    {
        stringstream sst(line);  // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
        sst >> token;        // grabbing the next token (reading time)
        time = stoi(token);  // converting time (string format) to an int
        sst >> callSign;     // grabbing the next token (reading call sign)
        sst >> flightNum;    // grabbing the next token (reading flight number)
        sst >> size;         // grabbing the next token (reading plane size)
        sst >> requestType;  // grabbing the next token (reading request type, either landing or takeoff)


        newPlane = new Plane(callSign, stoi(flightNum), size, requestType, Simulation::atcId);
        Simulation::atcId += 1;  // increment atcId

        if (requestType == "takeoff") {
            newTake = new RequestTakeoff(time, newPlane);  // everyone will always request either takeoff or landing
            this->scheduleEvent(newTake);
        } else {
            newLand = new RequestLanding(time, newPlane);  // everyone will always request either takeoff or landing
            this->scheduleEvent(newLand);
        }
    }
}

void Simulation::scheduleEvent( Event* event) {
    eventQueue->enqueue(event);  // places event into the priority queue
}

void Simulation::incrementTimeWasted(const int time) {
    timeWasted += time;
}

void Simulation::enqueueWaitQueue(Event* event) {
    waitQueue->enqueue(event);
}

void Simulation::print() {
    cout << endl
         << "#######################" << endl
         << "The simulation has ended." << endl
         << "The number of runways was " << runwayMgr->getNumRunways() << "." << endl
         << "The total amount of time wasted because runways were not available was " << timeWasted << " minutes." << endl
         << "#######################" << endl
         << endl;
}

// Getters
RunwayManager* Simulation::getRunwayMgr() {
    return runwayMgr;
}

Event* Simulation::dequeueWaitQueue() {
    return waitQueue->dequeue();
}

int Simulation::getTimeWasted() {
    return timeWasted;
}

bool Simulation::isWaitQueueEmpty() {
    return waitQueue->isEmpty();
}
 