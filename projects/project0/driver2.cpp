// CMSC 341 - Fall 2020 - Project 0

// driver.cpp: a sample driver for the Queue class.
// This is NOT a test program; it just demonstrates basic usage of
// Queue.

// Assignment:
//   (1) Complete the copy constructor (in queue.h)
//   (2) Complete the assignment operator (in queue.h)
//   (3) Complete the destructor (in queue.h)
//   (4) Write a test program (mytest.cpp) to test copy and assignment
//   (5) Verify destructor by running the test program in Valgrind

#include <iostream>
#include "queue.h"

using namespace std;


//***********UTILITY FUNCS******************/

// initialize values in queue
void initializeQueue(Queue<int>& intQueue){
  // cout << "\nPush integers on queue and dump contents:\n";
  for (int i = 1; i <= 5; i++) {
    intQueue.enqueue(i);
  }
}

// erase values in queue
void clearQueue(Queue<int>& intQueue){
  // if queue is not empty
  while ( not intQueue.empty() ) {

    // remove the head of node
    intQueue.dequeue();
  }
}



/************BOOL UNIT TESTS********************/

bool testValuesNEQ(Queue<int>& queue1, Queue<int>& queue2){

  for (int i = 0; i < 5; i++){

    if (&queue1.head() != &queue2.head()){
      
      queue1.dequeue();
      queue2.dequeue();

    } else {
        
      return false;
      
    }
  } 

  return true;
}


int main() {

  // create queue object
  Queue<int> intQueue;

  // initialize values in queue
  initializeQueue(intQueue);

  // print contents of queue
  intQueue.dump();

  // erase contents of queue
  clearQueue(intQueue);

  cout << "\nAttempt dequeue() of empty queue:\n";
  try {

    // try to remove the head of the queue
    intQueue.dequeue();

    // queue is empty so dequeue will throw an exception
    // and exit

    // pass in exception message  
  } catch (exception &e) {

    // print exception message 
    cout << "Caught exception:\n" << e.what() << endl;
  }

  // //////////////////////////////////////////////////////

  initializeQueue(intQueue);

  // check that a copy is made. new queue should contain same data as source

  // call copy constructor
  // create a new obj from a pre-existing object
  Queue<int> copiedQueue = intQueue;
  
  cout << "\nDisplay contents of copied queue: \n";
  intQueue.dump();
  
  // check that copy is a deep copy
  if(testValuesNEQ(intQueue, copiedQueue)){
    cout << "Copied queue is a deep copy, each node has a unique address" << endl;
  } else {
    cout << "Copied queue is a shallow copy, at least one node shares " <<
    "an address with another" << endl;
  }


  // call assign oper
  // copy a pre-existing obj to another pre-existing obj
  Queue<int> assignQueue;

  initializeQueue(intQueue);
  initializeQueue(assignQueue);

  assignQueue = intQueue;



  return 0;
}