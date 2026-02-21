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


#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>  //necessary to use ifstream (to open a file)
#include <sstream>  //necessary for using stringstream
//iostream & string include in Priority Queue

#include "PriorityQueue.h"
#include "RunwayManager.h"

class Simulation {
   private:
    static int atcId;
    PriorityQueue* eventQueue;  // place all events in here
    Queue* waitQueue;           // place all events that are waiting for a runway
    RunwayManager* runwayMgr;   // used to check runways
    ifstream inputFile;
    int timeWasted;

   public:
    Simulation();
    Simulation(const int);
    virtual ~Simulation();
    void runSimulation();

    // setters
    void openFile(const string);
    void closeFile();
    void readFileLine();
    void scheduleEvent( Event*);
    void incrementTimeWasted(const int);
    void enqueueWaitQueue( Event*);
    void print();

    // getters
    RunwayManager* getRunwayMgr();
    Event* dequeueWaitQueue();
    int getTimeWasted();
    bool isWaitQueueEmpty();
};

#endif