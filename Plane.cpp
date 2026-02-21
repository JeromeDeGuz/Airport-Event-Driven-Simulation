//-----------------------------------------
// CLASS: Plane
//
// Author: Jerome De Guzman, #7917983
//
// REMARKS: The purpose of this class is to 
//  create a plane object, that contains data 
//  members that are related to a plane
//  as well as the respective getters and setters needed
//
//-----------------------------------------

#include "Plane.h"

Plane::Plane() {
    callSign = "N/A";
    flightNum = 0;
    size = "N/A";
    requestType = "N/A";
    waitTime = 0;
}

// Constructor to initialize all values, as well as calculate waketime
Plane::Plane(string sign, int num, string s, string req, int id) {
    callSign = sign;
    flightNum = num;
    size = s;
    requestType = req;
    atcId = id;
    waitTime = 0;

    // we are including the additional 1 minute spent on the runway by the plane for takeoff and landing
    if (s == "super") {
        wakeTime = 4;
    } else if (s == "heavy") {
        wakeTime = 3;
    } else if (s == "large") {
        wakeTime = 2;
    } else {
        // size == "small"
        wakeTime = 1;
    }
}

Plane::~Plane() {
    // cout << "Plane " << callSign << " has been destroyed." << endl;
    // uncomment to see that it does work and is called
}

string Plane::print() {
    return callSign + " " + to_string(flightNum) + " (" + to_string(atcId) + ") " + size + " ";
}

// getters
string Plane::getRequestType() {
    return requestType;
}

int Plane::getAtcId() {
    return atcId;
}

int Plane::getWakeTime() {
    return wakeTime;
}

int Plane::getWaitTime() {
    return waitTime;
}

// setters

void Plane::incrementWakeTime(const int time) {
    wakeTime += time;
}

void Plane::setWaitTime(const int time) {
    waitTime = time;
}
