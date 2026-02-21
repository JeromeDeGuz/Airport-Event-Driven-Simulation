//-----------------------------------------
// CLASS: RunwayManager
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of the RunwayManager class is to 
//  maintain the runways of the airport, 
//  initializing how many runways are needed for the simulation
//  as well as getters and setters for the runways 
//
//-----------------------------------------

#include "RunwayManager.h"

RunwayManager::RunwayManager() {
    numRunways = 0;
    runWays = new bool[0];
}

RunwayManager::RunwayManager(const int num) {
    numRunways = num;
    runWays = new bool[numRunways];

    // initialize all runways to free
    for (int i = 0; i < numRunways; i++) {
        runWays[i] = false;
    }
}

RunwayManager::~RunwayManager() {
    delete[] runWays;
}

// getters

// goes through runways and returns the first free one
int RunwayManager::getFreeRunway() {
    int freeRunway = -1;
    for (int i = 0; i < numRunways; i++) {
        if (runWays[i] == false) {
            runWays[i] = true;
            freeRunway = i;
        }
    }
    return freeRunway;
    // returns -1 if no free runways
}

int RunwayManager::getNumRunways() {
    return numRunways;
}

// setters

void RunwayManager::setRunways(const int num) {
    numRunways = num;
    runWays = new bool[numRunways];

    // initialize all runways to free
    for (int i = 0; i < numRunways; i++) {
        runWays[i] = false;
    }
}

void RunwayManager::setRunwayOccupied(const int runway) {
    runWays[runway] = true;
}

void RunwayManager::setRunwayUnoccupied(const int runway) {
    runWays[runway] = false;
}

bool RunwayManager::checkOccupied(const int runway) {
    return runWays[runway];
}