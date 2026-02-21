# Airport Event-Driven Simulation

Developed as a high-fidelity system to assist the **Winnipeg Airports Authority (WAA)**, this program simulates real-time aircraft traffic management for the Winnipeg Richardson International Airport (YWG). The simulation evaluates the impact of runway closures and infrastructure expansion on aircraft wait times and operational efficiency.

## Project Overview

The simulation manages complex aircraft transitions, including landings and takeoffs, while adhering to strict aviation safety protocols. It calculates the total "wasted time"—the duration aircraft spend in holding patterns or on the ground waiting for a clear runway—under varying traffic scenarios and runway availability.

### Key Simulation Logic

* 
**Priority-Based Scheduling:** Aircraft in the air are prioritized over those on the ground to conserve fuel and manage emergency holding patterns.


* 
**Wake Turbulence Modeling:** The system enforces safety intervals based on aircraft weight categories to account for wake turbulence dissipation:


* **Small:** 0 mins | **Large:** 1 min | **Heavy:** 2 mins | **Super:** 3 mins.




* 
**Operational Timings:** Standardized approach times (2 minutes) and runway occupancy times (1 minute) are factored into every event.



## 🛠️ Technical Stack & Architecture

* 
**Language:** C++11.


* 
**Methodology:** Object-Oriented Programming (OOP) with a focus on polymorphism, abstract classes, and class hierarchies.


* 
**Memory Management:** Implemented custom destructors to ensure manual dynamic memory management and zero leaks.


* 
**Data Structures:** * **Custom Priority Queue:** A completely from-scratch, generic linked structure used to maintain and process events chronologically.


* 
**Event-Driven Model:** Manages five distinct event subtypes: *Request Landing, Request Takeoff, Landing, Takeoff,* and *Complete*.





## Getting Started

### Prerequisites

* Clang++ compiler with C++11 support.
* Aviary-compatible environment.



### Compilation and Execution

The project includes a `Makefile` for streamlined testing.

**Using Make:**

```bash
# Compile the program
make

# Run with custom arguments (Example: test.txt with 2 runways)
make run ARGS="test.txt 2"

```

**Manual Compilation:**
If `make` is unavailable, compile manually using the following commands:

```bash
clang++ *.cpp -std=c++11 -o a.out
./a.out test.txt 2

```

## 📊 Learning Outcomes & Achievements

This project was built to demonstrate proficiency in core Computer Science principles, including:

* 
**Separate Compilation:** Utilizing header and source files for modular, scalable code.


* 
**Polymorphic Dispatch:** Using dynamic binding to handle multiple related event classes through a single interface.


* 
**Efficient I/O:** Processing large datasets one arrival at a time to minimize memory overhead.
