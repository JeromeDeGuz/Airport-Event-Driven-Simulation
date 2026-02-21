
// // #include "PriorityQueue.h"
// // #include "Event.h"
// #include "RequestLanding.h"
// #include "RequestTakeoff.h"
// #include "Simulation.h"

// int main(){

//     // Simulation* sim = new Simulation();
//     // sim->openFile("test.txt");
//     // sim->readFileLine();
//     // sim->runSimulation();

//     // // sim->printPQ();
//     // // sim->printWQ();

//     // sim->print();
//     // sim->closeFile();
//     // delete sim;

//     Queue* q = new Queue();

//     Plane* p1 = new Plane("10", 1243, "heavy", "takeoff", 5);
//     Plane* p2 = new Plane("18", 973, "heavy", "takeoff", 7);
//     Plane* p3 = new Plane("18", 1243, "heavy", "takeoff", 8);
//     Plane* p4 = new Plane("18", 973, "heavy", "landing", 9);
//     Plane* p5 = new Plane("19", 973, "heavy", "landing", 10);


//     Event* e1 = new RequestTakeoff(10, p1);
//     Event* e2 = new RequestTakeoff(18, p2);
//     Event* e3 = new RequestTakeoff(18, p3);
//     Event* e4 = new RequestLanding(18, p4);
//     Event* e5 = new RequestLanding(19, p5);


//     q->enqueue(e1);
//     q->enqueue(e2);
//     q->enqueue(e3);
//     q->enqueue(e4);
//     q->enqueue(e5);
//     q->print();

   











//     return 0;
// }
// /*

// void test1(){
//      // PriorityQueue* pq = new PriorityQueue();
//     Queue* q = new Queue();

//     Plane* p1 = new Plane("Delta", 1243, "heavy", "takeoff", 1);
//     Plane* p2 = new Plane("AirCanada", 973, "heavy", "takeoff", 2);


//     Event* e1 = new RequestTakeoff(1, p1);
//     Event* e2 = new RequestTakeoff(1, p2);


//     // pq->enqueue(e1);


//     // pq->enqueue(e2);
//     // pq->print();

//     // Event* e3 = pq->dequeue();
//     // // pq->dequeue();
//     // pq->print();

//     q->enqueue(e1);
//     q->enqueue(e2);
//     q->print();

//     Event* e3 = q->dequeue();
//     e3->print();

//     Event* e4 = q->dequeue();
//     e4->print();


// }

// */