// CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

#include "pqueue.h"

using std::cout;
using std::endl;
using std::domain_error;

PQueue::PQueue(prifn_t priFn) {
  
}

PQueue::~PQueue() {
  
}

PQueue::PQueue(const PQueue& rhs) {
  
}


PQueue& PQueue::operator=(const PQueue& rhs) {
  
}

void PQueue::insertPatient(const Patient& input) {
  
}

Patient PQueue::getNextPatient() {
  
}


void PQueue::mergeWithQueue(PQueue& rhs) {
  
}

void PQueue::clear() {
  
}

int PQueue::numPatients() const {
  
}

void PQueue::printPatientQueue() const {
  
}

prifn_t PQueue::getPriorityFn() const {
  
}

void PQueue::setPriorityFn(prifn_t priFn) {
  
}

void PQueue::dump() const
{
  
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


