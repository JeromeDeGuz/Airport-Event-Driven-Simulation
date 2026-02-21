//-----------------------------------------
// NAME		: Jerome De Guzman
// STUDENT NUMBER	: 7917983
// COURSE		: COMP 2150
// INSTRUCTOR	: Heather Matheson
// ASSIGNMENT	: assignment #2
// QUESTION	: question #1?
//
// REMARKS: What is the purpose of this program?
//  The purpose of this program is to run an event based simulation based on an airport
//   the airport will recieve request to takeoff and land from airplanes
//   and must manage each request as events and process them as suchs
//   This file will manage the creation of said simulation
//   as well as running the simulation, printing, and
//   closing the program.
//
//-----------------------------------------

#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[]) {
    string filename = argv[1];
    int numRunways = stoi(argv[2]);

    if (filename.empty() == false && numRunways > 0) {
        Simulation* sim = new Simulation(numRunways);
        sim->openFile(filename);
        sim->readFileLine();
        sim->runSimulation();
        sim->print();
        sim->closeFile();
        delete sim;

    } else {
        cout << "Please Input Valid File Name and Valid Number of Run Ways ( > 0)" << endl;
    }

    return 0;
}