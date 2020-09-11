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
  
  // check that copy is a deep copy. modifying either queue should not affect the other
  if(testValuesNEQ(intQueue, copiedQueue)){
    cout << "Copied queue is a deep copy, each node has a unique address " << 
    "when compared with it's respective counterpart" << endl;
  } else {
    cout << "Copied queue is a shallow copy, at least one node shares " <<
    "an address with it's respective counterpart" << endl;
  }


  // call assign oper
  // copy a pre-existing obj to another pre-existing obj
  Queue<int> assignQueue;

  initializeQueue(intQueue);
  initializeQueue(assignQueue);

  // want to copy intQueue into assignQueue
  // must erase contents of assignQueue first
  assignQueue = intQueue;

  // check that copy is a deep copy. modifying either queue should not affect the other
  if(testValuesNEQ(intQueue, assignQueue)){
    cout << "Assign queue is a deep copy, each node has a unique " <<
    "address when compared with it's respective counterpart" << endl;
  } else {
    cout << "Assign queue is a shallow copy, at least one node shares " <<
    "an address with it's respective counterpart" << endl;
  }

  // check edge cases. (use exception handling to prevent prog from crashing)
  // make sure copy and assign can handle list with one entry
  // make sure queues aren't empty before being copied
  // make sure queues aren't self assigned
  // 

  // test to see if copy constructor can handle a queue
  // w/ one entry. spoiler: mine can't. fails once it gets
  // in enqueue. not sure how to solve that.
  clearQueue(intQueue);
  intQueue.enqueue(1);

  // call copy constructor
  // create a new obj from a pre-existing object
  // Queue<int> newCopyQueue = intQueue;

  // call assign oper
  // copy a pre-existing obj to another pre-existing obj
  Queue<int> newAssignQueue;

  initializeQueue(newAssignQueue);

  // want to copy intQueue into assignQueue
  // must erase contents of assignQueue first
  newAssignQueue = intQueue;

  return 0;
}