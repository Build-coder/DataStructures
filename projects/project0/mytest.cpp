// CMSC 341 - Fall 2020 - Project 0
// Name     - Phil Wood
// driver.cpp: a sample driver for the Queue class.
// This is a test program

#include <iostream>
#include "queue.h"

using namespace std;

// constants
int NUM_OF_NODE_PTRS = 5; // feel free to change value

// function declarations;
void initializeQueue(Queue<int>& sourceQueue);
void clearQueue(Queue<int>& sourceQueue);
void shallowCopy();
bool testValuesEQ(Queue<int>& queue1, Queue<int>& queue2);
bool testAdressesNEQ(Queue<int>& queue1, Queue<int>& queue2);
bool testEmptyQueues(Queue<int>& queue1, Queue<int>& queue2);


/*****************************************/
/************UTILITY FUNCS****************/
/*****************************************/

// initialize values in queue
void initializeQueue(Queue<int>& sourceQueue){
  // cout << "\nPush integers on queue and dump contents:\n";
  for (int i = 1; i <= NUM_OF_NODE_PTRS; i++) {
    sourceQueue.enqueue(i);
  }
}

// erase values in queue
void clearQueue(Queue<int>& sourceQueue){
  // if queue is not empty
  while ( not sourceQueue.empty() ) {

    // remove the head of node
    sourceQueue.dequeue();
  }
}

/*****************************************/
/************BOOL UNIT TESTS**************/
/*****************************************/

// test to make sure queues are copies of one another
bool testValuesEQ(Queue<int>& queue1, Queue<int>& queue2){

  for (int i = 0; i < NUM_OF_NODE_PTRS; i++){

    if (queue1.head() == queue2.head()){
      
      queue1.dequeue();
      queue2.dequeue();

    } else {
        
      return false;
      
    }
  } 

  return true;
}

// test to make sure copy is deep
bool testAdressesNEQ(Queue<int>& queue1, Queue<int>& queue2){

  for (int i = 0; i < NUM_OF_NODE_PTRS; i++){

    if (&queue1.head() != &queue2.head()){
      
      queue1.dequeue();
      queue2.dequeue();

    } else {
        
      return false;
      
    }
  } 

  return true;
}

// test that source and copied list are empty
bool testEmptyCopied(Queue<int>& queue1, Queue<int>& queue2){

  return queue1.empty() && queue2.empty();
}


int main() {

  
  /**********************************************************/
  /***********TEST EXCEPTION HANDLING OF EMPTY QUEUE*********/
  /**********************************************************/
  cout << "\n/**************************************************/\n" <<
  "/*****TEST EXCEPTION HANDLING OF EMPTY QUEUE*******/\n" <<
  "/**************************************************/\n\n";

  // create queue object
  Queue<int> sourceQueue;

  // initialize values in queue
  initializeQueue(sourceQueue);

  // erase contents of queue
  clearQueue(sourceQueue);  

  // make sure queues aren't empty before being copied
  cout << "\nAttempt dequeue() of empty queue:\n";
  try {

    // try to remove the head of the queue
    sourceQueue.dequeue();

    // queue is empty so dequeue will throw an exception
    // and exit

    // pass in exception message 
  } catch (exception &e) {

    // print exception message 
    cout << "Caught exception:\n" << e.what() << endl;
  }

  ///////////////////////////////////////////////////////





  /**************************************************/
  /************TESTING COPY CONSTRUCTOR**************/
  /**************************************************/

  cout << "\n/**************************************************/\n" <<
  "/************TESTING COPY CONSTRUCTOR**************/\n" <<
  "/**************************************************/\n\n";

  initializeQueue(sourceQueue);

  // call copy constructor
  Queue<int> copiedQueue = sourceQueue;

   // check that copy is made
  if(testValuesEQ(sourceQueue, copiedQueue)){
    cout << "Each value of the source queue matches copied queue. " <<
    "\nTherefore, they are copies of one another.\n\n";
  } else {
    cout << "One or more values don't match. \nTherefore, they aren't copies\n\n";
  }
  
  // have to recreate the copy cause testValuesEQ cleared the queues
  initializeQueue(sourceQueue);
  Queue<int> copiedQueue2 = sourceQueue;

  // check that copy is a deep copy. modifying either queue should not affect the other
  if(testAdressesNEQ(sourceQueue, copiedQueue2)){
    cout << "Each node has a unique address when compared to it's respective counterpart." << 
    " \nTherefore copied queue is a deep copy.\n\n";
  } else {
    cout << "At least one node shares an address with it's respective counterpart." <<
    " \nTherefore, copied queue is a shallow copy\n\n";
  }


  // EDGE CASES:
  
  // test that empty queue doesn't break copy construct
  Queue<int> copiedQueue3 = sourceQueue;  

  // check that source and copied queue are empty
  if(testEmptyCopied(sourceQueue, copiedQueue3)){
    cout << "Copied successfully! Source and copied queue are empty\n";
  } else {
    cout << "Copy failed! One of the queues isn't a match of the other\n";
  }


  /**************************************************/
  /*********TESTING OVERLOAD ASSIGN OPER*************/
  /**************************************************/

    cout << "\n/**************************************************/\n" <<
  "/************TESTING OVERLOAD ASSIGN OPER**********/\n" <<
  "/**************************************************/\n\n";

  Queue<int> assignQueue;
  Queue<int> assignQueue2;
  Queue<int> assignQueue3;

  initializeQueue(sourceQueue);
  initializeQueue(assignQueue);
  initializeQueue(assignQueue2);
  initializeQueue(assignQueue3);


  // call overload assign oper
  assignQueue = sourceQueue;

  // check that copy is made
  if(testValuesEQ(sourceQueue, assignQueue)){
    cout << "Each value of the source queue matches copied queue. " <<
    "\nTherefore, they are copies of one another.\n\n";
  } else {
    cout << "One or more values don't match. Therefore, they aren't copies.\n\n";
  }

  initializeQueue(sourceQueue);

  // have to recreate the copy cause testValuesEQ cleared the queue
  assignQueue2 = sourceQueue;

  // check that copy is a deep copy. modifying either queue should not affect the other
  if(testAdressesNEQ(sourceQueue, assignQueue2)){
    cout << "Each node has a unique address when compared to it's respective counterpart." << 
    " \nTherefore copied queue is a deep copy.\n\n";
  } else {
    cout << "At least one node shares an address with it's respective counterpart." <<
    " \nTherefore, copied queue is a shallow copy\n\n";
  }

  // EDGE CASES:
  
  // test that empty queue doesn't break copy construct
  assignQueue3 = sourceQueue;

  // check that source and copied queue are empty
  if(testEmptyCopied(sourceQueue, assignQueue3)){
    cout << "Copied successfully! Source and copied queue are empty\n\n";
    } else {
      cout << "Copy failed! One of the queues isn't a match of the other\n\n";
    }

  return 0;
}