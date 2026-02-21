
# COMP2150 ASSIGNMENT #2

## Description
This project is to create an event-driven simulation of an airport handling planes as they go through different events.
The Main file handles the creation of the simulation and is considered the main front interface to be interacted with by a tester.

## Running the Program
Run "make" - to compile the program
Run "make run ARGS="test.txt 2"" - place your file and number of runways
    This makes testing different files and number of run ways easier for the marker. (you're welcome)

### If all else fails
Running the Makefile shouldn't fail on running the program. However, if it does so please compile the program manually, as instructed:
    clang++ *.cpp -std=c++11 -o a.out
    ./a.out (test.txt) (numRunWays)
        Replacing test.txt and numRunWays as intended. Thank you
