// the interface for patient, node, and pqueue classes
// CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

#ifndef _PQUEUE_H
#define _PQUEUE_H

#include <stdexcept>
#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::out_of_range;


class Grader; // forward declaration (for grading purposes)
class PQueue; // forward declaration

// Triage parameters, min and max values 
const int MINTR = 1;
const int MAXTR = 5;
const int MINTEMP = 30;
const int MAXTEMP = 42;
const int MINOX = 70;
const int MAXOX = 101;
const int MINRR = 5;
const int MAXRR = 40;
const int MINHR = 35;
const int MAXHR = 140;
const int MINBP = 70;
const int MAXBP = 160;

//
// patient class
// 
class Patient {

    private:
        string _patient;
        int _triage; // 1-5, this is assigned by health technician or nurse
        int _temperature; // body temperature, celsius
        int _oxygen; // level of oxygen saturation (SpO2), percentage
        int _RR; // respiratory rate, per minute
        int _HR; // heart rate, per minute
        int _BP; // blood pressure  

    public:
        // default constructor 
        Patient() {
            _patient = ""; _triage = 5; _temperature = 37; _oxygen = 100;
            _RR = 20; _HR = 70; _BP = 100;
        }

        // Alternative constructor 
        Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp){
            if ((triage < MINTR || triage > MAXTR) || (temp < MINTEMP || temp > MAXTEMP)
                || (ox < MINOX || ox > MAXOX) || (rr < MINRR || rr > MAXRR) || (hr < MINHR ||
                hr < MAXHR) || (bp < MINBP || bp > MAXBP)){
                    throw out_of_range("Bad value to Patient constructor.");
                
                _patient = name; _triage = triage; _temperature = temp; _oxygen = ox;
                _RR = rr; _HR = hr; _BP = bp;
            }

            string getPatient() const {return _patient;}
            int getTriage() const {return _triage;}
            int getTemperature() const {return _temperature;}
            int getOxygen() const {return _oxygen;}
            int getRR() const {return _RR;}
            int getHR() const {return _HR;}
            int getBP() const {return _BP;}
        }
};

class Node{

    private:
        Patient _patient; // patient information 
        Node* _right; // right child
        Node* _left; // left child

    public:
        friend class PQueue;
        Node(Patient patient){
            _patient = patient; // patient information 
            _right = nullptr; // right child
            _left = nullptr; // left child
        }
        Patient getPatient() const {return _patient;}
};

// overload insertion operators for Patient and Node
ostream& operator<<(ostream& sout, const Patient& patient);
ostream& operator<<(ostream& sout, const Node& node);

// priority function pointer type
typedef int (*prifn_t) (const Patient&);

class PQueue{

    private:
        Node* _heap; // pointer to root of skew heap 
        int _size; // current size of the heap

        // Function pointer; function to compute priority
        prifn_t priority;

        /**********************************************
         * Private function declarations go here! *
         * *******************************************/


    public:
        friend class Grader; // for grading purposes

        // constructor. create a queue with given priority function.
        PQueue(prifn_t priFn);

        // destructor 
        ~PQueue();

        // copy constructor
        PQueue(const PQueue& rhs);

        // assignment operator
        PQueue& operator=(const PQueue& rhs);

        // add a patient to the queue
        void insertPatient(const Patient& job);

        // extract the highest priority patient
        Patient getNextPatient();

        // merge two queues
        void mergeWithQueue(PQueue& rhs);

        // remove all patients from the queue
        void clear();

        // return number of patients in queue
        int numPatients() const;

        // print the queue using preOrder traversal. 
        // although the first patient printed should 
        // have the highest priority. the remaining 
        // patients will not necessarily be in priority
        // order
        void printPatientQueue() const;

        // get the current priority function
        prifn_t getPriorityFn() const;

        // set a new priority function. must rebuild the heap!!!
        void setPriorityFn(prifn_t priFn);

        // dump the heap. for debugging purposes.
        void dump() const;
};

#endif