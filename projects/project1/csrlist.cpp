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

    m_head = nullptr;
    m_size = 0;
}

CSRList::CSRList(const CSRList & src){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Copy constructor, creates a new 
     * CSRList object from src.
     * 
     * Note: If we simply use 
     * insertAtHead(...) to make insertion, 
     * the new list will be reversed. That
     * is not what we need. Copy constructor
     * makes an exact copy of rhs, i.e the
     * order of the CSR objects should be 
     * the same as src
     * **********************************/

    // init m_size and m_head 
    m_size = 0;
    m_head = nullptr;
  
    // make copies (don't want to change m_head when it's set)
    CSR* curr = src.m_head; // to iter through src list
    CSR* temp = nullptr; // to iter through "this" list

    // iter through src list
    while (curr != nullptr){

        // create new node && init with curr src node
        CSR* newPtr = new CSR(*curr);
        m_size++;

        // if creating first node...
        if (m_size == 1){

            // save m_head as ref point
            m_head = newPtr;
            // make a copy of m_head
            temp = m_head;

        } else {

            // save prev node's next as addr of new node
            temp->m_next = newPtr;
            // move temp poiner to curr node in "this" list
            temp = newPtr;
        }

        // iter to next node in src list
        curr = curr->m_next;
    }
}

CSRList::~CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Deconstructor
     * ********************************/

    CSR* curr = m_head;

    while(m_head != nullptr){
        // move tracker to next node
        m_head = m_head->m_next;
        // delete prev node
        delete curr;
        // set curr to nullptr
        curr = nullptr;
        // set curr to m_head node
        curr = m_head;
    }
  
    m_head = nullptr;
    m_size = 0;
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
     * Returns true if the list is
     * empty, otherwise returns false
     * ********************************/
    return (m_head == nullptr) && (m_size == 0);
}

void CSRList::insertAtHead(const CSR & matrix){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Inserts the CSR object at the head 
     * of the CSRList object
     * ********************************/

    /* 1. allocate node */
    /* 2. put in the data */
    CSR* newPtr = new CSR(matrix);
  
    /* 3. Make next of new node as head */
    // connect new node to m_head
    newPtr->m_next = m_head;  
  
    /* 4. move the head to point to the new node */
    // make new node m_head
    m_head = newPtr;  
    m_size++;
}

void CSRList::clear(){

    CSR* nodePtr = m_head;

    while ( nodePtr != nullptr ) {
        nodePtr->clear();
        nodePtr = nodePtr->m_next;
    }

    m_head = nullptr;
    m_size = 0;
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

    CSR* curr = m_head;
    int i = 0;

    while (curr != nullptr){

        if (CSRIndex == i){
            return curr->getAt(row, col);
        }

        i++;  
    }
    
    return 911;
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


bool CSRList::operator== (const CSRList & src) const{
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

    CSR* curr = src.m_head;
    CSR* temp = m_head;

    while (curr != nullptr){

        if (*temp == *curr) { 

            curr = curr->m_next; 
            temp = temp->m_next;

        } else { 

            return false; 
        }
    }
    
    return true;
}

const CSRList& CSRList::operator=(const CSRList & src){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Assignment Operator
     * ********************************/

    if(this != &src) {

        /**************
         * Delete Data
         * ***********/

        clear();

        /**************
         * Copy Data
         * ***********/

        // make copies (don't want to change m_head when it's set)
        CSR* curr = src.m_head; // to iter through src list
        CSR* temp = nullptr; // to iter through "this" list

        // iter through src list
        while (curr != nullptr){

            // create new node && init with curr src node
            CSR* newPtr = new CSR(*curr);
            m_size++;

            // if creating first node...
            if (m_size == 1){

                // save m_head as ref point
                m_head = newPtr;
                // make a copy of m_head
                temp = m_head;

            } else {

                // save prev node's next as addr of new node
                temp->m_next = newPtr;
                // move temp poiner to curr node in "this" list
                temp = newPtr;
            }

            // iter to next node in src list
            curr = curr->m_next;
        }
    }
    
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

    CSR* curr = m_head;
    float total = 0.0;

    while (curr != nullptr){

        total = curr->sparseRatio() + total;
    }
    
    // return average
    return (total/float(m_size))*100;
}