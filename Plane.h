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


#ifndef PLANE_H_
#define PLANE_H_


#include <iostream>
using namespace std;

class Plane {
   private:
    string callSign;
    int flightNum;
    string size;
    string requestType;
    int atcId;
    int wakeTime;
    int waitTime;

   public:
    Plane();
    Plane(string, int, string, string, int);
    virtual ~Plane();  // no need to be virtual because there won't be polymorphism
    string print();

    // getters
    string getRequestType();
    int getAtcId();
    int getWakeTime();
    int getWaitTime();

    // setters
    void incrementWakeTime(const int);
    void setWaitTime(const int);
};

#endif