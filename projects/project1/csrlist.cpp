// CMSC 341 - Fall 2020 - Project 1
#include "csrlist.h"

CSRList::CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Constructor, creates an empty
     * CSRList object
     * ********************************/
}

CSRList::~CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Deconstructor
     * ********************************/
}

bool CSRList::empty() const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/


    /***********************************
     * Returns true if the object is
     * empty, otherwise returns false
     * ********************************/
    return true;
}

void CSRList::insertAtHead(const CSR & matrix){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Inserts the CSR object at the head 
     * of the CSRList object
     * ********************************/
}

void CSRList::clear(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Resets the CSRList object to its
     * initial, empty state
     * ********************************/
}

int CSRList::getAt(int CSRIndex, int row, int col) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns the value of a matrix 
     * member with row and col indices,
     * from the matrix at the position
     * CSRIndex in the CSRList object. 
     * Requires exception handling if
     * an index does not exist in CSR 
     * object, or the CSR object does 
     * not exist in the list
     * ********************************/
    return 0;
}

void CSRList::dump(){
    if (!empty()){
        CSR* temp = m_head;
        while (temp != nullptr){
            temp->dump();
            temp = temp->m_next;
        }
    }
    else
        throw runtime_error("Error: List is empty!");
}

bool CSRList::operator== (const CSRList & rhs) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Equality Operator, returns true if 
     * both lists have the same matrices 
     * and in the same order, otherwise
     * returns false
     * ********************************/
    return false;
}

const CSRList& CSRList::operator=(const CSRList & rhs){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Assignment Operator
     * ********************************/
    return *this;
}

int CSRList::averageSparseRatio(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns the average sparse ratio 
     * for all matrices stored in the 
     * CSRList object. It returns the 
     * ratio as a percentage, e.g. if
     * the ratio is 0.656, the func 
     * returns 0.656 x 100 = 65 as int
     * ********************************/
    return 0;
}