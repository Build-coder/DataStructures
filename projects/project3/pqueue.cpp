// CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

#include "pqueue.h"

using std::cout;
using std::endl;
using std::domain_error;

PQueue::PQueue(prifn_t priFn) {
/*******************************************************************************
 * This is the constructor for the PQueue class. It must be provided with a
 * pointer to the prioritization function
 * ****************************************************************************/
  
}

PQueue::~PQueue() {
/*******************************************************************************
 * Destructor, all dynamically-allocated data must be deallocated
 * ****************************************************************************/

}

PQueue::PQueue(const PQueue& rhs) {
/*******************************************************************************
 * Copy constructor, must make a deep copy of the rhs object. Must function 
 * correctly if rhs is empty
 * ****************************************************************************/
}


PQueue& PQueue::operator=(const PQueue& rhs) {
/*******************************************************************************
 * Assignment operator, remember to check for self-assignment and to free all 
 * dynamically allocated data members of the host. You should not call the 
 * copy constructor in the implementation of the assignment operator
 * ****************************************************************************/

  // Patient patient;
  // Node* newNode = new Node(patient);
  // PQueue* newQueue = new PQueue();

  return *this;

}

void PQueue::insertPatient(const Patient& input) {
/*******************************************************************************
 * Insert a patient into the queue. Must maintain the min-heap property
 * ****************************************************************************/
  
}

Patient PQueue::getNextPatient() {
/*******************************************************************************
 * Extract and return the highest priority patient from the queue. Must maintain
 * the min-heap property. Should throw a domain_error exception if the queue is 
 * empty when the function is called
 * ****************************************************************************/

  Patient patient;
  
  return patient;
}


void PQueue::mergeWithQueue(PQueue& rhs) {
/*******************************************************************************
 * Merge the host queue with the rhs; leaves rhs empty; Two skew heaps can only
 * be merged if they have the same priority function. If the user attempts to 
 * merge queues with different priority functions, a domain_error exception
 * should be thrown
 * ****************************************************************************/
  
}

void PQueue::clear() {
/*******************************************************************************
 * Clear the queue. Must delete all the nodes in the skew heap, leaving the skew
 * heap empty
 * ****************************************************************************/
  
}

int PQueue::numPatients() const {
/*******************************************************************************
 * Return the current number of patients in the queueu
 * ****************************************************************************/


  return 0;
}

void PQueue::printPatientQueue() const {
/*******************************************************************************
 * Prints the contents of the queue using preorder traversal. Although the first
 * patient printed should have the highest priority, the remaining patients will
 * not necessarily bu in priority order
 * ****************************************************************************/
  
}

prifn_t PQueue::getPriorityFn() const {
/*******************************************************************************
 * Get the current priority function
 * ****************************************************************************/
  
  
}

void PQueue::setPriorityFn(prifn_t priFn) {
/*******************************************************************************
 * Set a new priority function. Must rebuild the heap!
 * ****************************************************************************/
  
}

void PQueue::dump() const {
/*******************************************************************************
 * Use an inorder traversal to dump the heap and indicate the tree structure
 * (as in the previous project). Represent a node in the tree by its integer
 * priority as computed using the priority function and the name of the patient.
 * Please refer to the sample output file (driver.txt) for the format of this 
 * function's output
 * ****************************************************************************/
}

ostream& operator<<(ostream& sout, const Patient& job) {
  sout << "Patient: " << job.getPatient() << ", triage: " << job.getTriage()
       << ", temperature: " << job.getTemperature() << ", oxygen: " << job.getOxygen() << ", RR: "
       << job.getRR() << ", HR: " << job.getHR() << ", BP: " << job.getBP();
  return sout;
}

ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.getPatient();
  return sout;
}


