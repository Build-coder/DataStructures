// CMSC 341 - Fall 2020 - Project 0

// mytest.cpp: a unit test to test copy and assignment functions in queue.h.

// Assignment:
//   (1) test the copy constructor
//   (2) test the assignment operator
//   (3) test the destructor using valgrind

#include <iostream>
#include "queue.h"

using namespace std;

    void TestCopyConstructor(){

        // Queue<int> myQ;

        // Queue<int> secondQ(myQ);        
        
        Queue<string> *newQueue = new Queue<string>(*newQueue);


    }

    void TestAssignmentOper(){

        // Queue<int> otherQ;

        // otherQ = secondQ;

        Queue<string> *newQueue = new Queue<string>();


    }

    int main(){

        TestCopyConstructor();
        TestAssignmentOper();
    }
