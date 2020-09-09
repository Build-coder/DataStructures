// CMSC 341 - Fall 2020 - Project 0

// mytest.cpp: a unit test to test copy and assignment functions in queue.h.

// Assignment:
//   (1) test the copy constructor
//   (2) test the assignment operator
//   (3) test the destructor using valgrind

// Following is a list of essential tests; we refer to the queue created by the
// copy constructor (or on the left side of the assignment operator) as the "new"
// queue; alternatively, the queue from which the copy is made is the "source"

// - check that a copy is made. the new queue should contain exactly the same data
//   as the source queue

// - check that the copy is deep. modifying either queue (new or source) should not
//   affect the other

// - check edge cases. do they work correctly if the source queue is empty?

// - for the assignment operator, check that you have guarded against self-assignment

#include <iostream>
#include "queue.h"

using namespace std;

    void TestCopyAssignmentAndDestruct(){

        // create queue by calling constructor
        Queue<string> firstQueue;  

        // create second queue by calling constructor
        Queue<string> secondQueue;  
        
        // initialize both queues with data
        for (int i = 1; i <= 5; i++) {

            switch (i) {
            case 1:
                firstQueue.enqueue("Syd");
                secondQueue.enqueue("Ariel");
                break;
            case 2:
                firstQueue.enqueue("Nala");
                secondQueue.enqueue("Sebastian");
                break;
            case 3:
                firstQueue.enqueue("Simba");
                secondQueue.enqueue("Scuttle");
                break;
            case 4:
                firstQueue.enqueue("Scar");
                secondQueue.enqueue("Flounder");
                break;
            case 5:
                firstQueue.enqueue("Mufasa");
                secondQueue.enqueue("King Triton");
                break;
                            
            default:
                break;
            }
        }

        // print contents of both queues
        cout << "Contents of first queue: " << endl;
        firstQueue.dump();
        cout << endl;
        cout << "Contents of second queue: " << endl;
        secondQueue.dump();

        // call copy constructor
        Queue<string>* copiedQueue = new Queue<string>(secondQueue);

        cout << "Contents of copied queue: " << endl;
        copiedQueue->dump();

        // call assignment oper
        Queue<string>* assignQueue = new Queue<string>();
        *assignQueue = firstQueue;
        cout << "Contents of assigned queue: " << endl;
        assignQueue->dump();

        firstQueue.empty();
    }

    int main(){

        TestCopyAssignmentAndDestruct();

    }
