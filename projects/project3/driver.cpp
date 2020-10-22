// a sample driver program
// CMSC 341 - Fall 2020 - Project 3
// driver.cpp: sample driver for the PQueue class

#include "pqueue.h"

// priority functions compute an integer priority for a patient
// internal computations may be floating point, but must return an int

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);

int main(){

    // create a patient queue with capacity five and priority function
    // priorityFn1()

    PQueue queue1(priorityFn1);
    PQueue queue2(priorityFn2);

    // create some test jobs and insert them into the queue
    // Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp)
    Patient testJob1("Sam", 1, 37, 79, 36, 133, 75);
    Patient testJob2("Liz", 5, 37, 98, 26, 70, 100);
    Patient testJob3("Nick", 2, 37, 85, 34, 125, 85);
    Patient testJob4("Eva", 4, 37, 95, 22, 115, 95);

    queue1.insertPatient(testJob3);
    queue1.insertPatient(testJob1);
    queue1.insertPatient(testJob2);
    queue1.insertPatient(testJob4);

    std::cout << "\nqueue1 dump after inserting 4 patients (Nick, Sam, Liz," <<
    "Eva):" << std::endl;

    Patient testJob5("John", 3, 39, 91, 27, 115, 110);
    Patient testJob6("Mia", 3, 33, 93, 28, 118, 98);

    queue2.insertPatient(testJob5);
    queue2.insertPatient(testJob6);

    std::cout << "\nqueue2 dump after inserting 2 patients (John, Mia)" <<
    std::endl;

    queue2.dump();

    queue1.mergeWithQueue(queue2);

    // print the queue, change priority function, print again, change again,
    // pring again. changing the priority function should cause the heap to
    // be rebuilt

    std::cout << std::endl << "Contents of queue1 after merging with queue2:\n";
    queue1.printPatientQueue();
    std::cout << "\nDump queue1 after merging with queue2:\n";
    queue1.dump();

    queue1.setPriorityFn(priorityFn1);

    std::cout << std::endl << "Contents of queue1 after changing the priority" <<
    " function to priorityFn2:\n";
}