// CMSC 341 - Fall 2020 - Project 0

// mytest.cpp: a unit test to test copy and assignment functions in queue.h.

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
        cout << endl;


        // check that a copy is made. new queue should contain same data as source

        // call copy constructor
        Queue<string>* copiedQueue = new Queue<string>(firstQueue);

        cout << "Contents of original queue: " << endl;
        firstQueue.dump();
        cout << endl;

        cout << "Contents of copied queue: " << endl;
        copiedQueue->dump();
        cout << endl;

        // call assignment oper
        Queue<string>* assignQueue = new Queue<string>();
        *assignQueue = secondQueue;

        cout << "Contents of original queue: " << endl;
        secondQueue.dump();
        cout << endl;

        cout << "Contents of assigned queue: " << endl;
        assignQueue->dump();
        cout << endl;


        // check copy is deep. modifying either queue should
        // not change the other

        for (int i = 1; i <= 5; i++) {
            copiedQueue->enqueue("Harry Potter");
            assignQueue->enqueue("Bugs Bunny");
        }

        cout << "Contents of copied queue after change" << endl;
        copiedQueue->dump();
        cout << endl;

        cout << "Contents of original queue" << endl;
        firstQueue.dump();
        cout << endl;

        cout << "Contents of assignment oper queue after change" << endl;
        assignQueue->dump();
        cout << endl;

        cout << "Contents of original queue" << endl;
        secondQueue.dump();
        cout << endl;

        // check edge cases. do they work correctly if the source queue is empty?

        Queue<string> thirdQueue;

        cout << "Contents of original queue: " << endl;
        thirdQueue.dump();
        cout << endl;

        // call copy constructor
        Queue<string>* copiedEmptyQueue = new Queue<string>(thirdQueue);

        cout << "Contents of copied empty queue: " << endl;
        copiedEmptyQueue->dump();
        cout << endl;


        // for the assignment operator, check that you have guarded against 
        // self-assignment


        delete copiedQueue;
        delete assignQueue;


        cout << "------------------------------" << endl << endl;
        
    }

    int main() {

            cout << "*****************************************************************" << endl;
        cout << " SSSS  U   U  BBBB   N    N   AAA   U   U  TTTTT  II  CCCC   AAA " << endl;
        cout << " S     U   U  B   B  NN   N  A   A  U   U    T    II  C     A   A" << endl;
        cout << " S     U   U  B   B  N N  N  A   A  U   U    T    II  C     A   A" << endl;
        cout << " SSSS  U   U  BBBB   N  N N  AAAAA  U   U    T    II  C     AAAAA" << endl;
        cout << "    S  U   U  B   B  N  N N  A   A  U   U    T    II  C     A   A" << endl;
        cout << "    S  U   U  B   B  N   NN  A   A  U   U    T    II  C     A   A" << endl;
        cout << " SSSS  UUUUU  BBBB   N    N  A   A  UUUUU    T    II  CCCC  A   A" << endl;
        cout << "*****************************************************************" << endl;

        TestCopyAssignmentAndDestruct();

    }
