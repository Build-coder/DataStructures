// CMSC 341 - Fall 2020 - Project 1
#include "csrlist.h"

CSRList::CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/
}

CSRList::~CSRList(){
    /***********************************
     *      To be implemented
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
    return true;
}

void CSRList::insertAtHead(const CSR & matrix){
    /***********************************
     *      To be implemented
     * ********************************/
}

void CSRList::clear(){
    /***********************************
     *      To be implemented
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
    return false;
}

const CSRList& CSRList::operator=(const CSRList & rhs){
    /***********************************
     *      To be implemented
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
    return 0;
}