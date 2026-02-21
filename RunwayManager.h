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

#ifndef RUNWAYMANAGER_H
#define RUNWAYMANAGER_H

class RunwayManager {
   private:
    int numRunways;
    bool* runWays;  // array of runways
    // false = free, true = occupied

   public:
    RunwayManager();
    RunwayManager(const int);        // num of runways
    virtual ~RunwayManager();  // destructor

    // getters
    int getFreeRunway();
    int getNumRunways();

    // setters
    void setRunways(const int);           // set the numRunways and array
    void setRunwayOccupied(const int);    // set a runway to occupied
    void setRunwayUnoccupied(const int);  // set a runway to free
    bool checkOccupied(const int);
};

#endif